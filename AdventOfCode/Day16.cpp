#include "Day16.h"

inline bool operator< (const Vec2& lhs, const Vec2& rhs) {
	// std::tuple's lexicographic ordering does all the actual work for you
	// and using std::tie means no actual copies are made
	return lhs.x < rhs.x;
}

void Day16::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day16Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day16Real.txt");
}

void Day16::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);


	vector<vector<bool>> grid; //true blank, false wall
	Vec2 start;
	Vec2 end;
	while (getline(MyReadFile, myText)) {
		grid.push_back(vector<bool>());
		for (int i = 0; i < myText.size(); i++) {
			if (myText[i] == '#') {
				grid.back().push_back(false);
			}
			else if (myText[i] == '.') {
				grid.back().push_back(true);
			}
			else if (myText[i] == 'E') {
				grid.back().push_back(true);
				end = Vec2(i, grid.size() - 1);
			}
			else if (myText[i] == 'S') {
				grid.back().push_back(true);
				start = Vec2(i, grid.size() - 1);
			}
		}
	}

	gridSizeX = grid.back().size();

	unordered_map<int, vector<Vec2>> nodes;
	for (int i = 0; i < grid.size(); i++) {
		for (int j = 0; j < grid[i].size(); j++) {
			if (grid[i][j]) {
				int pos = getPos(Vec2(j, i));
				if (i - 1 > 0 && grid[i - 1][j]) {
					nodes[pos].push_back(Vec2(j, i - 1));
				}
				if (j - 1 > 0 && grid[i][j - 1]) {
					nodes[pos].push_back(Vec2(j - 1, i));
				}
				if (i + 1 < grid.size() - 1 && grid[i + 1][j]) {
					nodes[pos].push_back(Vec2(j, i + 1));
				}
				if (j + 1 < grid.back().size() - 1 && grid[i][j + 1]) {
					nodes[pos].push_back(Vec2(j + 1, i));
				}
			}
		}
	}

	PathFind(nodes, start, end);

	cout << uniquePlaces.size() << endl;

	// Close the file
	MyReadFile.close();
}

int Day16::PathFind(unordered_map<int, vector<Vec2>> grid, Vec2 start, Vec2 end)
{
	unordered_map<int, Vec2> cameFrom;
	unordered_map<int, Vec2> dirs;
	dirs.insert(pair<int, Vec2>(getPos(start), helperFunctions.cardinalDirs[1]));
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

		//cout << "Current: " << current.x << ", " << current.y << " - Dir " << dirs[getPos(current)].x << ", " << dirs[getPos(current)].y << endl;

		if (current == end) {
			int path = ReconstructPath(cameFrom, current, 0);

			if (path == lowestPoints || lowestPoints == -1) {
				lowestPoints = path;
				//cout << "Found Path!" << endl;
				ReconstructPath(cameFrom, current, 1);
			}
			else if (path < lowestPoints) {
				return 0;
			}
		}

		nodes.erase(nodes.begin() + index, nodes.begin() + index  + 1);

		for (auto iter : grid[getPos(current)]) {
			int tentativeScore = gScore[getPos(current)];

			Vec2 newDir = Vec2((iter.x - current.x), (iter.y - current.y));
			if (newDir == dirs[getPos(current)]) {
				tentativeScore += 1;
			}
			else {
				tentativeScore += 1001;
			}

			if (gScore.contains(getPos(iter)) && tentativeScore - 1000 == gScore[getPos(iter)]) {
				ReconstructPath(cameFrom, current, 2, iter);
				//cout << "Found Alternative Path : " << current.x << ", " << current.y << endl;
			}

			if (!gScore.contains(getPos(iter)) || tentativeScore < gScore[getPos(iter)]) {
				cameFrom[getPos(iter)] = current;
				gScore[getPos(iter)] = tentativeScore;
				fScore[getPos(iter)] = tentativeScore + h(iter, end);
				dirs[getPos(iter)] = newDir;

				if (find(nodes.begin(), nodes.end(), iter) == nodes.end()) {
					nodes.push_back(iter);
				}
			}
		}
	}

	return 0;
}

int Day16::ReconstructPath(unordered_map<int, Vec2> cameFrom, Vec2 current, int copyPlaces, Vec2 name)
{
	int total = 0;
	Vec2 dir = current - cameFrom[getPos(current)];

	while (cameFrom.contains(getPos(current))) {
		if (copyPlaces == 1) {
			uniquePlaces.insert(getPos(current));

			if (possiblePaths.contains(getPos(current))) {
				//cout << "Merging Paths: " << current.x << ", " << current.y << endl;
				set<int> copy = possiblePaths[getPos(current)];
				uniquePlaces.merge(copy);

				Merge(getPos(current));
			}
		}
		else if (copyPlaces == 2) {
			possiblePaths[getPos(name)].insert(getPos(current));
		}

		//cout << "Current: " << current.x << ", " << current.y << endl;
		Vec2 next = cameFrom[getPos(current)];

		Vec2 newDir = current - cameFrom[getPos(current)];
		if (newDir != dir) {
			total += 1001;
		}
		else {
			total += 1;
		}

		dir = newDir;

		current = next;
	}
	if (copyPlaces == 1) {
		uniquePlaces.insert(getPos(current));
	}
	return total;
}

void Day16::Merge(int path)
{
	for (auto iter : possiblePaths[path]) {
		if (iter != path && possiblePaths.contains(iter)) {
			//cout << "Merging Paths: " << iter << endl;
			set<int> copy = possiblePaths[getPos(iter)];
			uniquePlaces.merge(copy);
			Merge(iter);
		}
	}
}

int Day16::h(Vec2 current, Vec2 end)
{
	return abs(current.x - end.x) + abs(current.y - end.y);
}

int Day16::getPos(Vec2 current)
{
	return current.y * 1000 + current.x;
}
