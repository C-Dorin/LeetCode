//
//  HowManyNumbersAreSmallerThanTheCurrentNumber.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 20.01.2025.
//

//
//	Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.
//	That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
//	Return the answer in an array.
//
//	Time Complexity: O(nlogn)
//	Space Complexity: O(n)
//

#include "HowManyNumbersAreSmallerThanTheCurrentNumber.hpp"
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
	vector<int> sorted_nums = nums;
	sort(sorted_nums.begin(), sorted_nums.end());

	unordered_map<int, int> number_index_map;
	for (int i = 0; i < sorted_nums.size(); ++i) {
		if (number_index_map.find(sorted_nums[i]) == number_index_map.end()) {
			number_index_map[sorted_nums[i]] = i;
		}
	}

	vector<int> result;
	for (int num : nums) {
		result.push_back(number_index_map[num]);
	}

	return result;
}

void displaySmallerNumbersThanCurrent() {
	vector<int> nums = {8,1,2,2,3};
	vector<int> result = smallerNumbersThanCurrent(nums);
	cout << "Result: [";
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i];
		if (i < result.size() - 1) {
			cout << ", ";
		}
	}
	cout << "]." << endl;
}
