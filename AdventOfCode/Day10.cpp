#include "Day10.h"

void Day10::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day10Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day10Real.txt");
}

void Day10::RunScript(string filename)
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