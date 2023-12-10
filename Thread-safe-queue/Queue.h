#pragma once

#include <mutex>
#include <thread>
#include <iostream>

template<typename T>
class queue
{
public:

	template<typename T>
	struct Node
	{
		T data = 0;
		Node* next = nullptr;

		Node() {};
		~Node() {};
	};

	Node<T>* head;
	Node<T>* tail;
	int queuesize;
	std::mutex mut;

	void push(T& x);
	T front();
	bool pop();
	bool empty();
	int size();
	queue();
	~queue();
};

template <typename T>
bool queue<T>::pop()
{
	std::lock_guard<std::mutex> guard(mut);

	if (this->empty())
	{
		return false;
	};

	Node<T>* temp = this->head;
	this->head = this->head->next;

	delete temp;

	this->queuesize--;

	return true;
}

template <typename T>
T queue<T>::front()
{
	std::lock_guard<std::mutex> guard(mut);

	return this->head->data;

	if (this->empty()) throw ("err front (empty queue)");
}

template <typename T>
void queue<T>::push(T& x)
{
	Node<T>* temp = new Node<T>;
	temp->data = x;

	std::lock_guard<std::mutex> guard(mut);

	if (this->head == nullptr)
	{
		this->head = temp;
		this->tail = temp;
		return;
	}

	this->tail->next = temp;
	this->tail = this->tail->next;

	this->queuesize++;
}

template <typename T>
bool queue<T>::empty()
{
	if (this->head) { return 1; }

	return 0;
}

template<typename T>
int queue<T>::size()
{
	return queuesize;
}

template <typename T>
queue<T>::queue() : head(nullptr), tail(nullptr) {}

template <typename T>
queue<T>::~queue()
{
	std::lock_guard<std::mutex> guard(mut);

	while (this->head != nullptr)
	{
		Node<T>* temp = this->head;
		this->head = this->head->next;

		delete temp;
	}
}