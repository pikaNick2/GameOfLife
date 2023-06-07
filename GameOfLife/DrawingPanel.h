#pragma once
#include "wx/wx.h"


class DrawingPanel : public wxPanel
{
public:
	DrawingPanel(wxFrame* parent, std::vector<std::vector<bool>>& gameBoard);
	~DrawingPanel();
	void SetSize(wxSize& size);
	void OnMouseUp(wxMouseEvent& mouse); ;
	std::vector<std::vector<bool>>& Handle;
	void Video(std::vector<std::vector<bool>>& game);
	void SetGridSize(int gridSize);
	wxDECLARE_EVENT_TABLE();
private:
	
	int rows = 10;
	int cols;
	int* grid;
	int cellHigh;
	int cellWidth;
	int GridSize = 15;
	void OnPaint(wxPaintEvent& event);
	

};


