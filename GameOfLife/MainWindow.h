#pragma once

#include "wx/wx.h"
#include "DrawingPanel.h"
#include <vector>

class MainWindow : public wxFrame
{
private:
	int store;
	int livin;
	int Gen;
	wxStatusBar* Status;
	wxToolBar* Tool;
	wxTimer* watch = nullptr;
public:
	~MainWindow();
	MainWindow();
	void SetStatusText(wxStatusBar* Status);
	DrawingPanel* draw = nullptr;
	wxBoxSizer* boxsize = nullptr;
	void OnSize(wxSizeEvent& fu);
	std::vector<std::vector<bool>> board;
	std::vector<std::vector<bool>> sandbox;
	void Generation();
	void InitializeGrid();
	int GridSize = 15;
	void SetSize(int GridSize);
	std::vector<std::vector<bool>> Handle;
	void Play(wxCommandEvent& push);
	void Pause(wxCommandEvent& plus);
	void Next(wxCommandEvent& minus);
	void Trash(wxCommandEvent& bin);
	void Watch(wxTimerEvent& watch);
	int LivingCell(int m, int n);
	wxDECLARE_EVENT_TABLE();
};

