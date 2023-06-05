#pragma once

#include "wx/wx.h"


class MainWindow
{
public:
	MainWindow();
	~MainWindow();

private:

};


MainWindow::MainWindow(const wxString& T) : wxFrame(wxWindow * parent, wxWindowID id, const wxString & T, const wxPoint & pos = wxDefaultPosition, const wxSize & size = wxDefaultSize)
{
    drawingPanel = new DrawingPanel(T);
}

MainWindow::~MainWindow()
{
}


