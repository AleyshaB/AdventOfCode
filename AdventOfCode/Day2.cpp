#include "Day2.h"

void Day2::run()
{
	cout << "Test Data: " << endl;
	RunScript("TestData/2025/Day2Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2025/Day2Real.txt");
}

void Day2::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);
	
	uint64_t invalid = 0;
	while (getline(MyReadFile, myText)) {
		while (myText.size() > 0) {
			uint64_t  ind1 = helperFunctions.getUIntFromString(myText, true);
			uint64_t ind2 = helperFunctions.getUIntFromString(myText, true);

			cout << "Checking range: " << ind1 << "," << ind2 << endl;
			for (uint64_t i = ind1; i <= ind2; i++) {
				string s = to_string(i);
				//cout << i << ": ";
				uint64_t divisible = 1;
				while (s.size() / 2 >= divisible) {
					if (s.size() % divisible == 0) {
						uint64_t div = s.size() / divisible;
						int numInvalid = 0;
						for (int x = 0; x < div - 1; x++) {
							string s1 = s.substr(s.size() / div * x , s.size() / div);
							string s2 = s.substr(s.size() / div * (x + 1), s.size() / div);

							if (s1 == s2) {
								numInvalid++;
							}
						}
						if (numInvalid == div - 1) {
							invalid += i;
							//cout << "Invalid number: " << i << endl;
							break;
						}
					}
					divisible++;
				}
			}
		}
	}
	cout << "invalid = " << invalid;

	// Close the file
	MyReadFile.close();
}