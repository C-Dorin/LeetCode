//
//  ValidParantheses.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 26.11.2024.
//

//
//	Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
//	determine if the input string is valid.
//
//	An input string is valid if:
//		1. Open brackets must be closed by the same type of brackets.
//		2. Open brackets must be closed in the correct order.
//		3. Every close bracket has a corresponding open bracket of the same type.
//
//	Time Complexity: O(n)
//	Space Complexity: O(n)
//

#include "ValidParantheses.hpp"
#include "iostream"
#include "stack"

using namespace std;

bool isValid(string s) {
	stack<char> paranthesesStack;

	for (char c : s) {
		if (c == '(' || c == '[' || c == '{') {
			paranthesesStack.push(c);
		} else {
			if (paranthesesStack.empty() ||
				(c == ')' && paranthesesStack.top() == '(') ||
				(c == ']' && paranthesesStack.top() == '[') ||
				(c == '}' && paranthesesStack.top() == '{')) {
				return false;
			}
			paranthesesStack.pop();
		}
	}

	return paranthesesStack.empty();
};

void displayIsValid() {
    string s = "(){}([)]";
    bool result = isValid(s);
	cout << result << endl;
}
