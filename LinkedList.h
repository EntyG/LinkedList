#pragma once
#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

struct linkedList
{
	Node* pHead;
	Node* pTail;
};

//add 1 node to the rightmost
void addLast(linkedList* l, int data);

//add 1 node has data x right behind of the node has data k
void insertXAfterK(Node* pHead, int x, int k);

//add 1 node has data x right in front of the node has data k
void insertXBeforeK(Node*& pHead, int x, int k);

//print all data of the list from left to right
void printList(linkedList* l);

//remove the first node has data of x
void removeFirstX(Node*& pHead, int x);

//remove aff the nodes has data of x
void removeX(Node*& pHead, int x);

//reverse
void reverse(Node*& pHead);

//sort ascending
void sortList(Node* pHead);

//return the pointer to the first node has data of x
Node* findX(Node* pHead, int x);

//merge 2 order list to the res list
void mergeList(Node* pHead1, Node* pHead2, linkedList*& res);

//like it's name
void deleteList(linkedList* l);