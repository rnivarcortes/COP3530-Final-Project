#pragma once
#include <iostream>
#include <map>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>
#include <chrono>
#include <queue>
#include <stack>

using namespace std;
using namespace std::chrono;

struct node {

	vector<node*> edgeList;

	string name;
	string cuisine;
	string state;
	string county;
	string lon;
	string lat;

	bool visited;


public:

	node() {
		name = "";
		cuisine = "";
		state = "";
		county = "";
		lon = "";
		lat = "";

		visited = false;
	}

	node(string _name, string _cuisine, string _state, string _county, string _lon, string _lat) {
		name = _name;
		cuisine = _cuisine;
		state = _state;
		county = _county;
		lon = _lon;
		lat = _lat;

		visited = false;
	}
};


void ImportData(map<string, node*>& adjList, map<string, int>& classifications) {

	ifstream file("chain.csv");

	int count = 0;
	int index_count = 0;

	if (file.is_open()) { 
		cout << "---CREATING GRAPH---" << endl;
		string fileLine;

		while (getline(file, fileLine)) {

			istringstream stream(fileLine);

			string name;
			string cuisine;
			string state;
			string county;
			string lon;
			string lat;

			getline(stream, name, ',');
			getline(stream, cuisine, ',');
			getline(stream, state, ',');
			getline(stream, county, ',');
			getline(stream, lon, ',');
			getline(stream, lat, ',');

			node* curr_node = new node(name, cuisine, state, county, lon, lat);
			string curr_key = lat + lon;
			adjList[curr_key] = curr_node;

			//name test case 
			if (classifications.find(name) == classifications.end()) {

				node* n = new node(name, "", "", "", "", "");

				classifications[name] = index_count;
				adjList[to_string(index_count)] = n;

				adjList[curr_key]->edgeList.push_back(n);
				adjList[to_string(index_count)]->edgeList.push_back(curr_node);
				index_count++;
			}
			else {
				auto it = classifications.find(name);
				string adj_list_key = to_string(it->second);
				auto itr = adjList.find(adj_list_key);
				adjList[curr_key]->edgeList.push_back(itr->second);
				adjList[adj_list_key]->edgeList.push_back(curr_node);
			}

			//cuisine test case
			if (classifications.find(cuisine) == classifications.end()) {

				node* n = new node("", cuisine, "", "", "", "");

				classifications[cuisine] = index_count;
				adjList[to_string(index_count)] = n;

				adjList[curr_key]->edgeList.push_back(n);
				adjList[to_string(index_count)]->edgeList.push_back(curr_node);
				index_count++;
			}
			else {
				auto it = classifications.find(cuisine);
				string adj_list_key = to_string(it->second);
				auto itr = adjList.find(adj_list_key);
				adjList[curr_key]->edgeList.push_back(itr->second);
				adjList[adj_list_key]->edgeList.push_back(curr_node);
			}

			//state test case
			if (classifications.find(state) == classifications.end()) {

				node* n = new node("", "", state, "", "", "");

				classifications[state] = index_count;
				adjList[to_string(index_count)] = n;

				adjList[curr_key]->edgeList.push_back(n);
				adjList[to_string(index_count)]->edgeList.push_back(curr_node);
				index_count++;
			}
			else {
				auto it = classifications.find(state);
				string adj_list_key = to_string(it->second);
				auto itr = adjList.find(adj_list_key);
				adjList[curr_key]->edgeList.push_back(itr->second);
				adjList[adj_list_key]->edgeList.push_back(curr_node);
			}

			//county test case
			if (classifications.find(county) == classifications.end()) {

				node* n = new node("", "", "", county, "", "");

				classifications[county] = index_count;
				adjList[to_string(index_count)] = n;

				adjList[curr_key]->edgeList.push_back(n);
				adjList[to_string(index_count)]->edgeList.push_back(curr_node);
				index_count++;
			}
			else {
				auto it = classifications.find(county);
				string adj_list_key = to_string(it->second);
				auto itr = adjList.find(adj_list_key);
				adjList[curr_key]->edgeList.push_back(itr->second);
				adjList[adj_list_key]->edgeList.push_back(curr_node);
			}
			if (count == 50000) {
				break;
			}
			count++;
		}
	}
	cout << "---GRAPH COMPLETE---" << endl;
}
void print(node* node) {
	cout << "Name: " << node->name << endl;
	cout << "Cuisine: " << node->cuisine << endl;
	cout << "State: " << node->state << endl;
	cout << "County: " << node->county << endl;
	cout << "lon: " << node->lon << endl;
	cout << "lat: " << node->lat << endl;
	cout << endl << endl;
}
void bfs(string search_parameter, int parameternum, node* curr_node, map<node*, string>& valid_nodes, queue<node*>& queue) {

	for (unsigned int i = 0; i < curr_node->edgeList.size(); i++) {
		node* index_node = curr_node->edgeList[i];

		switch (parameternum) {
		case 1:
			//checks name
			if (index_node->name == search_parameter && valid_nodes.find(index_node) == valid_nodes.end() && index_node->cuisine != "") {
				queue.push(index_node);
				valid_nodes[index_node] = "in";
			}
			break;
		case 2:
			//checks cuisine
			if (curr_node->cuisine == search_parameter && valid_nodes.find(index_node) == valid_nodes.end() && index_node->name != "") {
				queue.push(index_node);
				valid_nodes[index_node] = "in";
			}
			break;
		case 3:
			//checks state
			if (curr_node->state == search_parameter && valid_nodes.find(index_node) == valid_nodes.end() && index_node->name != "") {
				queue.push(index_node);
				valid_nodes[index_node] = "in";
			}
			break;
		case 4:
			//checks county
			if (curr_node->county == search_parameter && valid_nodes.find(index_node) == valid_nodes.end() && index_node->name != "") {
				queue.push(index_node);
				valid_nodes[index_node] = "in";
			}
			break;
		}
	}

	if (queue.empty()) {
		return;
	}
	else {
		node* new_node = queue.front();
		queue.pop();
		bfs(search_parameter, parameternum, new_node, valid_nodes, queue);
	}
}
void dfs(string search_parameter, int parameternum, node* curr_node, map<node*, string>& valid_nodes) {
	switch (parameternum) {
	case 1:
		//checks name
		curr_node->visited = true;
		if (curr_node->name == search_parameter) {
			if (curr_node->cuisine != "") {
				valid_nodes[curr_node] = "in";
			}
		}

		for (unsigned int i = 0; i < curr_node->edgeList.size(); i++) {
			if (curr_node->edgeList[i]->visited == false) {
				dfs(search_parameter, parameternum, curr_node->edgeList[i], valid_nodes);
			}
		}
		break;
	case 2:
		//checks cuisine
		curr_node->visited = true;
		if (curr_node->cuisine == search_parameter) {
			if (curr_node->name != "") {
				valid_nodes[curr_node] = "in";
			}
		}

		for (unsigned int i = 0; i < curr_node->edgeList.size(); i++) {
			if (curr_node->edgeList[i]->visited == false) {
				dfs(search_parameter, parameternum, curr_node->edgeList[i], valid_nodes);
			}
		}
		break;
	case 3:
		//checks state
		curr_node->visited = true;
		if (curr_node->state == search_parameter) {
			if (curr_node->name != "") {
				valid_nodes[curr_node] = "in";
			}
		}

		for (unsigned int i = 0; i < curr_node->edgeList.size(); i++) {
			if (curr_node->edgeList[i]->visited == false) {
				dfs(search_parameter, parameternum, curr_node->edgeList[i], valid_nodes);
			}
		}
		break;
	case 4:
		//checks county
		curr_node->visited = true;
		if (curr_node->county == search_parameter) {
			if (curr_node->name != "") {
				valid_nodes[curr_node] = "in";
			}
		}

		for (unsigned int i = 0; i < curr_node->edgeList.size(); i++) {
			if (curr_node->edgeList[i]->visited == false) {
				dfs(search_parameter, parameternum, curr_node->edgeList[i], valid_nodes);
			}
		}
		break;
	}
}

node* search(map<string, node*>& adjList, map<string, int>& classifications, string search_parameter) {
	
	//finds first occuring node where an attribute is equal to the one searched
	node* found_node = nullptr;
	for (auto itr = adjList.begin(); itr != adjList.end(); itr++) {
		if (itr->second->name == search_parameter || itr->second->cuisine == search_parameter || itr->second->state == search_parameter || itr->second->county == search_parameter) {
			found_node = itr->second;
			if (found_node->name == "" && found_node->cuisine == "" && found_node->state == "") {
				return found_node;
			}
			else if (found_node->county == "" && found_node->cuisine == "" && found_node->state == "") {
				return found_node;
			}
			else if (found_node->name == "" && found_node->county == "" && found_node->state == "") {
				return found_node;
			}
			else if (found_node->name == "" && found_node->cuisine == "" && found_node->county == "") {
				return found_node;
			}
		}
	}

	return found_node;
}
