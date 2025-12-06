#include "Day6.h"

void Day6::run()
{
	//cout << "Test Data: " << endl;
	//RunScript("TestData/2025/Day6Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2025/Day6Real.txt");
}

void Day6::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	std::vector<bool> multiply;
	std::vector<std::vector<char>> columns;
	while (getline(MyReadFile, myText)) {
		if (myText[0] != '*') {
			columns.push_back(std::vector<char>());

			for (int i = 0; i < myText.size();i++) {
				columns.back().push_back(myText[i]);
			}
		}
		else {
			while (myText.size() > 0) {
				if (myText[0] == '*') {
					multiply.push_back(true);
					myText.erase(0, 1);
				}
				else if (myText[0] == '+') {
					multiply.push_back(false);
					myText.erase(0, 1);
				}
				while (myText.size() > 0 && myText[0] == ' ') {
					myText.erase(0, 1);
				}
			}
		}
	}

	std::vector<std::vector<int>> nums;
	nums.resize(columns.size());
	int index = 0;
	for (int j = 0; j < columns.back().size(); j++) {
		int num = 0;
		for (int i = 0; i < columns.size(); i++) {
			if (columns[i][j] != ' ') {
				num *= 10;
				num += columns[i][j] - '0';
			}
		}

		if (num == 0) {
			while (index < columns.size()) {
				nums[index].push_back(0);
				index++;
			}
			index = 0;
		}
		else {
			nums[index].push_back(num);
			index++;
		}
	}

	nums.back().push_back(0);
	

	uint64_t total = 0;
		for (int m = 0; m < multiply.size(); m++) {
			uint64_t currentTotal = nums[0][m];
			for (int i = 1; i < nums.size(); i++) {
				if (multiply[m] && nums[i][m] != 0 && currentTotal != 0) {
					currentTotal *= nums[i][m];
				}
				else {
					currentTotal += nums[i][m];
				}
			}
			total += currentTotal;
		}

	cout << total << endl;

	// Close the file
	MyReadFile.close();
}