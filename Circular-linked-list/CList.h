#pragma once

template<typename T>
class CList
{
public:
	struct Node
	{
		T data;
		Node* next;

		Node();
		~Node();
	}

	Node<T>* head;
	Node<T>* tail;
};

