#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>

class Day18
{
public:
	void run();

private:
	void RunScript(string filename);
	vector<Vec2> PathFind(unordered_map<int, vector<Vec2>> grid, Vec2 start, Vec2 end);
	vector<Vec2> ReconstructPath(unordered_map<int, Vec2> cameFrom, Vec2 current);
	int h(Vec2 currrent, Vec2 end);
	int getPos(Vec2 current);
	void PrintGrid(vector<vector<bool>> grid);

	HelperFunctions helperFunctions;

	int gridSize = 0;
	int numFall = 0;
};