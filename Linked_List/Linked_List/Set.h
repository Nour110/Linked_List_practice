#ifndef Set_Include
#define Set_Include

#include <string>

using ItemType = unsigned long;

class Set
{
public:
	Set(); // Create an empty set (i.e., one with no items).

	~Set(); // Destructor

	Set& operator=(const Set& rhs); // Assignment operator

	Set(const Set& other); // Copy constructor

	bool empty() const; // Return true if the set is empty, otherwise false

	int size() const; // Return the number of items in the set

	bool insert(const ItemType& value); 
	// Insert value into the set if it is not already present. Return true is the value is actually inserted. Leave the set unchanged and return false if the value was not inserted

	bool erase(const ItemType& value);
	// Remove the value from the set if it is present. Return true if the value was removed; otherwise, leave the set unchanged and return false.

	bool contains(const ItemType& value) const;
	// Return true if the value is in the set, otherwise false. 


	void swap(Set& other);
	// Exchange the contents of this set with the other one


private:
	struct Node
	{
		Node* m_next;
		ItemType m_value;
		Node* m_prev;
	};

	int m_size;
	Node* m_head;
	Node* m_tail;
};


#endif // Set_Include