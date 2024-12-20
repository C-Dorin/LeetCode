//
//  AddTwoNumbers.cpp
//  LeetCode
//
//  Created by Dorin Curnic on 26.11.2024.
//

//
//	You are given two non-empty linked lists representing two non-negative integers. The digits are stored
//	in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the
//	sum as a linked list.
//
//	You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//	Time Complexity: O(n)
//	Space Complexity: O(n)
//

#include "AddTwoNumbers.hpp"
#include "iostream"

using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Function to insert a node at the end of the list
void insertNodeAddTwoNumbers(ListNode*& head, int value) {
	// Create a new node with the provided value
	ListNode* newNode = new ListNode{value, nullptr};

	// If the list is empty, the new node becomes the head
	if (head == nullptr) {
		head = newNode;
		return;
	}

	// Traverse to the end of the list
	ListNode* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}

	// Link the new node at the end
	temp->next = newNode;
}

// Function to display the entire linked list
void displayNodeAddTwoNumbers(ListNode* head) {
	// If the list is empty
	if (head == nullptr) {
		cerr << "The list is empty." << endl;
		return;
	}

	// Traverse the list and display each node's data
	ListNode* temp = head;
	while (temp != nullptr) {
		cout << temp->val << " -> ";
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode* l3 = new ListNode(0);
	ListNode* current = l3;
	int carry = 0;

	while (l1 != nullptr || l2 != nullptr || carry != 0) {
		int val1 = (l1 != nullptr) ? l1->val : 0;
		int val2 = (l2 != nullptr) ? l2->val : 0;
		int sum = val1 + val2 + carry;

		carry = sum / 10;
		int digit = sum % 10;

		current->next = new ListNode(digit);
		current = current->next;

		if(l1 != nullptr) l1 = l1->next;
		if(l2 != nullptr) l2 = l2->next;
	}

	return l3->next;
}

void displayAddTwoNumbers() {
	ListNode* l1 = nullptr;
	ListNode* l2 = nullptr;

	insertNodeAddTwoNumbers(l1, 2);
	insertNodeAddTwoNumbers(l1, 4);
	insertNodeAddTwoNumbers(l1, 3);

	insertNodeAddTwoNumbers(l2, 5);
	insertNodeAddTwoNumbers(l2, 6);
	insertNodeAddTwoNumbers(l2, 4);

	ListNode* l3 = addTwoNumbers(l1, l2);

	displayNodeAddTwoNumbers(l3);
}
