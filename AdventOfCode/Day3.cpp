#include "Day3.h"

void Day3::run()
{
	cout << "Test Data: " << endl;
	RunScript("TestData/2025/Day3Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2025/Day3Real.txt");
}

void Day3::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	uint64_t num = 0;
	while (getline(MyReadFile, myText)) {
		string s = "";
		for (int x = 11; x >= 0; x--) {
			int highest = 0;
			int highestPosition = 0;
			for (int i = 0; i < myText.size() - x; i++) {
				if (highest < myText[i] - '0') {
					highest = myText[i] - '0';
					highestPosition = i;
				}
			}

			myText = myText.substr(highestPosition);
			s += myText[0];
			myText.erase(myText.begin(), myText.begin() + 1);
		}
		cout << s << endl;

		num += helperFunctions.getUIntFromString(s);
	}
	cout << num << endl;

	// Close the file
	MyReadFile.close();
}

/*
int highest = 0;
		int highestPosition = 0;
		int number = 0;
		for (int i = 0; i < myText.size() - 9; i++) {
			if (highest < myText[i] - '0') {
				highest = myText[i] - '0';
				highestPosition = i;
			}
		}

		std::vector<Vec2> nums;
		for (int i = 0; i < 8; i++) {
			int currentHighest = 0;
			int currentPosition = 0;
			for (int s = highestPosition + 1; s < myText.size(); s++) {
				if (currentHighest < myText[s] - '0') {
					currentHighest = myText[s] - '0';
					currentPosition = s + nums.size();
				}
			}

			nums.push_back(Vec2(currentHighest, currentPosition));
			myText.erase(currentPosition, currentPosition);
		}

		int tens = 100000000;
		number += highest * tens;
		for (int i = 0; i < 8; i++) {
			tens /= 10;
			int position = 10000;
			int vecPositon = 0;
			for (int x = 0; x < nums.size(); x++) {
				if (position > nums[x].y) {
					position = nums[x].y;
					vecPositon = x;
				}
			}
			number += nums[vecPositon].x * tens;
			nums.erase(nums.begin() + vecPositon, nums.begin() + vecPositon);
		}*/