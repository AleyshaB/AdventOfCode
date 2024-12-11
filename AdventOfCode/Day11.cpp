#include "Day11.h"
#include <unordered_map>

void Day11::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day11Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day11Real.txt");
}

void Day11::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);


	vector<uint64_t> nums;
	while (getline(MyReadFile, myText)) {
		while (myText.size() > 0) {
			nums.push_back(helperFunctions.getUIntFromString(myText));
		}
	}

	int numBlinks = 75;

	unordered_map<int64_t, int64_t> numToCount;

	for (int i = 0; i < nums.size(); i++) {
		++numToCount[nums[i]];
	}

	for (int i = 0; i < numBlinks; i++) {
		unordered_map<int64_t, int64_t> newNumToCount;
		for (auto [num, count] : numToCount) {
			vector<uint64_t> newNums = Update(num);
			for (int n = 0; n < newNums.size(); n++) {
				newNumToCount[newNums[n]] += count;
			}
		}

		numToCount = move(newNumToCount);
	}

	uint64_t total = 0;
	for (auto num : numToCount) {
		total += num.second;
	}

	cout << total << endl;

	// Close the file
	MyReadFile.close();
}

vector<uint64_t> Day11::Update(uint64_t num)
{
	vector<uint64_t> newNums;

	string s(to_string(num));
	if (num == 0) {
		newNums.push_back(1);
	}
	else if (s.size() % 2 == 0) {
		string newS = s.substr(0, s.size() / 2);
		newNums.push_back(atoi(newS.c_str()));
		newS = s.substr(s.size() / 2);
		newNums.push_back(atoi(newS.c_str()));
	}
	else {
		newNums.push_back(num * 2024);
	}
	

	return newNums;
}
