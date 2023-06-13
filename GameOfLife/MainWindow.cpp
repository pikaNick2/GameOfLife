#include "MainWindow.h"
#include "DrawingPanel.h"
#include "wx/wx.h"
#include "play.xpm"
#include "pause.xpm"
#include "next.xpm"
#include "trash.xpm"
#define TIMER 20003

wxBEGIN_EVENT_TABLE(MainWindow, wxFrame)
EVT_SIZE(MainWindow::OnSize)
EVT_MENU(25000, MainWindow::Play)
EVT_MENU(30000, MainWindow::Pause)
EVT_MENU(20001, MainWindow::Next)
EVT_MENU(20002, MainWindow::Trash)
EVT_TIMER(TIMER, MainWindow::Watch)
wxEND_EVENT_TABLE()
MainWindow::MainWindow() :wxFrame(nullptr, wxID_ANY, "the Game of Life", wxPoint(0, 0), wxSize(800, 600))
{
	Status = CreateStatusBar();
	SetStatusText(Status);
	Tool = CreateToolBar();
	draw = new DrawingPanel(this, Handle);
	wxBoxSizer* boxsize = new wxBoxSizer(wxVERTICAL);
	boxsize->Add(draw, 1, wxEXPAND | wxALL);
	this->SetSizer(boxsize);
	this->Bind(wxEVT_SIZE, &MainWindow::OnSize, this);
	InitializeGrid();
	
	wxBitmap playIcon(play_xpm);
	wxBitmap pauseIcon(pause_xpm);
	wxBitmap nextIcon(next_xpm);
	wxBitmap trashIcon(trash_xpm);
	Tool->AddTool(25000, "Play", playIcon); 
	Tool->AddTool(30000, "Pause", pauseIcon);
	Tool->AddTool(20001, "Next", nextIcon);
	Tool->AddTool(20002, "Trash", trashIcon);
	Tool->Realize();
	watch = new wxTimer(this, TIMER);
}

MainWindow::~MainWindow()
{

}
void MainWindow::OnSize(wxSizeEvent& fu)
{
	wxSize big = GetSize();
	wxSize(SetSize());
	if (draw != nullptr)
	{
		draw->SetSize(big);
		Refresh();
		fu.Skip();
	}
}
void MainWindow::InitializeGrid()
{
	
	board.resize(GridSize);
	for (int i = 0; i < GridSize; i++)
	{
		board[i].resize(GridSize);
	}
	draw->Video(board); 

}
void MainWindow::SetStatusText(wxStatusBar* Status)
{
	this->Layout();
	Status->SetStatusText(" Cell Count " + std::to_string(livin) + " Generation " + std::to_string(Gen));
}

void MainWindow::Play(wxCommandEvent& push)
{
	SetStatusText(Status);

}
void MainWindow::Pause(wxCommandEvent& plus)
{


}
void MainWindow::Next(wxCommandEvent& minus)
{
	Generation();

}
void MainWindow::Trash(wxCommandEvent& bin)
{
	for (int i = 0; i < 15; i++)
	{

		for (int j = 0; j < 15; j++)
		{
			Handle[i][j] = false;

		}

	}

	SetStatusText(Status);
	Refresh();
}

int MainWindow::LivingCell(int m, int n)
{
	
	int neighbors = 0;
	for (int i = -1; i < 2; i++)
	{

		for (int j = -1; j < 2; j++)
		{
			if (m - i < 0 || m - i >14 || n - j < 0 || n - j >14)
			{
				continue;
			}
			else if (i == 0 && j == 0)
			{

			}
			else if (Handle[m - i][n - j] == true)
			{
				neighbors++;
			}

		}

	}
	return neighbors;
}

void MainWindow::Generation()
{
	sandbox.resize(15);
	for (int i = 0; i < 15; i++)
	{
		sandbox[i].resize(15);
	}
	for (int i = 0; i < 15; i++)
	{

		for (int j = 0; j < 15; j++)
		{
			if (LivingCell(i, j) < 2)
			{
				sandbox[i][j] = false;
			}
			else if (LivingCell(i, j) >= 4)
			{
				sandbox[i][j] = false;
			}
			else if (LivingCell(i, j) == 2 || LivingCell(i, j) == 3)
			{
				sandbox[i][j] = Handle[i][j];
			}
			if (LivingCell(i, j) == 3 && sandbox[i][j] == false)
			{
				sandbox[i][j] = true;
				livin + 1;
			}


		}

	}
	sandbox.swap(Handle);
	Gen + 1;
	SetStatusText(Status);
	Refresh();
}
void MainWindow::Watch(wxTimer* watch)
{

}