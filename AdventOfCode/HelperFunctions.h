#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Vec2 {
public:
	Vec2(int x = 0, int y = 0);
	Vec2 operator+(const Vec2 rhs);
	Vec2 operator-(const Vec2 rhs);
	bool operator<(const Vec2& rhs);
	bool operator>(const Vec2& rhs);
	Vec2 operator*(const Vec2 rhs);
	Vec2 operator*(const int rhs);
	Vec2 operator+=(const Vec2 rhs);
	bool operator==(const Vec2 rhs);

	int x;
	int y;
};

class HelperFunctions
{
public:
	int getIntFromString(string& s, bool eraseEnd = true);
	uint64_t getUIntFromString(string& s, bool eraseEnd = true);
	vector<int> Sort(std::vector<int> list);

public:
	vector<Vec2> cardinalDirs = { Vec2(0, -1), Vec2(1, 0), Vec2(0, 1), Vec2(-1, 0) };
};

