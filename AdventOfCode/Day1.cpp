#include "Day1.h"

void Day1::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day1Test.txt");
	cout << "\n\n\n\n\n RealData:" << endl;
	RunScript("TestData/2024/Day1Real.txt");
}

void Day1::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);
	
	std::vector<int> list1;
	std::vector<int> list2;

	while (getline(MyReadFile, myText)) {
		list1.push_back(helperFunctions.getIntFromString(myText));

		myText.erase(0, 2);

		list2.push_back(helperFunctions.getIntFromString(myText));
	}

	list1 = helperFunctions.Sort(list1);
	list2 = helperFunctions.Sort(list2);

	uint32_t total = 0;
	for (int i = 0; i < list1.size(); i++) {
		for (int j = 0; j < list2.size(); j++) {
			if (list2[j] < list1[i]) {
				//cout << "Deleting " << list2[j] << endl;
				list2.erase(list2.begin() + j, list2.begin() + j + 1);
				j--;
			}
			else if (list2[j] == list1[i]) {
				//cout << "Adding " << list2[j] << endl;
				total += list2[j];
			}
			else {
				break;
			}
		}
	}

	cout << total << endl;

	// Close the file
	MyReadFile.close();
}
