#include "Day3.h"

void Day3::run()
{
	cout << "Test Data: " << endl;
	RunScript("TestData/2025/Day3Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2025/Day3Real.txt");
}

void Day3::RunScript(string filename)
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