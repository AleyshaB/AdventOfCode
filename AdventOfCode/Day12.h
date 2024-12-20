#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

class Day12
{
public:
	void run();

private:
	void RunScript(string filename);
	void GetAreaAndPerimiter(vector<vector<pair<char, bool>>>& grid, int y, int x);

	HelperFunctions helperFunctions;
	uint64_t total = 0;
};