#include "Day19.h"

void Day19::run()
{
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day19Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day19Real.txt");
}

void Day19::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	getline(MyReadFile, myText);
	vector<string> towelTypes;
	while (myText.size() > 0) {
		for (int i = 0; i < myText.size(); i++) {
			if (myText[i] == ',') {
				towelTypes.push_back(myText.substr(0, i));
				myText.erase(myText.begin(), myText.begin() + i + 2);
				break;
			}
		}

		if (find(myText.begin(), myText.end(), ',') == myText.end()) {
			towelTypes.push_back(myText);
			myText.erase();
		}
	}

	getline(MyReadFile, myText);

	int total = 0;
	long long total2 = 0;
	while (getline(MyReadFile, myText)) {

		long long result = HasPattern(myText, towelTypes);
		if (result > 0) {
			total++;
			//cout << myText << " is valid" << endl;
		}

		total2 += result;

	}
	

	std::cout << total << endl;
	cout << total2 << endl;

	// Close the file
	MyReadFile.close();
}

long long Day19::HasPattern(string towel, vector<string>& towelTypes)
{
	if (towel == "") {
		return 1;
	}

	long long result = 0;

	for (int t = 0; t < towelTypes.size(); t++) {
		if (towel.size() < towelTypes[t].size()) {
			continue;
		}
		string start = towel.substr(0, towelTypes[t].size());
		if (start == towelTypes[t]) {
			result += CheckHasPattern(towel.substr(towelTypes[t].size()), towelTypes);
		}

		/*if (result > 0) {
			return result;
		}*/
	}
	return result;
}

long long Day19::CheckHasPattern(string towel, vector<string>& towelTypes)
{
	if (checked.find(towel + concated) == checked.end()) {
		long long result = HasPattern(towel, towelTypes);
		checked[towel + concated] = result;
		return result;
	}
	else {
		return checked[towel + concated];
	}
}
