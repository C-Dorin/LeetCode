//
//  TheTwoSneakyNumbersOfDigitville.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 28.01.2025.
//

//
//	In the town of Digitville, there was a list of numbers called nums containing integers from 0 to n - 1.
//	Each number was supposed to appear exactly once in the list, however, two mischievous numbers sneaked in
//	an additional time, making the list longer than usual.
//	As the town detective, your task is to find these two sneaky numbers. Return an array of size two containing
//	the two numbers (in any order), so peace can return to Digitville.
//
//	Time Complexity: O(n)
//	Space Complexity: O(1)
//

#include "TheTwoSneakyNumbersOfDigitville.hpp"
#include <iostream>
#include <vector>

using namespace std;

vector<int> getSneakyNumbers(vector<int>& nums) {
	constexpr int kMax = 100; // constant expression - evaluated at compile time, rather than at runtime.
	vector<int> result;
	int count[kMax] = {0};

	for (int num : nums) {
		if (++count[num] == 2) {
			result.push_back(num);
		}
	}

	return result;
}

void displayGetSneakyNumbers() {
	vector<int> nums = {7,1,5,4,3,4,6,0,9,5,8,2};
	vector<int> result = getSneakyNumbers(nums);
	cout << "Result: [";
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i];
		if (i < result.size() - 1) {
			cout << ", ";
		}
	}
	cout << "]." << endl;
}
