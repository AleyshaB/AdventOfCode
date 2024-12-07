#include "Day7.h"

void Day7::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	//RunScript("TestData/2024/Day7Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	RunScript("TestData/2024/Day7Real.txt");
}

void Day7::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	long long total = 0;
	while (getline(MyReadFile, myText)) {
		long long testValue = helperFunctions.getUIntFromString(myText);
		myText.erase(0, 1);

		vector<int> nums;
		while (myText.size() > 0) {
			nums.push_back(helperFunctions.getIntFromString(myText));
		}

		vector<int> operators;
		operators.resize(nums.size() - 1, 0);
		while (true) {
			long long sum = Calculate(nums, operators);

			if (sum == testValue) {
				cout << total << " + " << testValue << endl;
				total += testValue;
				break;
			}

			bool finished = true;
			for (int i = 0; i < operators.size(); i++) {
				if (operators[i] != 2) {
					finished = false;
					break;
				}
			}

			if (finished) {
				break;
			}

			for (int i = operators.size() - 1; i > -1; i--) {
				operators[i]++;
				operators[i] = operators[i] == 3 ? 0 : operators[i];
				if (operators[i] != 0) {
					break;
				}
			}

			
		}
	}

	cout << total << endl;

	// Close the file
	MyReadFile.close();
}

long long Day7::Calculate(vector<int> nums, vector<int> operators)
{
	long long sum = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		if (operators[i - 1] == 0) {
			sum += nums[i];
		}
		else if (operators[i - 1] == 1) {
			sum *= nums[i];
		}
		else if (operators[i - 1] == 2) {
			string string1 = std::to_string(sum);
			string string2 = std::to_string(nums[i]);
			string result = string1 + string2;
			sum = std::stoll(result);
		}
	}

	return sum;
}
