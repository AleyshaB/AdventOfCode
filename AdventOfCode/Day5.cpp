#include "Day5.h"

void Day5::run()
{
	std::cout << "Test Data: " << endl;
//	RunScript("TestData/2025/Day5Test.txt");
	std::cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2025/Day5Real.txt");
}

void Day5::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	vector<vector<uint64_t>> ranges;
	bool blankLine = false;
	int numFresh = 0;
	uint64_t totalIds = 0;
	while (getline(MyReadFile, myText)) {
		if (!blankLine) {
			if (myText.size() == 0) {
				blankLine = true;
			}
			else {
				bool adjustedRange = false;
				uint64_t int1 = helperFunctions.getUIntFromString(myText);
				uint64_t int2 = helperFunctions.getUIntFromString(myText);
				ranges.push_back({int1, int2});
			}
		}
		else {
			uint64_t ingredient = helperFunctions.getUIntFromString(myText);
			for (int i = 0; i < ranges.size(); i++) {
				if (ingredient >= ranges[i][0] && ingredient <= ranges[i][1]) {
					numFresh++;
					break;
				}
			}
		}
	}

	std::sort(ranges.begin(), ranges.end());

	for (int i = 0; i < ranges.size(); i++)
	{
		for (int j = i + 1; j < ranges.size(); j++)
		{
			if (ranges[i][1] >= ranges[j][0])
			{
				uint64_t largest = max(ranges[i][1], ranges[j][1]);
				ranges[i][1] = largest;
				ranges.erase(ranges.begin() + j);
				j--;
			}

		}
	}

	for (int i = 0; i < ranges.size(); i++) {
		totalIds += ranges[i][1] - ranges[i][0] + 1;
	}

	std::cout << "numFresh = " << numFresh << endl;
	std::cout << "totalIds = " << totalIds << endl;

	// Close the file
	MyReadFile.close();
}