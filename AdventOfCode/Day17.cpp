#include "Day17.h"

void Day17::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day17Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day17Real.txt");
}

void Day17::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	getline(MyReadFile, myText);
	getline(MyReadFile, myText);
	getline(MyReadFile, myText);

	getline(MyReadFile, myText);
	getline(MyReadFile, myText);
	myText.erase(myText.begin(), myText.begin() + 9);

	while (myText.size() > 0) {
		instructions.push_back(helperFunctions.getIntFromString(myText));
	}

	vector<long long> nums = run(0, 0);

	//for (int i = 0; i < nums.size(); i++) {
		vector<int> outputs = runProgram(nums[48]);

		if (outputs == instructions) {
			//cout << i << endl;
		}
	//}

	// Close the file
	MyReadFile.close();
}

vector<long long> Day17::run(long long currentValue, int depth)
{
	vector<long long> values;
	if (depth > instructions.size()) {
		return values;
	}

	long long tmp = currentValue << 3;
	for (int i = 0; i < 8; i++) {
		vector<int> tempValues = runProgram(tmp + i);
		bool found = true;
		for (int j = 0; j < depth; j++) {
			int size = tempValues.size() - 1 - j;
			if (size < 0 || tempValues[size] != instructions[instructions.size() - 1 - j]) {
				found = false;
				break;
			}
		}

		if (found) {
			if (depth + 1 == instructions.size()) {
				values.push_back(tmp + i);
			}
			vector<long long> newValues = run(tmp + i, depth + 1);

			for (int j = 0; j < newValues.size(); j++) {
				values.push_back(newValues[j]);
			}
		}
	}

	return values;
}

vector<int> Day17::runProgram(long long a)
{
	vector<int> outputs;
	long long A = a; //Lowest value is pow(8, 15)
	long long B = 0;
	long long C = 0;

	while (A != 0) {
		B = A % 8;
		B ^= 1;
		C = A / pow(2, B);
		B ^= 5;
		B ^= C;
		outputs.push_back(B % 8);
		//cout << B % 8 << ",";
		A = A / pow(2, 3);
	}
	return outputs;
}
