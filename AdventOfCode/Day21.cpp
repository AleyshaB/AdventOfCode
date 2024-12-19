#include "Day21.h"

void Day21::run()
{
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day21Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day21Real.txt");
}

void Day21::RunScript(string filename)
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