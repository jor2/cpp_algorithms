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

int main() {
	std::cout << "Method 1 : \n";
	Node * head = nullptr;
	for ( int i = 0; i < 10; ++i ) {
		insert(head, random_number(1,7));
	}
	printList(head);
	deleteNode(head, 2);
	printList(head);
	return 0;
}
