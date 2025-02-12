//
//  DesignCircularDeque.hpp
//  LeetCode
//
//  Created by Dorin Curnic on 10.02.2025.
//

#ifndef DesignCircularDeque_hpp
#define DesignCircularDeque_hpp

#include <vector>

class MyCircularDeque {
private:
	std::vector<int> deque;
	int front, rear, size, capacity;
public:
	MyCircularDeque(int k);

	bool insertFrontMyCircularDeque(int value);
	bool insertLastMyCircularDeque(int value);
	bool deleteFrontMyCircularDeque();
	bool deleteLastMyCircularDeque();
	int getFrontMyCircularDeque();
	int getRearMyCircularDeque();
	bool isEmptyMyCircularDeque();
	bool isFullMyCircularDeque();
};

void displayMyCircularDeque();

#endif /* DesignCircularDeque_hpp */
