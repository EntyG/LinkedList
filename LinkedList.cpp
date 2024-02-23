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

void addLast(linkedList* l, int data)
{
	if (l->pHead == nullptr) {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		l->pHead = newNode;
		l->pTail = newNode;
	}
	else {
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		l->pTail->next = newNode;
		l->pTail = newNode;
	}
}

void insertXAfterK(Node* pHead, int x, int k)
{
	if (pHead == nullptr)
	{
		return;
	}
	Node* cur = pHead;
	while (cur->data != k)
	{
		cur = cur->next;
		if (cur == nullptr)
		{
			return;
		}
	}
	Node* X;
	X = new Node;
	X->data = x;
	X->next = cur->next;
	cur->next = X;
}

void insertXBeforeK(Node*& pHead, int x, int k)
{
	if (pHead == nullptr)
	{
		return;
	}
	if (pHead->data == k)
	{
		Node* X;
		X = new Node;
		X->data = x;
		X->next = pHead;
		pHead = X;
		return;
	}
	Node* cur = pHead;
	while (cur->next->data != k)
	{
		cur = cur->next;
		if (cur == nullptr)
		{
			return;
		}
	}
	Node* X;
	X = new Node;
	X->data = x;
	X->next = cur->next;
	cur->next = X;
}

void printList(linkedList* l)
{
	if (l->pHead == nullptr)
	{
		cout << "There is nothing in the list";
		return;
	}
	Node* cur = l->pHead;
	while (cur != nullptr)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
}

void removeFirstX(Node*& pHead, int x)
{
	if (pHead == nullptr)
	{
		return;
	}
	if (pHead->data == x)
	{
		Node* tmp = pHead;
		pHead = pHead->next;
		delete tmp;
		return;
	}
	Node* cur = pHead;
	while (cur->next->data != x)
	{
		cur = cur->next;
		if (cur->next == nullptr)
		{
			return;
		}
	}
	Node* tmp = cur->next;
	cur->next = cur->next->next;
	delete tmp;
}

void removeX(Node*& pHead, int x)
{
	if (pHead == nullptr)
	{
		return;
	}
	Node* cur = pHead;
	while (cur->next != nullptr)
	{
		if (cur->next->data == x)
		{
			Node* tmp = cur->next;
			cur->next = cur->next->next;
			delete tmp;
			continue;
		}
		cur = cur->next;
	}
	if (pHead != nullptr && pHead->data == x)
	{
		Node* tmp = pHead;
		pHead = pHead->next;
		delete tmp;
	}
}


void sort(int* a, int& n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (a[j] < a[i])
			{
				a[j] = a[i] + a[j];
				a[i] = a[j] - a[i];
				a[j] = a[j] - a[i];
			}
		}
	}
}

void reverse(Node*& pHead)
{
	Node* cur = pHead;
	if (pHead == nullptr)
	{
		return;
	}
	while (cur->next != nullptr)
	{
		Node* tmp = cur->next;
		cur->next = cur->next->next;
		tmp->next = pHead;
		pHead = tmp;
	}
}

void sortList(Node* pHead)
{
	Node* cur = pHead;
	int values[100];
	int i = 0;
	while (cur)
	{
		values[i] = cur->data;
		cur = cur->next;
		i++;
	}
	sort(values, i);
	cur = pHead;
	i = 0;
	while (cur)
	{
		cur->data = values[i];
		i++;
		cur = cur->next;
	}
}

Node* findX(Node* pHead, int x)
{
	Node* cur = pHead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else if (cur->data > x)
		{
			return nullptr;
		}
		cur = cur->next;
	}
	return nullptr;
}

void mergeList(Node* pHead1, Node* pHead2, linkedList*& res)
{
	Node* cur1, * cur2;
	cur1 = pHead1;
	cur2 = pHead2;
	while (cur1 != nullptr || cur2 != nullptr)
	{
		if (cur1 == nullptr)
		{
			addLast(res, cur2->data);
			cur2 = cur2->next;
		}
		else if (cur2 == nullptr)
		{
			addLast(res, cur1->data);
			cur1 = cur1->next;
		}
		else if (cur1->data >= cur2->data)
		{
			addLast(res, cur2->data);
			cur2 = cur2->next;
		}
		else
		{
			addLast(res, cur1->data);
			cur1 = cur1->next;
		}
	}
}

void deleteList(linkedList* l)
{
	while (l->pHead != nullptr) {
		Node* temp = l->pHead;
		l->pHead = l->pHead->next;
		delete temp;
	}
	l->pTail = nullptr;
}

int main()
{
	linkedList* list1, * list2;
	list1 = new linkedList;
	list1->pHead = nullptr;
	list1->pTail = nullptr;
	list2 = new linkedList;
	list2->pHead = nullptr;
	list2->pTail = nullptr;
	int input;
	cin >> input;
	while (input)
	{
		addLast(list1, input);
		cin >> input;
	}
	printList(list1);
	cout << endl;
	cin >> input;
	while (input)
	{
		addLast(list2, input);
		cin >> input;
	}
	printList(list2);
	cout << endl;
	linkedList* result;
	result = new linkedList;
	result->pHead = nullptr;
	result->pTail = nullptr;
	sortList(list1->pHead);
	sortList(list2->pHead);
	mergeList(list1->pHead, list2->pHead, result);
	printList(result);
	deleteList(list1);
	delete list1;
	deleteList(list2);
	delete list2;
	deleteList(result);
	delete result;
	return 0;
}