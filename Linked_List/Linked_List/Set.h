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

	int size();

	bool insert(const ItemType& value);

	bool erase(const ItemType& value);
	// Remove the value from the set if it is present. Return true if the value was removed; otherwise, leave the set unchanged and return false.

	bool contains(const ItemType& value) const;

	bool get(int pos, ItemType& value) const;

	void swap(Set& other);

private:
	struct Node
	{
		Node* n_next;
		ItemType m_value;
		Node* m_prev;
	};

	int m_size;
	Node* m_head;
	Node* m_tail;
};


#endif // Set_Include