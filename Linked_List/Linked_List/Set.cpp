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
	return false;
}

bool Set::contains(const ItemType& value) const
{
	return false;
}

bool Set::get(int pos, ItemType& value) const
{
	return false;
}

void Set::swap(Set& other)
{
	return;
}