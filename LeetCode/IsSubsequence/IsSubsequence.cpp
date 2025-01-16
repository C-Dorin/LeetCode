//
//  IsSubsequence.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 16.01.2025.
//

//
//	Given two strings s and t, return true if s is a subsequence of t, or false otherwise.
//
//	A subsequence of a string is a new string that is formed from the original string by deleting
//	some (can be none) of the characters without disturbing the relative positions of the remaining
//	characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).
//
//	Time Complexity: O(n)
//	Space Complexity: O(1)
//

#include "IsSubsequence.hpp"
#include "iostream"
#include "string"

using namespace std;

bool isSubsequence(string s, string t) {
	int position = 0;

	for (char c : t) {
		if (s[position] == c) {
			++position;
		}
	}

	return position == s.size();
}

void displayIsSubsequence() {
	string s = "ace";
	string t = "abcde";
	bool result = isSubsequence(s, t);
	cout << "Result: " << result << endl;
}
