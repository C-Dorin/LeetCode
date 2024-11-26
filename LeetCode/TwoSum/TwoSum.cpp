//
//  TwoSum.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 13.11.2024.
//

//
//	Given an array of integers nums and an integer target, return indices of the two numbers
//	such that they add up to target. You may assume that each input would have exactly one solution,
//	and you may not use the same element twice.
//	You can return the answer in any order.
//
//	Time Complexity: O(n)
//	Space Complexity: O(n)
//

#include "TwoSum.hpp"
#include "iostream"
#include "vector"
#include "unordered_map"

using namespace std;

vector <int> twoSum(vector<int> &nums, int target) {
	unordered_map<int, int> num_map;

	for (int i = 0; i < nums.size(); ++i) {
		int complement = target - nums[i];

		if (num_map.find(complement) != num_map.end()) {
			return {num_map[complement], i};
		}
		num_map[nums[i]] = i;
	}

	return {};
}

void displayTwoSum() {
    vector<int> nums = {2, 11, 7, 15};
    int target = 9;

    vector<int> result = twoSum(nums, target);

	// Display the result
	cout << "The positions from array: ";
    for (auto nr : result) {
        cout << nr << " ";
    }
    cout << endl;
}
