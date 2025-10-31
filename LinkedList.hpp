#pragma once
#include <iostream>
using namespace std;


template <typename T>
class LinkedList {
	struct Node {
		T data;
		Node* prev;
		Node* next;
	};
	// Stores pointers to first and last nodes and count
	Node* head;
	Node* tail;
	unsigned int count;


public:
	// Behaviors
	void printForward() const {
		Node* current = head;
		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->next;
		}
		std::cout << std::endl;
	}
	void printReverse() const {
		Node* current = tail;
		while (current != nullptr) {
			std::cout << current->data << " ";
			current = current->prev;
		}
		std::cout << std::endl;
	}

	// Accessors
	[[nodiscard]] unsigned int getCount() const {
		return count;
	}
	Node* getHead() {
		return head;
	}
	const Node* getHead() const {
		return head;
	}
	Node* getTail() {
		return tail;
	}
	const Node* getTail() const {
		return tail;
	}

	// Insertion
	void addHead(const T& data) {
		if (count==0) {
			Node* newNode = new Node;
			newNode->data = data;
			newNode->prev = nullptr;
			newNode->next = nullptr;
			head = newNode;
			tail = newNode;
			count++;
			return;
		}
		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = head;
		newNode->prev = nullptr;
		Node* temp = head;
		head = newNode;
		temp->prev = newNode;
		count++;

	}
	void addTail(const T& data) {
		if (count==0) {
			Node* newNode = new Node;
			newNode->data = data;
			newNode->prev = nullptr;
			newNode->next = nullptr;
			head = newNode;
			tail = newNode;
			count++;
			return;
		}

		Node* newNode = new Node;
		newNode->data = data;
		newNode->next = nullptr;
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
		count++;
	}

	// Removal
	bool removeHead() {
		if (count==0) {
			return false;
		}
		if (head == tail) {
			delete head;
			head = nullptr;
			tail = nullptr;
		}
		Node* temp = head;
		head = temp->next;
		delete temp;
		count--;
		temp = nullptr;
		return true;
	}
	bool removeTail() {
		if (count==0) {
			return false;
		}
		Node* temp = tail;
		tail = temp->prev;
		delete temp;
		count--;
		temp = nullptr;
		return true;
	}
	void clear() {
		while (count>0) {
			removeHead();
		}
	}

	// Operators
	LinkedList<T>& operator=(LinkedList<T>&& other) noexcept {
		if (this == &other) {
			return *this;
		}
		this->count = other.count;
		delete head;
		delete tail;
		head = other.head;
		tail = other.tail;
		other.head = nullptr;
		other.tail = nullptr;

		return *this;
	}
	LinkedList<T>& operator=(const LinkedList<T>& rhs) {
		if (this == &rhs) {
			return *this;
		}
		this->count = rhs.count;
		delete head;
		delete tail;
		head = nullptr;
		tail = nullptr;

		Node* current = rhs.head;
		while (current!= nullptr) {
			addTail(current->data);
			current = current->next;
		}
		return *this;
	}

	// Construction/Destruction
	LinkedList() {
		head = nullptr;
		tail = nullptr;
		count = 0;
	}
	LinkedList(const LinkedList<T>& list) {
		this->count = list.count;
		head = nullptr;
		tail = nullptr;

		Node* current = list.head;
		while (current != nullptr) {
			this->addTail(current->data);
			current = current->next;
		}
	}
	LinkedList(LinkedList<T>&& other) noexcept {
		head = other.head;
		tail = other.tail;
		count = other.count;
		other.head = nullptr;
		other.tail = nullptr;
	}
	~LinkedList() {
		clear();
	}
};

