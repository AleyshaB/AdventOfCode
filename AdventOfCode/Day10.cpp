#include "Day10.h"

void Day10::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day10Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day10Real.txt");
}

void Day10::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	vector<pair<int, int>> trailHeads;

	while (getline(MyReadFile, myText)) {
		grid.push_back(vector<int>());
		for (int i = 0; i < myText.size(); i++) {
			grid.back().push_back(myText[i] - '0');

			if (grid.back().back() == 0) {
				trailHeads.push_back(pair<int, int>(grid.back().size() - 1, grid.size() - 1));
				//cout << trailHeads.back().first << ", " << trailHeads.back().second << endl;
			}
		}
	}

	int total = 0;
	for (int i = 0; i < trailHeads.size(); i++) {
		total += PathFind(trailHeads[i]);
	}

	cout << "Total = " << total << endl;

	// Close the file
	MyReadFile.close();

	grid.clear();
}

int Day10::PathFind(pair<int, int> start)
{
	int numPaths = 0;
	vector<pair<int, int>> paths;
	//vector<vector<bool>> visited(grid.size(), vector<bool>(grid.back().size(), false));
	paths.push_back(start);

	while (paths.size() > 0) {
		int x = paths[0].first;
		int y = paths[0].second;
		int newY = y - 1;
		int newX = x - 1;

		if (newX > -1 && grid[y][newX] - 1 == grid[y][x]) {
			if (grid[y][newX] == 9) {// && !visited[y][newX]) {
				//visited[y][newX] = !visited[y][newX];
				numPaths++;
			}
			else {
				paths.push_back(pair<int, int>(newX, y));
			}
		}

		if (newY > -1 && grid[newY][x] - 1 == grid[y][x]) {
			if (grid[newY][x] == 9 ) { //&& !visited[newY][x]) {
				//visited[newY][x] = !visited[newY][x];
				numPaths++;
			}
			else {
				paths.push_back(pair<int, int>(x, newY));
			}
		}

		newX = x + 1;
		newY = y + 1;

		if (newX < grid.back().size() && grid[y][newX] - 1 == grid[y][x]) {
			if (grid[y][newX] == 9) { // && !visited[y][newX]) {
				//visited[y][newX] = !visited[y][newX];
				numPaths++;
			}
			else {
				paths.push_back(pair<int, int>(newX, y));
			}
		}

		if (newY < grid.size() && grid[newY][x] - 1 == grid[y][x]) {
			if (grid[newY][x] == 9) { // //&& !visited[newY][x]) {
				//visited[newY][x] = !visited[newY][x];
				numPaths++;
			}
			else {
				paths.push_back(pair<int, int>(x, newY));
			}
		}

		paths.erase(paths.begin(), paths.begin() + 1);
	}

	//cout << numPaths << endl;
	return numPaths;
}
