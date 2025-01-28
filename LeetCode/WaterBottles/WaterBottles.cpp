//
//  WaterBottles.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 22.01.2025.
//

//
//	Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it.
//	That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].
//	Return the answer in an array.
//
//	Time Complexity: O(logn)
//	Space Complexity: O(1)
//

#include "WaterBottles.hpp"
#include <iostream>

using namespace std;

int numWaterBottles(int numBottles, int numExchange) {
	int result = numBottles;

	while (numBottles >= numExchange) {
		int groups = numBottles / numExchange;
		numBottles = groups + numBottles % numExchange;
		result += groups;
	}
	
	return result;
}

void displayNumWaterBottles() {
	int numBottles = 9;
	int numExchange = 3;
	int result = numWaterBottles(numBottles, numExchange);
	cout << "Result: " << result << endl;
}

