#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

class Day13
{
public:
	void run();

private:
	void RunScript(string filename);

	HelperFunctions helperFunctions;
};