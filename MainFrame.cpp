#include "MainFrame.h"
#include "Graph.h"

MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title) {
	panel->SetBackgroundColour(wxColor(153, 204, 255));

	wxStaticText* intro = new wxStaticText(panel, wxID_ANY, "-----This program allows the user to search for all restaurants by a specific category-----", 
		wxPoint(0, 0), wxSize(800, -1), wxALIGN_CENTER);
	wxFont font = intro->GetFont();
	font.SetPointSize(12);
	intro->SetFont(font);

	wxStaticText* firstQuestion = new wxStaticText(panel, wxID_ANY, "What would you like to search by:",
		wxPoint(0, 25), wxSize(800, -1), wxALIGN_LEFT);
	font = firstQuestion->GetFont();
	font.SetPointSize(12);
	firstQuestion->SetFont(font);


	wxButton* Name = new wxButton(panel, wxID_ANY, "Name", wxPoint(0, 50), wxSize(100, -1));
	Name->Bind(wxEVT_BUTTON, &MainFrame::OnNameClicked, this);

	wxButton* Cuisine = new wxButton(panel, wxID_ANY, "Cuisine", wxPoint(100, 50), wxSize(100, -1));
	Cuisine->Bind(wxEVT_BUTTON, &MainFrame::OnCuisineClicked, this);

	wxButton* State = new wxButton(panel, wxID_ANY, "State", wxPoint(200, 50), wxSize(100, -1));
	State->Bind(wxEVT_BUTTON, &MainFrame::OnStateClicked, this);

	wxButton* County = new wxButton(panel, wxID_ANY, "County", wxPoint(300, 50), wxSize(100, -1));
	County->Bind(wxEVT_BUTTON, &MainFrame::OnCountyClicked, this);

}

void MainFrame::OnNameClicked(wxCommandEvent& evt) {
	parameternum = 1;
	wxStaticText* Question = new wxStaticText(panel, wxID_ANY, "What restaurant would you like to search for: ",
		wxPoint(0, 75), wxSize(315, -1), wxALIGN_LEFT);
	wxFont font = Question->GetFont();
	font.SetPointSize(12);
	Question->SetFont(font);

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(315, 75), wxSize(100, -1));
	textCtrl->SetValidator(wxTextValidator(wxFILTER_NONE, &search_parameter));

	wxButton* save = new wxButton(panel, wxID_ANY, "ENTER", wxPoint(420, 75), wxSize(50, -1));
	save->Bind(wxEVT_BUTTON, &MainFrame::OnEnter, this);

	search_parameter = "";
	TransferDataToWindow();
}

void MainFrame::OnCuisineClicked(wxCommandEvent& evt) {
	parameternum = 2;
	wxStaticText* Question = new wxStaticText(panel, wxID_ANY, "What Cuisine would you like to search for: ", 
		wxPoint(0, 75), wxSize(315, -1), wxALIGN_LEFT);
	wxFont font = Question->GetFont();
	font.SetPointSize(12);
	Question->SetFont(font);

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(315, 75), wxSize(100, -1));
	textCtrl->SetValidator(wxTextValidator(wxFILTER_NONE, &search_parameter));

	wxButton* save = new wxButton(panel, wxID_ANY, "ENTER", wxPoint(420, 75), wxSize(50, -1));
	save->Bind(wxEVT_BUTTON, &MainFrame::OnEnter, this);

	search_parameter = "";
	TransferDataToWindow();
}

void MainFrame::OnStateClicked(wxCommandEvent& evt) {
	parameternum = 3;
	wxStaticText* Question = new wxStaticText(panel, wxID_ANY, "In what state would you like to search: ",
		wxPoint(0, 75), wxSize(315, -1), wxALIGN_LEFT);
	wxFont font = Question->GetFont();
	font.SetPointSize(12);
	Question->SetFont(font);

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(315, 75), wxSize(100, -1));
	textCtrl->SetValidator(wxTextValidator(wxFILTER_NONE, &search_parameter));

	wxButton* save = new wxButton(panel, wxID_ANY, "ENTER", wxPoint(420, 75), wxSize(50, -1));
	save->Bind(wxEVT_BUTTON, &MainFrame::OnEnter, this);

	search_parameter = "";
	TransferDataToWindow();
}

void MainFrame::OnCountyClicked(wxCommandEvent& evt) {
	parameternum = 4;
	wxStaticText* Question = new wxStaticText(panel, wxID_ANY, "In what county would you like to search: ",
		wxPoint(0, 75), wxSize(315, -1), wxALIGN_LEFT);
	wxFont font = Question->GetFont();
	font.SetPointSize(12);
	Question->SetFont(font);

	wxTextCtrl* textCtrl = new wxTextCtrl(panel, wxID_ANY, "", wxPoint(315, 75), wxSize(100, -1));
	textCtrl->SetValidator(wxTextValidator(wxFILTER_NONE, &search_parameter));

	wxButton* save = new wxButton(panel, wxID_ANY, "ENTER", wxPoint(420, 75), wxSize(50, -1));
	save->Bind(wxEVT_BUTTON, &MainFrame::OnEnter, this);

	search_parameter = "";
	TransferDataToWindow();
}

void MainFrame::OnEnter(wxCommandEvent& evt) {
	TransferDataFromWindow();

	wxStaticText* DATA = new wxStaticText(panel, wxID_ANY, "Which search would you like to use: ", wxPoint(0, 100), wxSize(150, -1), wxALIGN_CENTER);
	wxFont font = DATA->GetFont();
	font.SetPointSize(12);
	DATA->SetFont(font);

	auto dfs = new wxButton(panel, wxID_ANY, "DFS", wxPoint(0, 125), wxSize(100, -1));
	dfs->Bind(wxEVT_BUTTON, &MainFrame::CreateDfs, this);

	auto bfs = new wxButton(panel, wxID_ANY, "BFS", wxPoint(100, 125), wxSize(100, -1));
	bfs->Bind(wxEVT_BUTTON, &MainFrame::CreateDfs, this);
}

void MainFrame::CreateDfs(wxCommandEvent& evt) {
	search_type = "dfs";

	list = new wxListView(panel, wxID_ANY, wxPoint(0, 200), wxSize(800, 400));
	list->SetBackgroundColour(wxColor(153, 204, 255));
	list->AppendColumn("Restaurant");
	list->AppendColumn("Cusine");
	list->AppendColumn("State");
	list->AppendColumn("County");
	list->AppendColumn("Lat-Lon");

	list->SetColumnWidth(0, 160);
	list->SetColumnWidth(1, 160);
	list->SetColumnWidth(2, 160);
	list->SetColumnWidth(3, 160);
	list->SetColumnWidth(4, 160);

	PopulateList(search_type);
}

void MainFrame::CreateBfs(wxCommandEvent& evt) {
	search_type = "bfs";

	list = new wxListView(panel, wxID_ANY, wxPoint(0, 200), wxSize(800, 400));
	list->SetBackgroundColour(wxColor(153, 204, 255));
	list->AppendColumn("Restaurant");
	list->AppendColumn("Cusine");
	list->AppendColumn("State");
	list->AppendColumn("County");
	list->AppendColumn("Lat-Lon");

	list->SetColumnWidth(0, 160);
	list->SetColumnWidth(1, 160);
	list->SetColumnWidth(2, 160);
	list->SetColumnWidth(3, 160);
	list->SetColumnWidth(4, 160);

	PopulateList(search_type);
}

void MainFrame::PopulateList(wxString search_type) {

	string temp = string(search_type.mb_str(wxConvUTF8));
	
	map<string, node*> adjList;
	map<string, int> classifications;
	map<node*, string> valid_nodes;

	ImportData(adjList, classifications);

	string str = string(search_parameter.mb_str(wxConvUTF8));
	node* found_node = search(adjList, classifications, str);

	if (temp == "bfs") {
		queue<node*> queue;

		auto start = high_resolution_clock::now();
		bfs(str, parameternum, found_node, valid_nodes, queue);
		auto stop = high_resolution_clock::now();

		auto duration = duration_cast<microseconds>(stop - start);
	}
	else {
		stack<node*> list;

		auto start = high_resolution_clock::now();
		dfs(str, parameternum, found_node, valid_nodes);
		auto stop = high_resolution_clock::now();

		auto duration = duration_cast<microseconds>(stop - start);
	}

	int index = 0;
	for (auto it = valid_nodes.begin(); it != valid_nodes.end(); ++it) {
		list->InsertItem(index, it->first->name);
		list->SetItem(index, 1, it->first->cuisine);
		list->SetItem(index, 2, it->first->state);
		list->SetItem(index, 3, it->first->county);
		string temp = it->first->lat + ", " + it->first->lon;
		list->SetItem(index, 4, temp);
		index++;
	}

}