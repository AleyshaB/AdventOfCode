#include "Day3.h"

void Day3::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day3Test.txt");
	cout << "\n\n\n\n\n RealData:" << endl;
	RunScript("TestData/2024/Day3Real.txt");
}

void Day3::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	uint32_t total = 0;

	bool allow = true;
	while (getline(MyReadFile, myText)) {
		for (int i = 0; i < myText.size(); i++) {
			string s = myText.substr(i, 7);
			if (s == "don't()") {
				allow = false;
				continue;
			}

			s = myText.substr(i, 4);
			if (s == "do()") {
				allow = true;
				continue;
			}

			if (!allow) {
				continue;
			}

			if (s != "mul(") {
				continue;
			}

			s = myText.substr(i + 4, 8);
			if (s[0] == ' ') {
				continue;
			}
			int num1 = helperFunctions.getIntFromString(s, false);
			
			if (s[0] != ',' || s[1] == ' ') {
				continue;
			}

			s = s.substr(1, 4);
			int num2 = helperFunctions.getIntFromString(s, false);

			if (s[0] != ')') {
				continue;
			}

			total += (num1 * num2);
		}
	}

	cout << total << endl;

	// Close the file
	MyReadFile.close();
}