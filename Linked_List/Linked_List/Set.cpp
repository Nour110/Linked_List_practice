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