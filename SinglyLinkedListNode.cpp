// SinglyLinkedListNode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode* next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode* head;
	SinglyLinkedListNode* tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
		}

		this->tail = node;
	}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
	while (node) {
		cout << node->data;

		node = node->next;

		if (node) {
			cout << sep;
		}
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
	while (node) {
		SinglyLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode*, SinglyLinkedListNode*);

int main()
{
	vector<int> v1{ 1, 3, 7 };
	vector<int> v2{ 1, 2 };
	SinglyLinkedList s1;
	SinglyLinkedList s2;

	for (int i : v1)
	{
		s1.insert_node(i);
	}

	for (int i : v2)
	{
		s2.insert_node(i);
	}

	print_singly_linked_list(s1.head, ", ");
	cout << endl;
	print_singly_linked_list(s2.head, ", ");
	cout << endl;

	print_singly_linked_list(mergeLists(s1.head, s2.head), ", ");
	cout << endl;

	return EXIT_SUCCESS;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2)
{
	SinglyLinkedList retValue;
	bool end = false;

	while (!end)
	{
		if (head1 == nullptr)
		{
			while (head2 != nullptr) 
			{
				retValue.insert_node(head2->data);
				head2 = head2->next;
			}
			break;
		}

		if (head2 == nullptr)
		{
			while (head1 != nullptr)
			{
				retValue.insert_node(head1->data);
				head1 = head1->next;
			}
			break;
		}

		if (head1->data < head2->data)
		{
			retValue.insert_node(head1->data);
			head1 = head1->next;
		}
		else
		{
			retValue.insert_node(head2->data);
			head2 = head2->next;
		}
	}

	return retValue.head;
}

