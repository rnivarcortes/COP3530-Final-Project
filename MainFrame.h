#pragma once
#include <wx/wx.h>
#include <wx/listctrl.h>

class MainFrame : public wxFrame
{
public:
	MainFrame(const wxString& title);
	wxPanel* panel = new wxPanel(this);
	int counter = 0;
private:

	void OnNameClicked(wxCommandEvent& evt);
	void OnCuisineClicked(wxCommandEvent& evt);
	void OnStateClicked(wxCommandEvent& evt);
	void OnCountyClicked(wxCommandEvent& evt);

	wxString search_parameter;
	int parameternum = 0;
	wxString search_type;
	wxListView* list;

	void OnEnter(wxCommandEvent& evt);
	void CreateDfs(wxCommandEvent& evt);
	void CreateBfs(wxCommandEvent& evt);
	void PopulateList(wxString search_type);
};