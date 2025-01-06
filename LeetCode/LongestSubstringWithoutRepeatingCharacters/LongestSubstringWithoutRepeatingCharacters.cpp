//
//  LongestSubstringWithoutRepeatingCharacters.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 06.01.2025.
//

//
//	Given a string s, find the length of the longest substring without repeating characters.
//
//	Time Complexity: O(n)
//	Space Complexity: O(1)
//

#include "LongestSubstringWithoutRepeatingCharacters.hpp"
#include "iostream"

using namespace std;

int lengthOfLongestSubstring(string s){
	if (s.empty()) {
		return 0;
	}

	int maxLength = 0;

	vector<int> lastSeen(256, -1);
	int left = 0;
	int right = 0;

	while (right < s.length()) {
		if (lastSeen[s[right]] != -1) {
			left = max(left, lastSeen[s[right]] + 1);
		}

		maxLength = max(maxLength, right - left + 1);
		lastSeen[s[right]] = right;
		++right;
	}

	return maxLength;
}

void displayLengthOfLongestSubstring(){
	string word = "pwwkew";
	int result = lengthOfLongestSubstring(word);
	cout << "Result: " << result << endl;
}
