#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

class Day2
{
public:
	void run();

private:
	void RunScript(string filename);
	bool CheckList(vector<int> list);
	bool CheckOne(int n1, int n2);

	int stopping = 0;

	HelperFunctions helperFunctions;
};

