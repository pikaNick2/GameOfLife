#include "App.h"
#include <wx/wx.h>
#include "MainWindow.h"

wxIMPLEMENT_APP(App);

App::App() {

}

App::~App() {

}

bool App::OnInit() {

	window = new MainWindow();
	window->Show();
	return true;
}