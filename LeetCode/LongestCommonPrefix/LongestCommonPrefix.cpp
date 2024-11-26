//
//  LongestCommonPrefix.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 12.11.2024.
//

//
//	Write a function to find the longest common prefix string amongst an array of strings.
//	If there is no common prefix, return an empty string "".
//
//	Time Complexity: O(n * L)
//	Space Complexity: O(1)
//

#include "LongestCommonPrefix.hpp"
#include "iostream"
#include "vector"

using namespace std;

string longestCommonPrefix(vector<string> &words) {
	if (words.empty()) {
		return "";
	}

	// Check the letter for begining one by one
	for (int i = 0; i < words[0].size(); ++i) {
		char currentChar = words[0][i];

		// Check if the letter exist in all another words at specific position
		for (int j = 1; j < words.size(); ++j) {
			if (i >= words[j].size() || words[j][i] != currentChar) {
				return words[0].substr(0, i);
			}
		}
	}

	return words[0];
}

void displayLongestCommonPrefix() {
    vector<string> words = {"flower", "flow", "flight"};

	cout << "Words: ";
	for (string word : words) {
		cout << word << " ";
	}

    cout << "\nLongest Common Prefix: " << longestCommonPrefix(words) << endl;
}
