#include "Dat'sLinkedList.h"

template<typename T> list<T>::list() {
	pHead = pTail = nullptr;
	size = 0;
}

template<typename T> list<T>::~list() {
	while (pHead) {
		Node* cur = pHead->pNext;
		delete pHead;
		pHead = cur;
	}
}

template<typename T> void list<T>::push_back(T data) {
	if (!pTail) {
		pHead = new Node;
		pHead->data = data;
		pTail = pHead;
		size++;
	}
	else {
		Node* cur = pTail;
		pTail = new Node(data, nullptr, cur);
		cur->pNext = pTail;
		size++;
	}
}

template<typename T> void list<T>::pop_back() {
	if (!pTail) {
		throw invalid_argument("cannot pop_back if the list is empty");
		return;
	}
	else {
		Node* cur = pTail->pPrev;
		if (!cur) {
			size = 0;
			pHead = nullptr;
			delete pTail;
		}
		else {
			size--;
			delete pTail;
			pTail = cur;
		}
	}
}

template<typename T> T list<T>::back() {
	if (!pTail) throw invalid_argument("access reading violation");
	return pTail->data;
}

template<typename T> void list<T>::push_front(T data) {
	if (!pHead) {
		pHead = new Node(data, nullptr, nullptr);
		pTail = pHead;
		size++;
	}
	else {
		Node* cur = pHead;
		pHead = new Node(data, cur, nullptr);
		cur->pPrev = pHead;
		size++;
	}
}

template<typename T> void list<T>::pop_front() {
	if (!pHead) {
		throw invalid_argument("cannot pop_front if the list is empty");
		return;
	}
	Node* cur = pHead->pNext;
	if (!cur) {
		size = 0;
		pTail = nullptr;
		delete pHead;
	}
	else {
		delete pHead;
		pHead = cur;
		size--;
	}
}

template<typename T> T list<T>::front() {
	if (!pHead) throw invalid_argument("access reading violation");
	return pHead->data;
}

template<typename T> void list<T>::insert(T data, int index) {
	Node* cur = pHead;
	if (index >= size) {
		throw invalid_argument("index is bigger than the size of list!!!");
		return;
	}
	while (index--) {
		cur = cur->pNext;
	}
	Node* tmp = cur;
	tmp = new Node(data, cur, cur->pPrev);
	tmp->pPrev->pNext = tmp;
	tmp->pNext->pPrev = tmp;
	size++;
}

template<typename T> void list<T>::insert(T data, T identifier, bool before) {
	Node* cur = pHead;
	while (cur) {
		if (cur->data == identifier) break;
		else {
			cur = cur->pNext;
		}
	}
	if (!cur) { // not found the identifier
		throw invalid_argument("not found the identifier");
	}
	Node* tmp = cur;
	tmp = new Node(data, cur, cur->pPrev);
	tmp->pPrev->pNext = tmp;
	tmp->pNext->pPrev = tmp;
	size++;
}

template<typename T> T list<T>::at(int index) {
	Node* cur = pHead;
	if (index >= size) {
		throw invalid_argument("index is bigger than the size of list!!!");
	}
	while (index--) {
		cur = cur->pNext;
	}
	return (cur->data);
}

template<typename T> int list<T>::length() {
	return size;
}