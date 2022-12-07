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
