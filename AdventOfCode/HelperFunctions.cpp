#include "HelperFunctions.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

int HelperFunctions::getIntFromString(string& s, bool eraseEnd)
{
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
		s.erase(0, 1);
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
