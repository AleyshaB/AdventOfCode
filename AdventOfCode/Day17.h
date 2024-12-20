#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <set>

class Day17
{
public:
	void run();

private:
	void RunScript(string filename);
	vector<long long> run(long long currentValue, int depth);
	vector<int> runProgram(long long a);

	HelperFunctions helperFunctions;
	vector<int> instructions;
};