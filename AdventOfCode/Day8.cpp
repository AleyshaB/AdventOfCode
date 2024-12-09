#include "Day8.h"

void Day8::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day8Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day8Real.txt");
}

void Day8::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	map<char, vector<pair<int, int>>> antennas;
	vector<pair<int, int>> locations;
	vector<char> types;
	int sizeY = 0;
	while (getline(MyReadFile, myText)) {
		for (int i = 0; i < myText.size(); i++) {
			if (myText[i] != '.' && myText[i] != '#') {
				antennas[myText[i]].push_back(pair<int, int>(i, sizeY));
				locations.push_back(antennas[myText[i]].back());
				if (find(types.begin(), types.end(), myText[i]) == types.end()) {
					types.push_back(myText[i]);
				}
			}
		}
		sizeY++;
	}

	int sizeX = myText.size();
	for (auto type : types) {
		//cout << "type: " << type << endl;
		for (int i = 0; i < antennas[type].size() - 1; i++) {
			for (int j = i + 1; j < antennas[type].size(); j++) {
				//cout << antennas[type][i].first << ", " << antennas[type][i].second << " - "
				//	 << antennas[type][j].first << ", " << antennas[type][j].second << " - ";
				int x = antennas[type][i].first - antennas[type][j].first;
				int y = antennas[type][i].second - antennas[type][j].second;

				pair<int, int> loc1(antennas[type][i].first + x, antennas[type][i].second + y);

				while (loc1.first > -1 && loc1.first < sizeX && loc1.second > -1 && loc1.second < sizeY) {
					if (find(locations.begin(), locations.end(), loc1) == locations.end()) {
						locations.push_back(loc1);
					}
					loc1.first += x;
					loc1.second += y;
				}

				pair<int, int> loc2(antennas[type][j].first - x, antennas[type][j].second - y);

				while (loc2.first > -1 && loc2.first < sizeX && loc2.second > -1 && loc2.second < sizeY) {
					if (find(locations.begin(), locations.end(), loc2) == locations.end()) {
						locations.push_back(loc2);
					}
					loc2.first -= x;
					loc2.second -= y;
				}

				//cout << x << ", " << y << endl;
			}
		}
	}

	cout << locations.size() << endl;

	// Close the file
	MyReadFile.close();
}