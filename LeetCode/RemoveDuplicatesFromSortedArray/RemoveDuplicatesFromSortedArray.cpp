//
//  RemoveDuplicatesFromSortedArray.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 26.11.2024.
//

//
//	Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that
//	each unique element appears only once. The relative order of the elements should be kept the same.
//	Then return the number of unique elements in nums.
//
//	Consider the number of unique elements of nums to be k, to get accepted, you need to do
//	the following things:
//		1. Change the array nums such that the first k elements of nums contain the unique elements in
//		the order they were present in nums initially. The remaining elements of nums are not important
//		as well as the size of nums.
//		2. Return k.
//
//	Time Complexity: O(n)
//	Space Complexity: O(1)
//

#include "RemoveDuplicatesFromSortedArray.hpp"
#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	int k = 1;

	for (int i = 1; i < nums.size(); ++i) {
		if (nums[i-1] != nums[i]) {
			nums[k] = nums[i];
			++k;
		}
	}

    return k;
}

void displayRemoveDuplicates() {
    vector<int> nums = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
	int result = removeDuplicates(nums);
	cout << result << endl;
}
