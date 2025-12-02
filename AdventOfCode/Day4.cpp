#include "Day4.h"

void Day4::run()
{
	cout << "Test Data: " << endl;
	RunScript("TestData/2025/Day4Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2025/Day4Real.txt");
}

void Day4::RunScript(string filename)
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