#include "DrawingPanel.h"
#include "wx/graphics.h"
#include "wx/dcbuffer.h"

wxBEGIN_EVENT_TABLE(DrawingPanel, wxPanel)
EVT_PAINT(DrawingPanel::OnPaint)
wxEND_EVENT_TABLE()

DrawingPanel::DrawingPanel(wxFrame* parent, std::vector<std::vector<bool>>& gameBoard) : wxPanel(parent), Handle(gameBoard)
{
	this->SetBackgroundStyle(wxBG_STYLE_PAINT);
	this->Bind(wxEVT_PAINT, &DrawingPanel::OnPaint, this);
	this->Bind(wxEVT_LEFT_UP, &DrawingPanel::OnMouseUp, this);
}
DrawingPanel::~DrawingPanel()
{

}
void DrawingPanel::OnPaint(wxPaintEvent& event)
{

	wxAutoBufferedPaintDC dc(this);
	dc.Clear();

	wxSize size = GetSize();
	

	wxGraphicsContext* context = wxGraphicsContext::Create(dc);
	if (!context) { return; }
	context->SetBrush(*wxWHITE);
	context->SetPen(*wxBLACK);


	cellWidth = GetSize().GetX() / 15;
	cellHigh = GetSize().GetY() / 15;
	for (int i = 0; i < GridSize; i++)
	{

		for (int j = 0; j < GridSize; j++)
		{

			if (Handle[i][j] == true)
			{
				context->SetBrush(*wxLIGHT_GREY);
			}
			else
			{
				context->SetBrush(*wxWHITE);
			}

			context->DrawRectangle(j * cellWidth, i * cellHigh, cellWidth, cellHigh);

		}

	}

	
}
void DrawingPanel::Video(std::vector<std::vector<bool>>& game)
{
	Handle = game;
}
void DrawingPanel::SetSize(wxSize& size)
{
	wxPanel::SetSize(size);
	Refresh();
}
void DrawingPanel::OnMouseUp(wxMouseEvent& mouse) 
{
	
	int X = mouse.GetX();
	int Y = mouse.GetY();
	this->Bind(wxEVT_LEFT_UP, &DrawingPanel::OnMouseUp, this);
	int cWidth = GetSize().GetWidth() / GridSize;
	int cHight = GetSize().GetHeight() / GridSize;
	int row = X / cWidth;
	int col = Y / cHight;

	if (Handle[col][row] == true)
	{
		Handle[col][row] = false;
	}
	else
	{
		Handle[col][row] = true;
	}
	Refresh();
}

void DrawingPanel::SetGridSize(int gridSize)
{

}