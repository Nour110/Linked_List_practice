#include "Set.h"

using namespace std;

Set::Set()
	:m_size(0),m_head(nullptr),m_tail(nullptr)
{

}

Set::~Set()
{
	Node* del_head = m_head, *hodl;
	while (del_head != nullptr)
	{
		hodl = del_head->m_next;
		delete del_head;
		del_head = hodl;
	}
}


Set& Set::operator=(const Set& rhs)
{
	return *this;
}

bool Set::empty() const
{
	if (m_size == 0)
		return true;
	return false;
}

int Set::size() const
{
	return m_size;
}

bool Set::insert(const ItemType& value)
{
	
	// If the set is empty then insert value and set m_head and m_tail to point to new node and, update m_size
	if (m_head == nullptr)
	{
		Node* first = new Node;
		m_head = first;
		m_tail = first;
		first->m_value = value;
		first->m_next = nullptr;
		first->m_prev = nullptr;
		m_size++;
		return true;
	}
	// Here we assume that the set is nonempty
	
	// Check if the users is trying to insert a value that is the same as the first value in the set. Return false if it is.
	if (m_head->m_value == value)
	{
		return false;
	}
	
	Node* curr = m_head;
	// Check if user is trying to insert a value that is already in the current set.
	while (curr->m_next != nullptr) 
	{	
		curr = curr->m_next;
		if (curr->m_value == value)
			return false;
		
	}
	// We can now assume that the value the user is trying to insert is not already in the set.
	// We can also assume that we are at the last Node in our set.
	// So we create a new node with the user's desired value and update the m_tail, m_size and, the necessary links in the set.
	Node* fournow = new Node;
	curr->m_next = fournow;
	m_tail = fournow;
	fournow->m_value = value;
	fournow->m_prev = curr;
	fournow->m_next = nullptr;
	m_size++;
	
	
	return true;


}

bool Set::erase(const ItemType& value)
{
	// If the set is empty then return false
	if (m_head == nullptr)
		return false;

	// Here we can assume that the set is nonempty

	// Check if the first value in the set is equal to the value that the user wants to erase. If it is then erase it and update m_head and add new Node.
	if (m_head->m_value == value)
	{
	
		// Check if there is only one value in the set so we can update m_tail properly to reflect that our set is now empty.
		if (m_head == m_tail)
		{
			m_tail = nullptr;
			delete m_head;
			m_head = nullptr;
			m_size--;
			return true;
		}
		// We can now assume that there are at least 2 values in the set within this if statement

		// Update the set by setting the second value in the set's m_prev to nullptr, then delete the user's inputted value and decrement m_value. Finally, return true
		Node* holder = m_head->m_next;
		holder->m_prev = nullptr;
		delete m_head;
		m_head = holder;
		m_size--;
		return true;
		
	}

	// We can now assume that the first value in the set is not equal to the value that the user wants to erase. 
	// Also, we can safely assume that the set either does not contain the value or has more than one element.

	Node* curr = m_head;
	while (curr->m_next != nullptr)
	{
		curr = curr->m_next;
		if (curr->m_value == value) // if the current node's value is the same as the one the user wants to remove then we will remove it
		{
			
			// If we are removing the last element in the list then we update m_tail
			if (curr->m_next == nullptr)
				m_tail = curr->m_prev;
			else // otherwise we must update the next node's m_prev pointer
			{
				curr->m_next->m_prev = curr->m_prev;
			}
			curr->m_prev->m_next = curr->m_next; // update the previous node's m_next pointer
			delete curr;
			m_size--; // don't forget to update m_size
			return true; // return true

		}
	}
	return false; // Once we determine that the user's input is not in the set then we can return false.
}

bool Set::contains(const ItemType& value) const
{

	
	return false;
}


void Set::swap(Set& other)
{
	return;
}