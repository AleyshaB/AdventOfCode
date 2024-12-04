#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class HelperFunctions
{
public:
	int getIntFromString(string& s, bool eraseEnd = true);
	uint64_t getUIntFromString(string& s, bool eraseEnd = true);
	vector<int> Sort(std::vector<int> list);
};

