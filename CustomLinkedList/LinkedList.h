#pragma once

#include <iostream>


template<typename T>
class LinkedList
{
private :

	struct Node
	{
		T m_Data;
		Node* next;
	};

	Node* head = nullptr;
	Node* node = nullptr;
	Node* newNode = nullptr;
	size_t size = 0;


public :
	class LinkedListIterator
	{
	private:
		Node* node;

	public:
		LinkedListIterator(Node* pointer)
			:node(pointer)
		{

		}

		//Prefix
		LinkedListIterator& operator++()
		{
			if (node)
				node = node->next;

			return *this;
		}

		//Postfix
		LinkedListIterator& operator++(int)
		{
			LinkedListIterator temp = *this;
			++(*this);
			return temp;
		}

		T& operator*()
		{
			return node->m_Data;
		}

		bool operator==(const LinkedListIterator& other)
		{
			return (node == other.node);
		}

		bool operator!=(const LinkedListIterator& other)
		{
			return (node != other.node);
		}

		LinkedListIterator& operator=(Node* temp)
		{
			this->node = temp;
			return *this;
		}

	};

	LinkedListIterator begin()
	{
		return LinkedListIterator(head);
	}

	LinkedListIterator end()
	{
		return LinkedListIterator(nullptr);
	}


	void Push(T data)
	{
		if (head == nullptr)
		{
			node = new Node();
			node->m_Data = data;
			head = node;
			newNode = node;
			size++;
			return;
		}
		newNode = new Node();
		newNode->m_Data = data;
		node->next = newNode;
		newNode->next = nullptr;
		node = newNode;
		size++;
		return;
	}

	void Pop()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			if (temp->next->next == nullptr)
			{
				temp->next = nullptr;
				node = temp;
				newNode = node;
				Node* del = temp->next;
				delete del;
				break;
			}
			temp = temp->next;
		}
	}

	//For Debugging
	void Display()
	{
		Node* temp = head;
		while (temp != nullptr)
		{
			std::cout << "Element : " << temp->m_Data << "\n";
			temp = temp->next;
		}
	}

	size_t Size() const
	{
		return size;
	}

	friend class Iterator;

};
