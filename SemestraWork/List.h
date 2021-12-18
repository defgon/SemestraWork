#pragma once
#include <iostream>
#include "Utils.h"


//==========================================================================================================
// struct Node
//==========================================================================================================

//sablony 
//template <typename T>
//for(int value : int_list) pøes všeechny prvky



/// Single node of the following linked list containing an integer value.
struct Node {
	/// Single instance of the data type that can be stored in the linked list.
	int mValue;

	/// Pointer to the next node in the linked list.
	///
	/// \note By default, it points nowhere.
	Node* mNext = nullptr;
};

// =========================================================================================================
// class List
// =========================================================================================================

/// Singly linked list with tail for storing integers.
class List {
	/// Pointer to the first node of this list.
	Node* mFirst = nullptr;

	/// Pointer to the tail node of this list.
	///
	/// It does not contain any useful value, just closes this list. 
	/// \note List containing only its dummy tail is considered to be empty.
	Node* mDummyTail = nullptr;

public:
	/// Constructor creating an empty list.
	List() {
		// TASK 1: Implement according to the documentation above. 
		// Note: A dynamic instance of the Node struct representing the dummy tail of this list 
		//       must be created.
		// Note: In the end, both ends of the node chain, that implements this linked list, must 
		//       point to the created tail.
		// INSERT YOUR IMPLEMENTATION HERE:

		mFirst = new Node();
		mDummyTail = mFirst;

	}

	/// Destructor deleting all existing nodes.
	~List() {
		// TASK 2: Implement according to the documentation above. 
		// Note: Do last as one of the methods assigned below can be used here.
		// Note: The dummy tail must be deleted at the end.
		// INSERT YOUR IMPLEMENTATION HERE:

		this->clear();
		delete mDummyTail;



	}

	// -----------------------------------------------------------------------------------------------------
	// Advanced
	// -----------------------------------------------------------------------------------------------------

	/// Returns whether this list is empty.
	bool isEmpty() {
		// TASK 3: Implement according to the documentation above. 
		// Note: Empty list does not contain any nodes but its dummy tail.
		// INSERT YOUR IMPLEMENTATION HERE:
		if (mFirst == mDummyTail) {
			return true;
		}
		else {
			return false;
		}
	}

	/// Returns the size of this list.
	int getSize() {
		// TASK 4: Implement according to the documentation above. 
		// Note: List size is equal to the number of "useful" values stored in its nodes.
		// Note: The method must iterate in a cycle through all nodes in this list.
		// Note: Method print() implemented below as an example may be helpful. 
		// INSERT YOUR IMPLEMENTATION HERE:
		int size = 0;
		Node* temp = mFirst;
		
		while (temp != mDummyTail) {
			size++;
			temp = temp->mNext;
		}
		return size;
	}

	/// Inserts the given value to the beginning of this list.
	void pushFront(int value) {
		// TASK 5: Implement according to the documentation above. 
		// Note: A dynamic instance of the Node struct must be created and its value must be set.
		// Note: The created instance must be the first in the node chain of this list. Therefore, 
		//       its "next" neighbor must be the node that used to be the first before.
		// Note: At the end, the pointer pointing to the first node of this list must point to the 
		//       created instance.
		// INSERT YOUR IMPLEMENTATION HERE:

		Node* temp = new Node(); //alokovat dynamicky
		temp->mValue = value; 
		temp->mNext = mFirst;

		mFirst = temp;
	}

	/// Removes the first node from this list.
	void removeFirst() {
		// TASK 6: Implement according to the documentation above. 
		// Note: Print a warning if this list was already empty.
		// Note: The first node must removed from the node chain of this list and then deleted.
		// Note: The method must work even if this list contained exactly one node with 
		//       a "useful" value before the call.
		// INSERT YOUR IMPLEMENTATION HERE:
		if (this->isEmpty()) // this-> pro demonstraci (jako demonstrace v této fci) (odliš metody od obyc fce)
		{
			printWarning("Removing from empty list.");
		}
		else 
		{
			Node* temp = mFirst;
			mFirst = mFirst->mNext;
			delete temp;
		}


	}

	/// Removes all values from this list.
	void clear() {
		// TASK 7: Implement according to the documentation above. 
		// Note: All nodes containing "useful" values must be removed from this list. 
		// Note: This list should be "empty" but still usable afterwards. 
		// INSERT YOUR IMPLEMENTATION HERE:
		while (mFirst != mDummyTail)
		{
			removeFirst(); //muze mit nevyhodu pouzit fci zde ale zatim jsem nenašel
		}
	}

	/// Returns whether the given value is already stored in this list.
	bool contains(int value) {
		// TASK 8: Implement according to the documentation above.
		// Note: "true" should be returned only if the given value was found in a node from this list.
		// INSERT YOUR IMPLEMENTATION HERE:
		
		Node* temp = mFirst;

		for (int i = 0; i <= getSize(); i++)
		{
			if (temp->mValue == value) 
			{
				return true;
			}
			temp = temp->mNext;
		}

	}

	/// Returns the value stored at the given index or -1 if the index was not a valid index to this list.
	int getValue(int index) {
		// TASK 9: Implement according to the documentation above.
		// Note: Indexing should start at zero (getValue(0) should return the value from the first node in 
		//       this list, getValue(1) from the second etc).
		// Note: A warning should be printed if the given index was invalid (negative or too large).
		// INSERT YOUR IMPLEMENTATION HERE:

		//cyklus
		if (index < 0 || index >= this->getSize()) {
			printWarning("invalid index");
			return -1;
		}

		int size = 0;
		Node* temp = mFirst;

		for (int i = 0; i < index; i++)
		{
			temp = temp->mNext;
		}
		return temp->mValue;
	}

	/// Returns the lowest index of the given value or -1 if the value is not present in this list.
	int indexOf(int value) {
		// TASK 10: Implement according to the documentation above.
		// Note: Only the first match is important. No need to consider that more identical values may be 
		//       stored in this list.
		// INSERT YOUR IMPLEMENTATION HERE:
		bool checker = true;
		Node* temp = mFirst;
		int i = 0;

		while (checker)
		{
			i++;
			if (temp->mValue == value) 
			{
				return i;
				checker = false;
			} else if (temp == mDummyTail)
			{
				printWarning("Value was not found.");
				return -1;
				checker = false;
			}
			temp = temp->mNext;
		}
	}

	// -----------------------------------------------------------------------------------------------------
	// Advanced
	// -----------------------------------------------------------------------------------------------------

	/// Appends the given data at the end of this list.
	void pushBack(int value) {
		// Task 11: Implement according to the documentation above. 
		// Note: A new node must be created and its value set.
		// Note: The created instance must be appended at the end of this list.
		// Note: The node should not became the dummy tail.
		// Note: The method must work even if this list was empty before the call.
		// INSERT YOUR IMPLEMENTATION HERE:
		Node* temp = new Node();
		temp->mValue = value;
		temp->mNext = mDummyTail;

		if (isEmpty())
		{
			mFirst = temp;
		}
		else 
		{
			Node* last = mFirst;
			while (last->mNext != mDummyTail)
			{
				last = last->mNext; // hleda posledni prvek protoze ten ukazuje na mDummy...
			}

			last->mNext = temp; // nastavi posledni prvek jako nasi hodnotu
		}

		
	}

	/// Places the given value to this list at the forwarded index.
	void insert(int index, int value) {
		// TASK 12: Implement according to the documentation above. 
		// Note: Calling getValue() with the same index afterwards should return the given value.
		// Note: A warning should be printed if the given index was invalid (negative or too large).
		// INSERT YOUR IMPLEMENTATION HERE:

		if (index < 0 || index > getSize())
		{
			printWarning("Invalid value of index");
		}

		Node* temp = new Node();
		temp->mValue = value;


	}

	/// Removes the first node containing the given value from this list.
	///
	/// \return true if the value was removed or false if no such value was found.
	bool remove(int value) {
		// TASK 13: Implement according to the documentation above. 
		// Note: Only the first match is important. No need to consider that more identical values may 
		//       be stored in this list.
		// INSERT YOUR IMPLEMENTATION HERE:





	
	}

	/// Removes all nodes containing the given value from this list.
	bool erase(int value) {
		// TASK 14: Implement according to the documentation above. 
		// Note: Presence of more identical values in this list must be considered.
		// INSERT YOUR IMPLEMENTATION HERE:



		return false;
	}

	// -----------------------------------------------------------------------------------------------------
	// Hard
	// -----------------------------------------------------------------------------------------------------

	/// Sorts this list values in ascending order.
	void sort() {
		// Bonus: Implement according to the documentation above.
		// Note: In the end, the smallest value should be the first, the largest the last one etc.
		// INSERT YOUR IMPLEMENTATION HERE:



	}

	// -----------------------------------------------------------------------------------------------------
	// Example 
	// -----------------------------------------------------------------------------------------------------

	/// Prints all values from this list.
	void print() {
		// Note: May be used as an inspiration.
		std::cout << "[";
		for (Node* it = mFirst; it != mDummyTail; it = it->mNext) {
			if (it != mFirst) {
				std::cout << ", ";
			}
			std::cout << it->mValue;
		}
		std::cout << "]" << std::endl;
	}
};

