#include "Day19.h"

void Day19::run()
{
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day19Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day19Real.txt");
}

void Day19::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	while (getline(MyReadFile, myText)) {
		cout << myText << endl;
	}

	// Close the file
	MyReadFile.close();
}