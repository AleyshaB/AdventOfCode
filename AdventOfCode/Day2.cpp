#include "Day2.h"

void Day2::run()
{
	cout << "Test Data: " << endl;
	RunScript("TestData/2025/Day1Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2025/Day1Real.txt");
}

void Day2::RunScript(string filename)
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