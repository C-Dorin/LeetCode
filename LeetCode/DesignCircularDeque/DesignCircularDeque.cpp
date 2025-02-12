//
//  DesignCircularDeque.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 10.02.2025.
//

//
//	Design your implementation of the circular double-ended queue (deque).
//	Implement the MyCircularDeque class:
//	- MyCircularDeque(int k) Initializes the deque with a maximum size of k.
//	- boolean insertFront() Adds an item at the front of Deque. Returns true if the operation is successful,
//		or false otherwise.
//	- boolean insertLast() Adds an item at the rear of Deque. Returns true if the operation is successful,
//		or false otherwise.
//	- boolean deleteFront() Deletes an item from the front of Deque. Returns true if the operation is successful,
//		or false otherwise.
//	- boolean deleteLast() Deletes an item from the rear of Deque. Returns true if the operation is successful,
//		or false otherwise.
//	- int getFront() Returns the front item from the Deque. Returns -1 if the deque is empty.
//	- int getRear() Returns the last item from Deque. Returns -1 if the deque is empty.
//	- boolean isEmpty() Returns true if the deque is empty, or false otherwise.
//	- boolean isFull() Returns true if the deque is full, or false otherwise.
//
//	Time Complexity: O(1)
//	Space Complexity: O(n)
//

//
//	Your MyCircularDeque object will be instantiated and called as such:
//	MyCircularDeque* obj = new MyCircularDeque(k);
//	bool param_1 = obj->insertFront(value);
//	bool param_2 = obj->insertLast(value);
//	bool param_3 = obj->deleteFront();
//	bool param_4 = obj->deleteLast();
//	int param_5 = obj->getFront();
//	int param_6 = obj->getRear();
//	bool param_7 = obj->isEmpty();
//	bool param_8 = obj->isFull();
//

#include "DesignCircularDeque.hpp"
#include <iostream>
#include <vector>

using namespace std;

MyCircularDeque::MyCircularDeque(int k) {
	capacity = k;
	deque.resize(k);
	front = 0;
	rear = -1;
	size = 0;
}

bool MyCircularDeque::insertFrontMyCircularDeque(int value) {
	if (isFullMyCircularDeque()) return false;
	front = (front - 1 + capacity) % capacity;
	deque[front] = value;
	if (size == 0) rear = front;
	++size;
	return true;
}

bool MyCircularDeque::insertLastMyCircularDeque(int value) {
	if (isFullMyCircularDeque()) return false;
	rear = (rear + 1) % capacity;
	deque[rear] = value;
	if (size == 0) front = rear;
	++size;
	return true;
}

bool MyCircularDeque::deleteFrontMyCircularDeque() {
	if (isEmptyMyCircularDeque()) return false;
	front = (front + 1) % capacity;
	--size;
	return true;
}

bool MyCircularDeque::deleteLastMyCircularDeque() {
	if (isEmptyMyCircularDeque()) return false;
	rear = (rear - 1 + capacity) % capacity;
	--size;
	return true;
}

int MyCircularDeque::getFrontMyCircularDeque() {
	return isEmptyMyCircularDeque() ? -1 : deque[front];
}

int MyCircularDeque::getRearMyCircularDeque() {
	return isEmptyMyCircularDeque() ? -1 : deque[rear];
}

bool MyCircularDeque::isEmptyMyCircularDeque() {
	return size == 0;
}

bool MyCircularDeque::isFullMyCircularDeque() {
	return size == capacity;
}

void displayMyCircularDeque() {
	MyCircularDeque myCircularDeque(3);
	cout << "Results: " << endl;
	cout << myCircularDeque.insertLastMyCircularDeque(1) << endl;  // return True
	cout << myCircularDeque.insertLastMyCircularDeque(2) << endl;  // return True
	cout << myCircularDeque.insertFrontMyCircularDeque(3) << endl; // return True
	cout << myCircularDeque.insertFrontMyCircularDeque(4) << endl; // return False, the queue is full.
	cout << myCircularDeque.getRearMyCircularDeque() << endl;      // return 2
	cout << myCircularDeque.isFullMyCircularDeque() << endl;       // return True
	cout << myCircularDeque.deleteLastMyCircularDeque() << endl;   // return True
	cout << myCircularDeque.insertFrontMyCircularDeque(4) << endl; // return True
	cout << myCircularDeque.getFrontMyCircularDeque() << endl;     // return 4
}
