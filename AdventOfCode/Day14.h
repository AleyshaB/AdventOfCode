#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <set>

class Day14
{
public:
	void run();

private:
	void RunScript(string filename);
	void PrintGrid(set<pair<int, int>> robots);

	HelperFunctions helperFunctions;

	int height = 0;
	int width = 0;
};