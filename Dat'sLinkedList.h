#pragma once
#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

template<typename T> class list {
	struct Node {
		T data;
		Node* pNext;
		Node* pPrev;
		Node() {
			pPrev = pNext = nullptr;
		}
		Node(T data, Node* pNext, Node* pPrev) {
			this->data = data;
			this->pNext = pNext;
			this->pPrev = pPrev;
		}
	};
private:
	int size;
	Node* pHead;
	Node* pTail;
public:
	// constructor
	list();

	// destructor
	~list();

	// create a new node to the end of the linked list and assign data to this node
	void push_back(T data);

	// create a new node to the front of the linked list and assign data to this node
	void push_front(T data);

	// delete the rightmost node.
	void pop_back();

	// delete the leftmost node.
	void pop_front();

	// returns the leftmost node.
	T front();

	// return the rightmost node.
	T back();

	// insert data to the index
	// note: the list starts with index 0.
	void insert(T data, int index);

	// insert data before this identifier
	void insert(T data, T identifier, bool before);

	// return T at the index
	// note: the list starts with index 0.
	T at(int index);

	// return the size of the list
	int length();
};