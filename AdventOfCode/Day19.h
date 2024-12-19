#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>

class Day19
{
public:
	void run();

private:
	void RunScript(string filename);
	long long HasPattern(string towel, vector<string>& towelTypes);
	long long CheckHasPattern(string towel, vector<string>& towelTypes);

	HelperFunctions helperFunctions;
	std::unordered_map<std::string, long long> checked;
	string concated;
};