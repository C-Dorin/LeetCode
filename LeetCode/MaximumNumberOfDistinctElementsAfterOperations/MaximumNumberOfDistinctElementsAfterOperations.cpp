//
//  MaximumNumberOfDistinctElementsAfterOperations.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 17.01.2025.
//

//
//	You are given an integer array nums and an integer k.
//	You are allowed to perform the following operation on each element of the array at most once:
//		· Add an integer in the range [-k, k] to the element.
//	Return the maximum possible number of distinct elements in nums after performing the operations.
//
//	Time Complexity: O(nlogn)
//	Space Complexity: O(1)
//

#include "MaximumNumberOfDistinctElementsAfterOperations.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int maxDistinctElements(vector<int>& nums, int k) {
	int distinctCount = 0;
	int previous = INT_MIN;
	sort(nums.begin(), nums.end());

	for (int number : nums) {
		int current = min(number + k, max(number - k, previous + 1));

		if (current > previous) {
			++distinctCount;
			previous = current;
		}
	}

	return distinctCount;
};

void displayMaxDistinctElements() {
	vector<int> nums = {1, 2, 2, 3, 3, 4};
	int k = 2;
	int result = maxDistinctElements(nums, k);
	cout << "Result: " << result << endl;
};
