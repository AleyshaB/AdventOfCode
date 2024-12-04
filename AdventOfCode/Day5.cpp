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

	while (getline(MyReadFile, myText)) {
		cout << myText << endl;
	}

	// Close the file
	MyReadFile.close();
}