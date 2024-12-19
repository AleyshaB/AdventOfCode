#include "Day20.h"

void Day20::run()
{
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day20Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day20Real.txt");
}

void Day20::RunScript(string filename)
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