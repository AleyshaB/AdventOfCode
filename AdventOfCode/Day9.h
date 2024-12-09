#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

class Day9
{
public:
	void run();

private:
	void RunScript(string filename);
	void SwapElements(vector<pair<int, bool>>& list, int first, int second);
	void PrintList(vector<pair<int, bool>> list);
	bool CheckSpace(vector<pair<int, bool>> list);

	HelperFunctions helperFunctions;
};