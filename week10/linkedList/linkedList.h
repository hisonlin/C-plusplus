#pragma once
#include <memory>
#include <iostream>


template<typename T>
class LinkList
{
	struct LinkNode;
	typedef std::shared_ptr<LinkNode> LinkP;

	struct LinkNode
	{
		T  data;
		LinkP next;
		LinkP prev;

		LinkNode(T d = T{}) : data(d), next(nullptr), prev(nullptr) {}
	};

private:
	LinkP head;   // pointing to the first LinkNode
	LinkP tail;   // pointing to the last LinkNode // This is optional, since we can next...next...next... until the end
	size_t count;  // represents the number of LinkNodes in this linklist//This is optinal

public:
	LinkList() : head(nullptr), tail(nullptr), count(0) {}  // it is the same as LinkList() = default;

	~LinkList()
	{
		while (head != nullptr)
			pop_back();
	}

	/// accessor for head:
	LinkP Begin()
	{
		return head;
	}

	// accessor for tail:
	LinkP End()
	{
		return tail;
	}

	void push_back(T d)
	{
		// first, create a node and put d in it:
		LinkP newnode(new LinkNode(d));

		// next, add this node to the LinkList
		if (head == nullptr)  // if the list is empty
		{
			head = tail = newnode;
		}
		else  // means the list is not empty
		{
			tail->next = newnode;
			newnode->prev = tail;
			tail = newnode;
		}
		++count;
	}

	void push_front(T d)
	{
		// first, create a node and put d in it:
		LinkP newnode(new LinkNode(d));

		if (head == nullptr)  // if the list is empty
		{
			head = tail = newnode;
		}
		else  // means the list is not empty
		{
			newnode->next = head;
			head->prev = newnode;
			head = newnode;
		}
		++count;
	}

	// insert d after the node a
	void insertAfter(T a, T d)
	{
		// Traverse the linked list to find the node containing a
		LinkP current = head;
		while (current != nullptr && current->data != a)
		{
			current = current->next;
		}

		if (current == nullptr)
		{
			// a was not found in the list
			std::cout << "Cannot insert after " << a << ", node not found\n";
			return;
		}

		// Create a new node containing d
		LinkP newnode(new LinkNode(d));

		// Update pointers to insert the new node after the node containing a
		newnode->prev = current;
		newnode->next = current->next;
		if (current->next != nullptr)
		{
			current->next->prev = newnode;
		}
		current->next = newnode;

		// Update tail pointer if necessary
		if (tail == current)
		{
			tail = newnode;
		}

		++count;
	
	}

	// removes and deletes the last node from the linklist
	void pop_back()
	{
		// check if the list is empty then nothing to do but print an error message
		if (head == nullptr)
		{
			std::cout << "pop_back(): the list is empty!\n";
			return;
		}

		if (head == tail)
		{
			head = tail = nullptr;  // since we are using shared_ptr we don't need to manually delete a node.
			--count;
			return;
		}

		tail = tail->prev;
		tail->next = nullptr;
		--count;
	}

	void pop_front()
	{
		// check if the list is empty then nothing to do but print an error message
		if (head == nullptr)
		{
			std::cout << "pop_front(): the list is empty!\n";
			return;
		}

		if (head == tail)
		{
			head = tail = nullptr;  // since we are using shared_ptr we don't need to manually delete a node.
			--count;
			return;
		}

		head = head->next;
		head->prev = nullptr;
		--count;
	}

	// removes the node whose data is d, from the linklist
	//returns true if a node with data d is found, otherwise retrun false
	bool remove(T d)
	{
		if (head == nullptr)
		{
			std::cout << "remove(): the list is empty!\n";
			return false;
		}

		// first, starting from head, find the node containing the data d. 
		// check if the list is empty then nothing to do but print an error message
		LinkP tempNodeP = head;
		while (tempNodeP && tempNodeP->data != d)
			tempNodeP = tempNodeP->next;

		if (tempNodeP == nullptr)
		{
			std::cout << "remove(): the data " << d << " is not found in the list.\n";
			return false;
		}

		// if we are here, it means we found the node containg d. So let's remove it 
		// from the list:
		// remove the node from the linklist by reassiging the prev and next pointers in the linklist

		tempNodeP->prev->next = tempNodeP->next;
		if (tempNodeP != tail)
			tempNodeP->next->prev = tempNodeP->prev;
		else
		{
			tail = tempNodeP->prev;
			tail->next = nullptr;
		}
		--count;

		return true;
	}

	// finds out if a value is in the linklist:
	// basically go over each node, one by one, and check
	// if data is the same as d. If so, return true.
	// Once you get to the end of the list and still not
	// found the node, then it means list does not contain d,
	// so return false;
	bool find(T d)
	{
		auto tmpP = head;
		while (tmpP)
		{
			if (tmpP->data == d)
				return true;
			else
				tmpP = tmpP->next;
		}
		return false;
	}

	void swap(T& t1, T& t2)
	{
		T temp = t1;
		t1 = t2;
		t2 = temp;
	}
	// sorts the list in least to largest order
	template<typename CMP>
	void bubblesort()
	{
		CMP comp; //create an object for comparision
		for (auto currEnd = End(); currEnd != Begin(); currEnd = currEnd->prev)
		{
			for (auto it = Begin(); it != currEnd; it = it->next)
			{
				if (!comp(it->data, it->next->data))
					swap(it->data, it->next->data);
				
			}
		}
		std::cout << "bubblesort: to be done\n";
	}
	// overloading ouptput operator so we can print out the list
	friend std::ostream& operator<<(std::ostream& os, LinkList<T>& list)
	{
		os << "LinkedList: ";
		auto nodeP = list.head;
		while (nodeP)
		{
			os << nodeP->data << ", ";
			nodeP = nodeP->next;
		}
		os << std::endl;
		return os;
	}



};

