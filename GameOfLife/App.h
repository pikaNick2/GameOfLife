#pragma once
#include "MainWindow.h"
#include "wx/wx.h"

class App : public wxApp
{
private:
	MainWindow* window = nullptr;
public:
	App();
	~App();
	virtual bool OnInit();
};

