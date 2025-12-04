#include "Day4.h"

void Day4::run()
{
	cout << "Test Data: " << endl;
	RunScript("TestData/2025/Day4Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2025/Day4Real.txt");
}

void Day4::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	vector<vector<bool>> grid;
	while (getline(MyReadFile, myText)) {
		grid.push_back(vector<bool>());
		for (int i = 0; i < myText.size(); i++) {
			if (myText[i] == '.') {
				grid.back().push_back(false);
			}
			else {
				grid.back().push_back(true);
			}
		}
	}

	int num = 0;
	int removed = 1;
	while (removed > 0) {
		removed = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid.size(); j++) {
				if (grid[i][j]) {
					int numAround = 0;
					if (i > 0 && j > 0) {
						if (grid[i - 1][j - 1]) {
							numAround++;
						}
					}
					if (i > 0 && j < grid[i].size() - 1) {
						if (grid[i - 1][j + 1]) {
							numAround++;
						}
					}
					if (i < grid.size() - 1 && j > 0) {
						if (grid[i + 1][j - 1]) {
							numAround++;
						}
					}
					if (i < grid.size() - 1 && j < grid[i].size() - 1) {
						if (grid[i + 1][j + 1]) {
							numAround++;
						}
					}

					if (i > 0) {
						if (grid[i - 1][j]) {
							numAround++;
						}
					}
					if (i < grid.size() - 1) {
						if (grid[i + 1][j]) {
							numAround++;
						}
					}
					if (j > 0) {
						if (grid[i][j - 1]) {
							numAround++;
						}
					}
					if (j < grid[i].size() - 1) {
						if (grid[i][j + 1]) {
							numAround++;
						}
					}

					//cout << numAround << endl;

					if (numAround < 4) {
						num++;
						grid[i][j] = false;
						removed++;
					}
				}
			}
		}
	}
	cout << num << endl;

	// Close the file
	MyReadFile.close();
}