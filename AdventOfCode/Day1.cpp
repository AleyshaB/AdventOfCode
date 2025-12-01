#include "Day1.h"

void Day1::run()
{
	cout << "Test Data: " << endl;
	RunScript("TestData/2025/Day1Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2025/Day1Real.txt");
}

void Day1::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	int num = 50;
	int numZero = 0;
	while (getline(MyReadFile, myText)) {
		char c = myText[0];
		myText.erase(0, 1);
		int index = stoi(myText);
		if (c == 'L') {
			num -= index;
			while (num < 0) {
				num += 100;
				numZero++;
			}
		}
		else {
			num += index;
			while (num > 99) {
				num -= 100;
				numZero++;
			}
		}
		cout << "num = "<< num << " - num zero = " << numZero << endl;
	}

	cout << "Num Zero = " << numZero << endl;

	// Close the file
	MyReadFile.close();
}