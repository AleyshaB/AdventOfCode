#include "Day13.h"
#include <iomanip>

void Day13::run()
{
	// Read from the text file
	cout << "Test Data: " << endl;
	RunScript("TestData/2024/Day13Test.txt");
	cout << "\n\n\n\n\nRealData:" << endl;
	//RunScript("TestData/2024/Day13Real.txt");
}

void Day13::RunScript(string filename)
{
	// Create a text string, which is used to output the text file
	string myText;

	ifstream MyReadFile(filename);

	vector<pair<long long, long long>> A;
	vector<pair<long long, long long>> B;
	vector<pair<long long, long long>> prize;

	int selection = 0;
	long long num1 = 0;
	long long num2 = 0;
	while (getline(MyReadFile, myText)) {
		if (selection == 3) {
			selection = 0;
			continue;
		}

		myText.erase(myText.begin(), myText.begin() + 7);
		switch (selection) {
		case 0:
			myText.erase(myText.begin(), myText.begin() + 5);
			num1 = helperFunctions.getIntFromString(myText);

			myText.erase(myText.begin(), myText.begin() + 3);
			num2 = helperFunctions.getIntFromString(myText);

			A.push_back(pair<long long, long long>(num1, num2));

			break;
		case 1:
			myText.erase(myText.begin(), myText.begin() + 5);
			num1 = helperFunctions.getIntFromString(myText);

			myText.erase(myText.begin(), myText.begin() + 3);
			num2 = helperFunctions.getIntFromString(myText);

			B.push_back(pair<long long, long long>(num1, num2));

			break;
		case 2:
			myText.erase(myText.begin(), myText.begin() + 2);
			num1 = helperFunctions.getIntFromString(myText) +10000000000000;

			myText.erase(myText.begin(), myText.begin() + 3);
			num2 = helperFunctions.getIntFromString(myText) +10000000000000;

			prize.push_back(pair<long long, long long>(num1, num2));
		}

		selection++;
	}

	long long total = 0;
	for (int i = 0; i < A.size(); i++) {
		long double slopeX =  (-(long double)B[i].first) / (long double)A[i].first; //get m 
		cout << "Slope X = " << slopeX << endl;
		long double slopeY = (-(long double)B[i].second) / (long double)A[i].second; // get m
		cout << "Slope Y = " << slopeY << endl;

		long double interceptX = (long double)prize[i].first / (long double)A[i].first; //get where intercepts with prize line.
		long double interceptY = (long double)prize[i].second / (long double)A[i].second;
		cout << "Intercept X = " << interceptX << endl;
		cout << "Intercept Y = " << interceptY << endl;

		long double moveB = (interceptY - interceptX) / (slopeX - slopeY); //num move B
		long double moveA = (slopeY * moveB) + interceptY; //num move A

		cout << "Move X = " << moveA << endl;
		cout << "Move Y = " << moveB << endl;

		const long double EPSILON = std::pow(10, -8);
		if (std::abs(moveB - std::llround(moveB)) > EPSILON || std::abs(moveA - std::llround(moveB)) > EPSILON) {
			continue;
		}
		
		//This is broken because of floating point precision which is Fun so I did this in an excel sheet.
		total += moveA * 3 + moveB;
	}

	cout << total << endl;

	// Close the file
	MyReadFile.close();
}