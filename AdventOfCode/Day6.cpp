#include "Day6.h"

void Day6::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day6Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day6Real.txt");
}

void Day6::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	x = 0;
	y = 0;
	int direction = 0; // 0 - up, 1 - right, 2 - down, 3 - left
	while (getline(MyReadFile, myText)) {
		grid.push_back(vector<pair<bool, bool>>());
		for (int i = 0; i < myText.size(); i++) {
			if (myText[i] == '#') {
				grid.back().push_back(pair<bool, bool>(true, false));
			}
			else if (myText[i] == '.') {
				grid.back().push_back(pair<bool, bool>(false, false));
			}
			else if (myText[i] == '^') {
				grid.back().push_back(pair<bool, bool>(false, true));
				x = i;
				y = grid.size() - 1;
			}
		}
	}

	dir.resize(grid.size(), vector<int>(grid[0].size(), -1));
	int tempX = x;
	int tempY = y;

	vector<vector<pair<bool, bool>>> heldGrid = grid;

	while (!Move(direction)) {
		direction++;
		direction = direction == 4 ? 0 : direction;
	}

	int total = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid.size(); j++) {
			if (grid[i][j].second) {
				total++;
			}
		}
	}

	copyGrid = grid;

	for (int i = 0; i < copyGrid.size(); i++) {
		for (int j = 0; j < copyGrid[i].size(); j++) {
			if (copyGrid[i][j].second) {
				dir.clear();
				dir.resize(grid.size(), vector<int>(grid[0].size(), -1));

				x = tempX;
				y = tempY;
				grid = heldGrid;
				direction = 0;

				grid[i][j].first = true;

				int move = 0;
				while (move == 0) {
					move = MovePart2(direction);
					direction++;
					direction = direction == 4 ? 0 : direction;
				}

				if (move == 2) {
					total2++;
				}
			}
		}
	}
	
	cout << total << endl;
	cout << total2 << endl;

	grid.clear();

	total2 = 0;

	// Close the file
	MyReadFile.close();
}

bool Day6::Move(int direction)
{
	int moveX = 0;
	int moveY = 0;
	switch (direction) {
	case 0:
		moveY = -1;
		break;
	case 1:
		moveX = 1;
		break;
	case 2:
		moveY = 1;
		break;
	case 3:
		moveX = -1;
		break;
	}

	do {
		int tempX = x + moveX;
		int tempY = y + moveY;
		if (tempX < grid.size() && tempX > -1 && tempY < grid.size() && tempY > -1) {
			if (!grid[tempY][tempX].first) {
				x = tempX;
				y = tempY;
				grid[y][x].second = true;
			}
			else {
				return false;
			}
		}
		else {
			return true;
		}
	} while (true);
}

int Day6::MovePart2(int direction)
{
	int moveX = 0;
	int moveY = 0;
	switch (direction) {
	case 0:
		moveY = -1;
		break;
	case 1:
		moveX = 1;
		break;
	case 2:
		moveY = 1;
		break;
	case 3:
		moveX = -1;
		break;
	}

	do {
		int tempX = x + moveX;
		int tempY = y + moveY;
		if (tempX < grid.size() && tempX > -1 && tempY < grid.size() && tempY > -1) {
			if (!grid[tempY][tempX].first) {
				x = tempX;
				y = tempY;
				if (grid[y][x].second && dir[y][x] == direction) {
					return 2;
				}
				dir[y][x] = direction;
				grid[y][x].second = true;
			}
			else {
				return 0;
			}
		}
		else {
			return 1;
		}
	} while (true);
}
