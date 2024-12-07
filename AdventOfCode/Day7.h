#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

class Day7
{
public:
	void run();

private:
	void RunScript(string filename);
	long long Calculate(vector<int> nums, vector<int> operators);

	HelperFunctions helperFunctions;
};