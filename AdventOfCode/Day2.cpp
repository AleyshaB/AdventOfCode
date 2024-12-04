#include "Day2.h"

void Day2::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day2Test.txt");
	cout << "\n\n\n\n\n RealData:" << endl;
	RunScript("TestData/2024/Day2Real.txt");
}

void Day2::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	int total = 0;

	while (getline(MyReadFile, myText)) {
		cout << myText << endl;
		std::vector<int> reports;
		while (myText.size() > 0) {
			reports.push_back(helperFunctions.getIntFromString(myText));
		}
		
		bool safe = true;
		int current = reports[0];
		bool singleSafe = true;
		safe = CheckList(reports);

		if (!safe) {
			for (int i = 0; i < reports.size(); i++) {
				safe = true;
				vector<int> list1(reports);
				list1.erase(list1.begin() + i, list1.begin() + i + 1);
				safe = CheckList(list1);
				if (safe) {
					break;
				}
			}
		}

		if (safe) {
			cout << "Safe\n" << endl;
			total++;
		}
		else {
			cout << "Unsafe\n" << endl;
		}
	}

	cout << total << endl;

	// Close the file
	MyReadFile.close();
}

bool Day2::CheckList(vector<int> list)
{
	int current = list[0];
	if (list[0] - list[1] < 0) {
		//cout << "Accending" << endl;
		for (int i = 1; i < list.size(); i++) {
			//cout << diff << endl;
			if (current > list[i] || CheckOne(current, list[i])) {
				return false;
			}
			current = list[i];
		}
	}
	else {
		//cout << "Decending" << endl;
		for (int i = 1; i < list.size(); i++) {
			//cout << diff << endl;
			if (current < list[i] || CheckOne(current, list[i])) {
				return false;
			}
			current = list[i];
		}
	}

	return true;
}

bool Day2::CheckOne(int n1, int n2)
{
	int diff = abs(n1 - n2);
	if (diff < 1 || diff > 3) {
		return true;
		//cout << "Unsafe" << endl;
	}
	return false;
}
