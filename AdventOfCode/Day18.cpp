#include "Day18.h"

void Day18::run()
{
	gridSize = 7;
	numFall = 12;
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day18Test.txt");

	gridSize = 71;
	numFall = 1024;
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day18Real.txt");
}

void Day18::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	vector<vector<bool>> grid(gridSize, vector<bool>(gridSize, true));

	int numFell = 0;
	while (getline(MyReadFile, myText)) {
		int num1 = helperFunctions.getIntFromString(myText);
		int num2 = helperFunctions.getIntFromString(myText);

		grid[num2][num1] = false;

		numFell++;
		if (numFell == numFall) {
			break;
		}
	}

	unordered_map<int, vector<Vec2>> nodes;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j]) {
				int pos = getPos(Vec2(j, i));
				if (i - 1 > -1 && grid[i - 1][j]) {
					nodes[pos].push_back(Vec2(j, i - 1));
				}
				if (j - 1 > -1 && grid[i][j - 1]) {
					nodes[pos].push_back(Vec2(j - 1, i));
				}
				if (i + 1 < gridSize && grid[i + 1][j]) {
					nodes[pos].push_back(Vec2(j, i + 1));
				}
				if (j + 1 < gridSize && grid[i][j + 1]) {
					nodes[pos].push_back(Vec2(j + 1, i));
				}
			}
		}
	}

	PrintGrid(grid);

	while (getline(MyReadFile, myText)) {
		int num1 = helperFunctions.getIntFromString(myText);
		int num2 = helperFunctions.getIntFromString(myText);

		if (num2 - 1 > -1 && grid[num2 - 1][num1]) {
			int pos = getPos(Vec2(num1, num2 - 1));
			const auto& iter = find(nodes[pos].begin(), nodes[pos].end(), Vec2(num1, num2));

			if (iter != nodes[pos].end()) {
				nodes[pos].erase(iter, iter + 1);
			}
		}
		if (num1 - 1 > -1 && grid[num2][num1 - 1]) {
			int pos = getPos(Vec2(num1 - 1, num2));
			const auto& iter = find(nodes[pos].begin(), nodes[pos].end(), Vec2(num1, num2));

			if (iter != nodes[pos].end()) {
				nodes[pos].erase(iter, iter + 1);
			}
		}
		if (num2 + 1 < gridSize && grid[num2 + 1][num1]) {
			int pos = getPos(Vec2(num1, num2 + 1));
			const auto& iter = find(nodes[pos].begin(), nodes[pos].end(), Vec2(num1, num2));

			if (iter != nodes[pos].end()) {
				nodes[pos].erase(iter, iter + 1);
			}
		}
		if (num1 + 1 < gridSize && grid[num2][num1 + 1]) {
			int pos = getPos(Vec2(num1 + 1, num2));
			const auto& iter = find(nodes[pos].begin(), nodes[pos].end(), Vec2(num1, num2));

			if (iter != nodes[pos].end()) {
				nodes[pos].erase(iter, iter + 1);
			}
		}


		vector<Vec2> newPath = PathFind(nodes, Vec2(0, 0), Vec2(gridSize - 1, gridSize - 1));
		if (newPath.size() == 0) {
			cout << "Last Byte: " << num1 << ", " << num2 << endl;
			break;
		}
	}

	// Close the file
	MyReadFile.close();
}

vector<Vec2> Day18::PathFind(unordered_map<int, vector<Vec2>> grid, Vec2 start, Vec2 end)
{
	unordered_map<int, Vec2> cameFrom;
	unordered_map<int, int> gScore;
	unordered_map<int, int> fScore;
	gScore.insert(pair<int, int>(getPos(start), 0));
	fScore.insert(pair<int, int>(getPos(start), h(start, end)));
	vector<Vec2> nodes;
	nodes.push_back(start);


	int lowestPoints = -1;
	while (nodes.size() > 0) {
		Vec2 current = nodes[0];
		int currentLowest = fScore[getPos(current)];
		int index = 0;
		for (int i = 1; i < nodes.size(); i++) {
			if (fScore[getPos(nodes[i])] < currentLowest) {
				index = i;
				current = nodes[index];
				currentLowest = fScore[getPos(current)];
			}
		}

		//cout << "Current: " << current.x << ", " << current.y << endl;

		if (current == end) {
			return ReconstructPath(cameFrom, current);
		}

		nodes.erase(nodes.begin() + index, nodes.begin() + index + 1);

		for (auto iter : grid[getPos(current)]) {
			int tentativeScore = gScore[getPos(current)];
			tentativeScore += 1;

			if (!gScore.contains(getPos(iter)) || tentativeScore < gScore[getPos(iter)]) {
				cameFrom[getPos(iter)] = current;
				gScore[getPos(iter)] = tentativeScore;
				fScore[getPos(iter)] = tentativeScore + h(iter, end);

				if (find(nodes.begin(), nodes.end(), iter) == nodes.end()) {
					nodes.push_back(iter);
				}
			}
		}
	}

	return vector<Vec2>();
}

vector<Vec2> Day18::ReconstructPath(unordered_map<int, Vec2> cameFrom, Vec2 current)
{
	int total = 0;

	vector<Vec2> path;
	while (cameFrom.contains(getPos(current))) {
		path.push_back(current);

		//cout << "Current: " << current.x << ", " << current.y << endl;
		Vec2 next = cameFrom[getPos(current)];


		current = next;
	}

	path.push_back(current);
	return path;
}

int Day18::h(Vec2 current, Vec2 end)
{
	return abs(current.x - end.x) + abs(current.y - end.y);
}

int Day18::getPos(Vec2 current)
{
	return current.y * 1000 + current.x;
}

void Day18::PrintGrid(vector<vector<bool>> grid)
{
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (!grid[i][j]) {
				cout << "#";
			}
			else {
				cout << ".";
			}
		}
		cout << endl;
	}
}
