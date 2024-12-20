#pragma once
#include "HelperFunctions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <set>

class Day16
{
public:
	void run();

private:
	void RunScript(string filename);
	int PathFind(unordered_map<int, vector<Vec2>> grid, Vec2 start, Vec2 end);
	int ReconstructPath(unordered_map<int, Vec2> cameFrom, Vec2 current, int copyPlaces, Vec2 name = Vec2(0, 0));
	void Merge(int path);
	int h(Vec2 currrent, Vec2 end);
	int getPos(Vec2 current);

	HelperFunctions helperFunctions;
	set<int> uniquePlaces;
	map<int, set<int>> possiblePaths;

	int gridSizeX;
};