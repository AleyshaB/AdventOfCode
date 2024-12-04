#include "Day4.h"

void Day4::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day4Test.txt");
	cout << "\n\n\n\n\n RealData:" << endl;
	RunScript("TestData/2024/Day4Real.txt");
}

void Day4::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	vector<string> lines;
	string xmas = "XMAS";
	string samx = "SAMX";

	while (getline(MyReadFile, myText)) {
		lines.push_back(myText);
	}

	int total = 0;
	for (int i = 0; i < lines.size() - 2; i++) {
		for (int j = 0; j < lines[i].size() - 2; j++) {
			if (lines[i][j] == 'M' && lines[i + 1][j + 1] == 'A' && lines[i + 2][j + 2] == 'S') {
				if (lines[i][j + 2] == 'M' && lines[i + 2][j] == 'S') {
					total++;
				}
				else if (lines[i][j + 2] == 'S' && lines[i + 2][j] == 'M') {
					total++;
				}
			}

			if (lines[i][j] == 'S' && lines[i + 1][j + 1] == 'A' && lines[i + 2][j + 2] == 'M') {
				if (lines[i][j + 2] == 'M' && lines[i + 2][j] == 'S') {
					total++;
				}
				else if (lines[i][j + 2] == 'S' && lines[i + 2][j] == 'M') {
					total++;
				}
			}
		}
	}

	/*for (int i = 0; i < lines.size() - 3; i++) {
		for (int j = 3; j < lines[i].size(); j++) {
			if (lines[i][j] == 'X' && lines[i + 1][j - 1] == 'M' && lines[i + 2][j - 2] == 'A' && lines[i + 3][j - 3] == 'S') {
				total++;
			}

			if (lines[i][j] == 'S' && lines[i + 1][j - 1] == 'A' && lines[i + 2][j - 2] == 'M' && lines[i + 3][j - 3] == 'X') {
				total++;
			}
		}
	}*/

	cout << total << endl;

	// Close the file
	MyReadFile.close();
}
