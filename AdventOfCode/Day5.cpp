#include "Day5.h"

void Day5::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day5Test.txt");
	cout << "\n\n\n\n\n RealData:" << endl;
	RunScript("TestData/2024/Day5Real.txt");
}

void Day5::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	bool pairs = true;
	int total1 = 0;
	int total2 = 0;
	while (getline(MyReadFile, myText)) {
		if (myText == "") {
			pairs = false;
			continue;
		}

		if (pairs) {
			int num1 = helperFunctions.getIntFromString(myText);
			int num2 = helperFunctions.getIntFromString(myText);
			rules[num1].push_back(num2);
			cout << "Rule: " << num1 << "-" << num2 << endl;
		}
		else {
			cout << "New Page: ";
			std::vector<int> pages;
			while (myText.size() > 0) {
				pages.push_back(helperFunctions.getIntFromString(myText));
				cout << pages.back() << ", ";
			}
			cout << endl;

			bool correct = true;
			bool initialCorrect = true;
			initialCorrect = SortPages(pages);
			

			int middlePage = ceil((float)pages.size() / 2.0f);
			cout << middlePage << endl;
			if (initialCorrect) {
				total1 += pages[middlePage - 1];
			}
			else {
				total2 += pages[middlePage - 1];
			}
		}
	}

	cout << total2 << endl;

	rules.clear();

	// Close the file
	MyReadFile.close();
}

bool Day5::SortPages(vector<int>& pages)
{
	bool initialCorrect = true;
	for (int i = 1; i < pages.size(); i++) {
		if (rules.find(pages[i]) == rules.end()) {
			continue;
		}
		int numWrong = 0;
		for (int j = 0; j < i; j++) {
			for (int r = 0; r < rules[pages[i]].size(); r++) {
				if (pages[j] == rules[pages[i]][r]) {
					int page = pages[j];
					pages.erase(pages.begin() + j, pages.begin() + j + 1);
					pages.insert(pages.begin() + i + numWrong, page);
					numWrong++;
					i--;
					j--;
					initialCorrect = false;
					break;
				}
			}
		}
	}

	return initialCorrect;
}
