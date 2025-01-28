//
//  FindTheArrayConcatinationValue.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 14.01.2025.
//

//
//	You are given a 0-indexed integer array nums.
//	The concatenation of two numbers is the number formed by concatenating their numerals.
//		▸ For example, the concatenation of 15, 49 is 1549.
//
//	The concatenation value of nums is initially equal to 0. Perform this operation until nums becomes empty:
//		▸ If there exists more than one number in nums, pick the first element and last element in nums
//		respectively and add the value of their concatenation to the concatenation value of nums, then
//		delete the first and last element from nums.
//		▸ If one element exists, add its value to the concatenation value of nums, then delete it.
//
//	Return the concatenation value of the nums.
//
//	Time Complexity: O(n)
//	Space Complexity: O(1)
//

#include "FindTheArrayConcatinationValue.hpp"
#include <iostream>
#include <vector>

using namespace std;

long long findTheArrayConcatinationValue(vector<int>& nums) {
	int left = 0;
	unsigned long right = nums.size() - 1;
	long long result = 0;

	while (left <= right) {
		if (left == right) {
			result += nums[left];
		} else {
			int lastElement = nums[right];
			long long multiplier = 1;
			while (lastElement >= 10) {
				lastElement /= 10;
				multiplier *= 10;
			}
			result += nums[left] * multiplier * 10 + nums[right];
		}

		++left;
		--right;
	}

	return result;
}

void displayFindTheArrayConcatinationValue() {
	vector<int> nums = {7, 52, 2, 4};
	long long result = findTheArrayConcatinationValue(nums);
	cout << "Result: " << result << endl;
}
