#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

class Day11
{
public:
	void run();

private:
	void RunScript(string filename);
	vector<uint64_t> Update(uint64_t num);

	HelperFunctions helperFunctions;
};