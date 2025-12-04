#include "Day6.h"

void Day6::run()
{
	cout << "Test Data: " << endl;
	RunScript("TestData/2025/Day6Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2025/Day6Real.txt");
}

void Day6::RunScript(string filename)
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