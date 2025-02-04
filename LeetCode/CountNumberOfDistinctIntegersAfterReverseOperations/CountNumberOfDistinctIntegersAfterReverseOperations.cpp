//
//  CountNumberOfDistinctIntegersAfterReverseOperations.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 03.02.2025.
//

//
//	You are given an array nums consisting of positive integers.
//
//	You have to take each integer in the array, reverse its digits, and add it to the end of the array.
//	You should apply this operation to the original integers in nums.
//
//	Return the number of distinct integers in the final array.
//
//	Time Complexity: O(n)
//	Space Complexity: O(n)
//

#include "CountNumberOfDistinctIntegersAfterReverseOperations.hpp"
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int countDistinctIntegers(vector<int>& nums) {
	unordered_set<int> distinctNumbers;

	for (int num : nums) {
		distinctNumbers.insert(num);
		int reversed = 0;
		int copy = num;
		while (copy != 0) {
			int pop = copy % 10;
			copy /= 10;
			reversed = reversed * 10 + pop;
		}
		distinctNumbers.insert(reversed);
	}

	return (int)distinctNumbers.size();
}

void displayCountDistinctIntegers() {
	vector<int> nums = {1,13,10,12,31};
	int result = countDistinctIntegers(nums);
	cout << "Result: " << result << endl;
}
