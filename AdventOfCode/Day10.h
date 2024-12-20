#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

class Day10
{
public:
	void run();

private:
	void RunScript(string filename);
	int PathFind(pair<int,int> start);

	HelperFunctions helperFunctions;

	vector<vector<int>> grid;
};