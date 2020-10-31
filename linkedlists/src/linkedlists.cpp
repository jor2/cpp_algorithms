//============================================================================
// Name        : linkedlists.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <unordered_map>
#include <random>
using namespace std;

struct Node {
	int data = 0;
	Node * next = nullptr;
};


void insert(Node*& head, int data) {
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = head;
	head = newNode;
}


Node* deleteNode(Node*& head, int data) {
	Node* n = head;

	if(n->data == data) {
		std::cout << "Removing head node: "  << data << "\n";
		return head->next;
	}

	while (n->next != nullptr) {
		if(n->data == data) {
			n->next = n->next->next;
			std::cout << "Removing node: "  << data << "\n";
			return head;
		}
		n = n->next;
	}
	return head;
}


void deleteDuplicatesNode(Node*& head) {
	if (head == nullptr || head->next == nullptr) {
			return;
	}

	Node* curr = head;

	while(curr) {
		Node* runner = curr;
		while (runner->next != nullptr) {
			if(runner->next->data == curr->data) {
				runner->next = runner->next->next;
				std::cout << "Removing node: "  << runner->data << "\n";
			}
			else {
				runner = runner->next;
			}
		}
		curr = curr->next;
	}
}


int random_number(int min, int max) {
	std::random_device rd;
	std::mt19937 mt(rd());
	std::uniform_int_distribution<int> distribution(min, max);
	return distribution(mt);}


void printList(Node* head) {
	while(head) {
		std::cout << head->data << "\n";
		head = head->next;
	}
	std::cout << "nullptr" << std::endl;
}



int getSizeOfLinkedList(Node*& head) {
	Node* n = head;
	int sizeOfLinkedList = 0;
	while(n->next != nullptr) {
		sizeOfLinkedList++;
		n = n->next;
	}
	return sizeOfLinkedList;
}



void kthToLastElement(Node* head, int k) {
	Node* n = head;
	int elementToFetch = getSizeOfLinkedList(head) - k;
	for(int i=0; i<=getSizeOfLinkedList(head); i++) {
		if(i == elementToFetch) {
			std::cout << n->data << std::endl;
		}
		n = n->next;
	}
}


void deleteMiddleNode(Node*& head) {
	if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
			return;
	}

	int sizeOfList = getSizeOfLinkedList(head);

	int halfway = (int)sizeOfList / 2;

	Node* n1 = head;
	Node* n2 = head->next;
	for(int i=0; i<=sizeOfList; i++) {
		if(i == halfway-1) {
			std::cout << "Deleting: " << n2->data << std::endl;
			n1->next = n2->next;
			break;
		}
		n1 = n1->next;
		n2 = n2->next;
	}
}


int main() {
	std::cout << "Method Insert : \n";
	Node * head = nullptr;
	for ( int i = 0; i < 10; ++i ) {
		insert(head, random_number(1,7));
	}

	std::cout << "\nMethod Print : \n";
	printList(head);

	std::cout << "\nMethod Delete : \n";
	deleteNode(head, 2);

	std::cout << "\nMethod Print : \n";
	printList(head);

	std::cout << "\nMethod Delete Dupes : \n";
	deleteDuplicatesNode(head);

	std::cout << "\nMethod Print : \n";
	printList(head);

	std::cout << "\nMethod kthToLastElement : \n";
	kthToLastElement(head, 4);
	deleteDuplicatesNode(head);

	std::cout << "\nMethod Print : \n";
	printList(head);

	std::cout << "\nMethod deleteMiddleNode : \n";
	deleteMiddleNode(head);

	std::cout << "\nMethod Print : \n";
	printList(head);

	return 0;
}
