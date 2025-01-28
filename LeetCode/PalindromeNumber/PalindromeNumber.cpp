//
//  Palindrome.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 26.11.2024.
//

//
//	Given an integer x, return true if x is a palindrome, and false otherwise.
//
//	Time Complexity: O(n)
//	Space Complexity: O(1)
//

#include "PalindromeNumber.hpp"
#include <iostream>

using namespace std;

bool isPalindrome(int x) {
	if (x < 0 || (x % 10 == 0 && x != 0)) {
		return false;
	}

	int original = x;
	int reversed = 0;

	while (x > 0) {
		int lastDigit = x % 10;
		reversed = reversed * 10 + lastDigit;
		x /= 10;
	}

	return original == reversed;
}

void displayIsPalindrome() {
    int x = 4554;
	bool result = isPalindrome(x);
    cout << result << endl;
}
