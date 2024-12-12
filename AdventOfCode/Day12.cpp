#include "Day12.h"
#include <set>

void Day12::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day12Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day12Real.txt");
}

void Day12::RunScript(string filename)
{
	total = 0;
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	vector<vector<pair<char, bool>>> grid;
	while (getline(MyReadFile, myText)) {
		grid.push_back(vector<pair<char, bool>>());
		for (int i = 0; i < myText.size(); i++) {
			grid.back().push_back(pair<char, bool>(myText[i], false));
		}
	}

	//GetAreaAndPerimiter(grid, 0, 0);

	for (int y = 0; y < grid.size(); y++) {
		for (int x = 0; x < grid[y].size(); x++) {
			if (!grid[y][x].second) {
				GetAreaAndPerimiter(grid, y, x);
			}
		}
	}

	cout << total << endl;

	// Close the file
	MyReadFile.close();
}

void Day12::GetAreaAndPerimiter(vector<vector<pair<char, bool>>>& grid, int y, int x)
{
	vector<vector<vector<bool>>> fences;
	fences.resize(grid.size(), vector<vector<bool>>(grid.back().size(), vector<bool>(4, false)));

	set<pair<int, int>> usedPositions;
	vector<pair<int, int>> positions;
	positions.push_back(pair<int, int>(x, y));
	char value = grid[y][x].first;

	//cout << "Area " << value << " at " << x << ", " << y << endl;

	int area = 0;
	int perimiter = 0;
	while (positions.size() > 0) {
		if (usedPositions.contains(positions[0])) {
			positions.erase(positions.begin(), positions.begin() + 1);
			continue;
		}
		usedPositions.insert(positions[0]);
		area++;

		int X = positions[0].first;
		int Y = positions[0].second;
		int newX = X - 1;
		int newY = Y - 1;

		grid[Y][X].second = true;

		if (newX > -1 && grid[Y][newX].first == value) {

			positions.push_back(pair<int, int>(newX, Y));
		}
		else {
			fences[Y][X][3] = true;
			if (!(usedPositions.contains(pair<int, int>(X, Y - 1)) && fences[Y - 1][X][3]) &&
				!(usedPositions.contains(pair<int, int>(X, Y + 1)) && fences[Y + 1][X][3])) {
				perimiter++;
			}
		}

		newX = X + 1;

		if (newX < grid.back().size() && grid[Y][newX].first == value) {
			positions.push_back(pair<int, int>(newX, Y));
		}
		else {
			fences[Y][X][1] = true;
			if (!(usedPositions.contains(pair<int, int>(X, Y - 1)) && fences[Y - 1][X][1]) &&
				!(usedPositions.contains(pair<int, int>(X, Y + 1)) && fences[Y + 1][X][1])) {
				perimiter++;
			}
		}

		if (newY > -1 && grid[newY][X].first == value) {
			positions.push_back(pair<int, int>(X, newY));
		}
		else {
			fences[Y][X][0] = true;
			if (!(usedPositions.contains(pair<int, int>(X - 1, Y)) && fences[Y][X - 1][0]) &&
				!(usedPositions.contains(pair<int, int>(X + 1, Y)) && fences[Y][X + 1][0])) {
				perimiter++;
			}
		}

		newY = Y + 1;

		if (newY < grid.size() && grid[newY][X].first == value) {
			positions.push_back(pair<int, int>(X, newY));
		}
		else {
			fences[Y][X][2] = true;
			if (!(usedPositions.contains(pair<int, int>(X - 1, Y)) && fences[Y][X - 1][2]) &&
				!(usedPositions.contains(pair<int, int>(X + 1, Y)) && fences[Y][X + 1][2])) {
				perimiter++;
			}
		}

		positions.erase(positions.begin(), positions.begin() + 1);
	}

	//cout << area << " : " << perimiter << endl;

	total += (area * perimiter);
}
