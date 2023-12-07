#pragma once

#include <iostream>
#include <mutex>
#include <thread>

template<typename T>
class queue
{
	struct Node
	{
		T data;
		Node* next = nullptr;
	};

	Node* head;
	Node* tail;
	std::mutex mut;

public:

	void push(T& x);
	T front();
	void pop();
	bool empty();
	queue();
	~queue();
	
};

template <typename T>
void queue<T>::pop()
{
	std::lock_guard<std::mutex>(mut);

	if (this->empty()) throw ("err pop (empty queue)");

	Node* temp = head;
	head = head->next;

	delete temp;
}

template <typename T>
T queue<T>::front()
{
	std::lock_guard<std::mutex>(mut);

	return head->data;

	if (this->empty()) throw ("err front (empty queue)");
}

template <typename T>
void queue<T>::push(T& x)
{
	Node* temp = new Node;
	temp->data = x;

	std::lock_guard<std::mutex> guard(mut);

	if (head == nullptr)
	{
		head = temp;
		tail = temp;
		return;
	}

	tail->next = temp;
	tail = tail->next;
}

template <typename T>
bool queue<T>::empty()
{
	if (head) { return 1; }

	return 0;
}

template <typename T>
queue<T>::queue() : head(nullptr), tail(nullptr) {}

template <typename T>
queue<T>::~queue()
{
	std::lock_guard<std::mutex> guard(mut);

	while (head != nullptr)
	{
		Node* temp = head;
		head = head->next;

		delete temp;
	}
}


