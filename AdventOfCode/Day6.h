#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Day6
{
public:
	void run();

private:
	void RunScript(string filename);
	bool Move(int direction);
	int MovePart2(int direction);

	HelperFunctions helperFunctions;

	vector<vector<pair<bool, bool>>> grid;
	vector<vector<pair<bool, bool>>> copyGrid;
	vector<vector<int>> dir;

	vector<pair<int, int>> turningPoints;

	int x = 0;
	int y = 0;
	int total2 = 0;
};