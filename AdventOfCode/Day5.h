#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

class Day5
{
public:
	void run();

private:
	void RunScript(string filename);
	bool SortPages(vector<int>& pages);

	HelperFunctions helperFunctions;
	map<int, std::vector<int>> rules;
};