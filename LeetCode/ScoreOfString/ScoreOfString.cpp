//
//  ScoreOfString.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 13.01.2025.
//

//
//	You are given a string s. The score of a string is defined as the sum of the
//	absolute difference between the ASCII values of adjacent characters.
//	Return the score of s.
//
//	Time Complexity: O(n)
//	Space Complexity: O(1)
//

#include "ScoreOfString.hpp"
#include "iostream"

using namespace std;

int scoreOfString(string s) {
	int result = 0;

	for (int i = 1; i < s.length(); ++i) {
		result += abs(s[i] - s[i - 1]);
	}

	return result;
}

void displayScoreOfString() {
	string word = "hello";
	int result = scoreOfString(word);
	cout << "Result: " << result << endl;
}
