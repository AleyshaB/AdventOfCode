#include "Day14.h"

void Day14::run()
{
	height = 7;
	width = 11;
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day14Test.txt");

	height = 103;
	width = 101;
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day14Real.txt");
}

void Day14::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	vector<pair<int, int>> robots;
	vector<pair<int, int>> velocities;
	while (getline(MyReadFile, myText)) {
		myText.erase(myText.begin(), myText.begin() + 2);

		int num1 = helperFunctions.getIntFromString(myText);
		int num2 = helperFunctions.getIntFromString(myText);

		robots.push_back(pair<int, int>(num1, num2));

		myText.erase(myText.begin(), myText.begin() + 2);

		num1 = helperFunctions.getIntFromString(myText);
		num2 = helperFunctions.getIntFromString(myText);

		velocities.push_back(pair<int, int>(num1, num2));
	}


	int turns = 0;
	while (true) {
		turns++;
		set<pair<int, int>> uniquePositions;
		for (int i = 0; i < robots.size(); i++) {
			int x = robots[i].first + velocities[i].first;
			int y = robots[i].second + velocities[i].second;

			x = x % width;
			y = y % height;

			if (x < 0) {
				x = width + x;
			}

			if (y < 0) {
				y = height + y;
			}

			uniquePositions.insert(pair<int, int>(x, y));

			robots[i].first = x;
			robots[i].second = y;
		}

		string help;
		if (uniquePositions.size() == robots.size()) {
			cout << turns << endl;
			PrintGrid(uniquePositions);
			cin >> help;
		}
	}

	// Close the file
	MyReadFile.close();
}

void Day14::PrintGrid(set<pair<int, int>> robots)
{
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (robots.contains(pair<int, int>(j, i))) {
				cout << "#";
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
}
