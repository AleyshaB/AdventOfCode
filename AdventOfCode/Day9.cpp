#include "Day9.h"

void Day9::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day9Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day9Real.txt");
}

void Day9::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	vector<pair<int, int>> dense;
	vector<pair<int, bool>> expanded;
	while (getline(MyReadFile, myText)) {
		int position = 0;
		for (int i = 0; i < myText.size(); i++) {
			int num = myText[i] - '0';
			dense.push_back(pair<int, int>(num, position));
			int num2 = i % 2 == 0 ? floor(i / 2) : -1;
			for (int j = 0; j < num; j++) {
				expanded.push_back(pair<int, bool>(num2, static_cast<bool>(i % 2)));
				//cout << expanded.back().first;
			}
			//cout << endl;
			position += num;
		}

	}


	bool finished = false;
	for (int i = dense.size() - 1; i > 0; i -= 2) {
		int size = dense[i].first;
		int freeSpace = 0;
		for (int j = 0; j < dense[i].second; j++) {
			if (expanded[j].first == -1) {
				freeSpace++;
			}
			else {
				freeSpace = 0;
			}

			if (freeSpace == size) {
				for (int x = 0; x < size; x++) {
					SwapElements(expanded, j - x, dense[i].second + x);
				}
				//PrintList(expanded);
				break;
			}
		}
	}

	uint64_t total = 0;

	for (int i = 0; i < expanded.size(); i++) {
		if (expanded[i].first == -1) {
			continue;
		}
		total += expanded[i].first * i;
	}

	cout << total << endl;

	

	// Close the file
	MyReadFile.close();
}

void Day9::SwapElements(vector<pair<int, bool>>& list, int first, int second)
{
	pair<int, bool> num1 = list[first];
	pair<int, bool> num2 = list[second];

	list.erase(list.begin() + first, list.begin() + first + 1);
	list.insert(list.begin() + first, num2);
	list.erase(list.begin() + second, list.begin() + second + 1);
	list.insert(list.begin() + second, num1);
}

void Day9::PrintList(vector<pair<int, bool>> list)
{
	for (int i = 0; i < list.size(); i++) {
		cout << list[i].first;
	}
	cout << endl;
}

bool Day9::CheckSpace(vector<pair<int, bool>> list)
{
	bool space = false;
	for (int i = 0; i < list.size(); i++) {
		if (list[i].first == -1) {
			space = true;
		}

		if (space && list[i].first != -1) {
			return false;
		}
	}
	return true;
}
