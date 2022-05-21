#include "Set.h"
#include <cassert>
using namespace std;

int main()
{
	// Initialize empty set to start testing
	Set nothing;
	
	// try inserting values into the set using the insert method
	assert(nothing.insert(5)== true);
	assert(nothing.insert(6)==true);
	assert(nothing.insert(7)==true);

	// Check that the insert method can detect a duplicate value being inserted when that value already exists at the end of the list.
	assert(nothing.insert(7)== false);

	// Check that the insert method can detect a duplicate value being inserted when that value already exists at the beginning of the list.
	assert(nothing.insert(5) == false);

	// Check that the insert method can detect a duplicate value being inserted when that value already somewhere in the set that is neither last or first.
	assert(nothing.insert(6) == false);

	// add another value to the set
	assert(nothing.insert(99) == true);

}