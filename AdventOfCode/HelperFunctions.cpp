#include "HelperFunctions.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int HelperFunctions::getIntFromString(string& s, bool eraseEnd)
{
	while (s.size() > 0 && s[0] == ' ') {
		s.erase(0, 1);
	}

	bool even = true;
	if (s[0] == '-' || s[0] == '+') {
		if (s[0] == '-') {
			even = false;
		}
		s.erase(0, 1);
	}

	int num = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num *= 10;
			num += s[i] - '0';
			s.erase(0, 1);
			i--;
		}
		else {
			break;
		}
	}

	if (!even) {
		num *= -1;
	}

	if (eraseEnd) {
		while (s.size() > 0 && s[0] == ' ') {
			s.erase(0, 1);
		}
	}

	return num;
}

uint64_t HelperFunctions::getUIntFromString(string& s, bool eraseEnd)
{
	bool even = true;
	if (s[0] == '-' || s[0] == '+') {
		if (s[0] == '-') {
			even = false;
		}
		s.erase(0, 1);
	}

	uint64_t num = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			num *= 10;
			num += s[i] - '0';
			s.erase(0, 1);
			i--;
		}
		else {
			break;
		}
	}

	if (!even) {
		num *= -1;
	}

	if (eraseEnd) {
		s.erase(0, 1);
	}

	return num;
}

vector<int> HelperFunctions::Sort(std::vector<int> list)
{
	std::vector<int> list2;

	for (int i = 0; i < list.size(); i++) {
		int lowestIndex = 0;
		int lowest = list[0];
		for (int j = i + 1; j < list.size(); j++) {
			if (lowest > list[j]) {
				lowest = list[j];
				lowestIndex = j;
			}
		}
		list2.push_back(lowest);
		list.erase(list.begin() + lowestIndex, list.begin() + lowestIndex + 1);
		i--;
	}

	return list2;
}

Vec2::Vec2(int newX, int newY)
{
	x = newX;
	y = newY;
}

Vec2 Vec2::operator+(const Vec2 rhs)
{
	return Vec2(x + rhs.x, y + rhs.y);
}

Vec2 Vec2::operator-(const Vec2 rhs)
{
	return Vec2(x - rhs.x, y - rhs.y);
}

bool Vec2::operator<(const Vec2& rhs)
{
	int total = this->y * 100 + this->x;
	int total2 = rhs.y * 100 + rhs.x;
	return total < total2;
}

bool Vec2::operator>(const Vec2& rhs)
{
	return this->x > rhs.x;
}

Vec2 Vec2::operator*(const Vec2 rhs)
{
	return Vec2(x * rhs.x, y * rhs.y);
}

Vec2 Vec2::operator*(const int rhs)
{
	return Vec2(x * rhs, y * rhs);
}

Vec2 Vec2::operator+=(const Vec2 rhs)
{
	x += rhs.x;
	y += rhs.y;
	return *this;
}

bool Vec2::operator==(const Vec2 rhs)
{
	if (x == rhs.x && y == rhs.y) {
		return true;
	}
	return false;
}
