#include "Day14.h"

void Day14::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day14Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day14Real.txt");
}

void Day14::RunScript(string filename)
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