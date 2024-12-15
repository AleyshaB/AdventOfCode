#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>
#include <set>

class Day15
{
public:
	enum GridType {
		WALL,
		BLANK,
		BOX1,
		BOX2
	};

	vector<Vec2> cardinalDirs = { Vec2(0, -1), Vec2(1, 0), Vec2(0, 1), Vec2(-1, 0) };
public:
	void run();

private:
	void RunScript(string filename);
	void PrintGrid(vector<vector<GridType>> grid, Vec2 robot);
	vector<vector<GridType>> SimulateMovement(vector<vector<GridType>> grid, Vec2 pos, Vec2 dir, Vec2& robot);

	HelperFunctions helperFunctions;
};