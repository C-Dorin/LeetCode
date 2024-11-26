//
//  RomanToInteger.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 12.11.2024.
//

//
//	Given a roman numeral, convert it to an integer.
//
//	Time Complexity: O(n)
//	Space Complexity: O(n)
//

#include "RomanToInteger.hpp"
#include "iostream"
#include "unordered_map"

using namespace std;

int romanToInteger(string romanNumber) {
	int sum = 0;
	unsigned long length = romanNumber.length();
	unordered_map <char, int> symbolValues {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};

	for (int i = 0; i < length; ++i) {
		int value = symbolValues[romanNumber[i]];

		if (i < length - 1 && value < symbolValues[romanNumber[i + 1]]) {
			sum -= value;
		} else {
			sum += value;
		}
	}

	return sum;
}


void displayRomanToInteger() {
    string romanNumber = "LXXIX";

	cout << romanNumber << ": " << romanToInteger(romanNumber) << endl;
}
