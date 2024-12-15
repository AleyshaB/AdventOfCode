#include "Day15.h"

void Day15::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day15Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day15Real.txt");
}

void Day15::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	vector<vector<GridType>> grid;
	vector<Vec2> directions;

	bool startDirections = false;

	Vec2 robot;
	while (getline(MyReadFile, myText)) {
		if (myText == "") {
			startDirections = true;
		}
		else if (startDirections) {
			for (int i = 0; i < myText.size(); i++) {
				if (myText[i] == '^') {
					directions.push_back(cardinalDirs[0]);
				}
				else if (myText[i] == '>') {
					directions.push_back(cardinalDirs[1]);
				}
				else if (myText[i] == 'v') {
					directions.push_back(cardinalDirs[2]);
				}
				else if (myText[i] == '<') {
					directions.push_back(cardinalDirs[3]);
				}
			}
		}
		else {
			grid.push_back(vector<GridType>());
			for (int i = 0; i < myText.size(); i++) {
				if (myText[i] == '#') {
					grid.back().push_back(WALL);
					grid.back().push_back(WALL);
				}
				else if (myText[i] == 'O') {
					grid.back().push_back(BOX1);
					grid.back().push_back(BOX2);
				}
				else if (myText[i] == '.') {
					grid.back().push_back(BLANK);
					grid.back().push_back(BLANK);
				}
				else if (myText[i] == '@') {
					grid.back().push_back(BLANK);
					robot = Vec2(grid.back().size() - 1, grid.size() - 1);
					grid.back().push_back(BLANK);
				}
			}
		}
	}

	for (int i = 0; i < directions.size(); i++) {
		Vec2 triedLocation = robot + directions[i];

		if (grid[triedLocation.y][triedLocation.x] == WALL) {
			continue;
		}
		else if (grid[triedLocation.y][triedLocation.x] == BLANK) {
			robot += directions[i];
		}
		else {
			grid = SimulateMovement(grid, triedLocation, directions[i], robot);
		}

	}

	PrintGrid(grid, robot);

	uint64_t total = 0;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j] == BOX1) {
				total += (100 * i) + j;
			}
		}
	}

	cout << total << endl;

	// Close the file
	MyReadFile.close();
}

void Day15::PrintGrid(vector<vector<GridType>> grid, Vec2 robot)
{
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (i == robot.y && j == robot.x) {
				cout << "@";
			}
			else {
				switch (grid[i][j]) {
				case WALL:
					cout << "#";
					break;
				case BLANK:
					cout << ".";
					break;
				case BOX1:
					cout << "[";
					break;
				case BOX2:
					cout << "]";
					break;
				}
			}
		}
		cout << endl;
	}
	cout << endl;
}

vector<vector<Day15::GridType>> Day15::SimulateMovement(vector<vector<GridType>> grid, Vec2 pos,  Vec2 dir, Vec2& robot)
{
	vector<vector<GridType>> heldGrid = grid;
	Vec2 newPos = pos;
	vector<Vec2> boxes;

	bool moveBoxes = false;
	if (dir.x != 0) {
		while (true) {
			if (grid[newPos.y][newPos.x] == BLANK) {
				moveBoxes = true;
				break;
			}
			else if (grid[newPos.y][newPos.x] == WALL) {
				break;
			}
			else {
				boxes.push_back(newPos);
			}

			newPos += dir;
		}
	}
	else {
		vector<int> points;
		points.push_back(newPos.x);
		boxes.push_back(newPos);
		if (grid[newPos.y][newPos.x] == BOX1) {
			points.push_back(newPos.x + 1);
			boxes.push_back(newPos + Vec2(1, 0));
		}
		else if (grid[newPos.y][newPos.x] == BOX2) {
			points.push_back(newPos.x - 1);
			boxes.push_back(newPos + Vec2(-1, 0));
		}
		while (true) {
			newPos.y += dir.y;
			bool wall = false;
			for (int i = 0; i < points.size(); i++) {
				newPos.x = points[i];
				if (grid[newPos.y][newPos.x] == BLANK) {
					points.erase(points.begin() + i, points.begin() + i + 1);
					i--;
					continue;
				}
				else if (grid[newPos.y][newPos.x] == WALL) {
					wall = true;
					break;
				}
				else {
					if (grid[newPos.y][newPos.x] == BOX1) {
						if (find(points.begin(), points.end(), newPos.x + 1) == points.end()) {
							points.insert(points.begin() + i, newPos.x + 1);
						}
						if (find(boxes.begin(), boxes.end(), newPos + Vec2(1, 0)) == boxes.end()) {
							boxes.push_back(newPos + Vec2(1, 0));
						}
					}
					else {
						if (find(points.begin(), points.end(), newPos.x - 1) == points.end()) {
							points.insert(points.begin() + i, newPos.x - 1);
						}
						if (find(boxes.begin(), boxes.end(), newPos + Vec2(-1, 0)) == boxes.end()) {
							boxes.push_back(newPos + Vec2(-1, 0));
						}
					}
					if (find(boxes.begin(), boxes.end(), newPos) == boxes.end()) {
						boxes.push_back(newPos);
					}
				}
			}

			if (points.size() == 0) {
				moveBoxes = true;
				break;
			}
			if (wall) {
				break;
			}
		}
	}

	if (moveBoxes) {
		robot += dir;
		for (int i = boxes.size() -1; i > -1; i--) {
			grid[boxes[i].y + dir.y][boxes[i].x + dir.x] = grid[boxes[i].y][boxes[i].x];
			grid[boxes[i].y][boxes[i].x] = BLANK;
		}

		/*PrintGrid(grid, robot);
		cout << "direction = " << dir.x << ", " << dir.y << endl;*/

		/*string s;
		cin >> s;*/
	}
	return grid;
}
