#include "Set.h"
#include <cassert>
using namespace std;

int main()
{
	// Initialize two empty set to start testing
	Set nothing;

	Set actnothing;

	// Test if empty function works on newly initialized set and that size functions gives proper value when set is initialized
	assert(nothing.empty() == true);
	assert(actnothing.size() == 0);
	// try inserting values into the set using the insert method
	assert(nothing.insert(5)== true);
	assert(nothing.insert(6)==true);
	// Test if m_size and size method function as expected
	assert(nothing.size() == 2);
	assert(nothing.insert(7)==true);

	// Check that the insert method can detect a duplicate value being inserted when that value already exists at the end of the list.
	assert(nothing.insert(7)== false);

	// Check that the insert method can detect a duplicate value being inserted when that value already exists at the beginning of the list.
	assert(nothing.insert(5) == false);

	// Check that the insert method can detect a duplicate value being inserted when that value already somewhere in the set that is neither last or first.
	assert(nothing.insert(6) == false);

	// Test adding another value to the set
	assert(nothing.insert(99) == true);

	// Test removing value from empty set
	assert(actnothing.erase(5) == false);


	// test removing first value
	assert(nothing.erase(5) == true);
	// Test removing value that is not in the set
	assert(nothing.erase(5) == false);
	assert(nothing.insert(5) == true);
	//test removing last value
	assert(nothing.erase(5) == true & nothing.size() == 3);

	assert(nothing.insert(99) == false);

	assert(nothing.insert(8) == true);
	
	// test removing value that is neither first nor last in the set
	assert(nothing.erase(7) == true & nothing.size() == 3);

	// test if contains function works with a value at the end of a set and the beginning
	assert(nothing.contains(8) == true);

	
}