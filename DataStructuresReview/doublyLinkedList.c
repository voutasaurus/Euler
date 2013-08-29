#include <stdio.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <string.h>
//#include <stddef.h>
//#include <ctype.h>
//#include <time.h>

// Constructors
struct doublyLinkedListEntry 	*newDLL(void);
struct doublyLinkedListEntry 	*newDLLwithvalue(int val); 

// Add entries
struct doublyLinkedListEntry 	*consDLL (struct doublyLinkedListEntry *front, int valueToInsert);
struct doublyLinkedListEntry 	*insertDLL (struct doublyLinkedListEntry *front, int valueToInsert);

// List deconstuctors
int 				headDLL(struct doublyLinkedListEntry *front); // Error case not handled appropriately
struct doublyLinkedListEntry 	*tailDLL(struct doublyLinkedListEntry *front); // Error case not handled appropriately

// Remove entries (by value)
struct doublyLinkedListEntry 	*removeFirstByValDLL(struct doublyLinkedListEntry *front, int valueToRemove);
struct doublyLinkedListEntry 	*removeAllByValDLL(struct doublyLinkedListEntry *front, int valueToRemove);

// Remove entry (by reference)
struct doublyLinkedListEntry 	*removeByRefDLL(struct doublyLinkedListEntry *front, struct doublyLinkedListEntry *entryToRemove);

// Print list contents
void 			printDLL (struct doublyLinkedListEntry *front);

// Test functions
void			testDLL(void);

struct doublyLinkedListEntry 
{
	int value;
	struct doublyLinkedListEntry *next;
	struct doublyLinkedListEntry *prev;
};

// Make a new empty list
struct doublyLinkedListEntry *newDLL(void)
{
	return ((struct doublyLinkedListEntry *) 0);
}

// Make a new list with one entry
struct doublyLinkedListEntry *newDLLwithvalue(int val)
{
	struct doublyLinkedListEntry *newList = (struct doublyLinkedListEntry *) malloc (sizeof (struct doublyLinkedListEntry));

	newList->value = val;
	newList->next = (struct doublyLinkedListEntry *) 0;
	newList->prev = (struct doublyLinkedListEntry *) 0;

	return newList;
}

// Add an entry to the front of the list
struct doublyLinkedListEntry *consDLL (struct doublyLinkedListEntry *front, int valueToInsert)
{
	// Allocate memory for this entry on the heap
	struct doublyLinkedListEntry *newEntry = (struct doublyLinkedListEntry *) malloc(sizeof (struct doublyLinkedListEntry));

	// Establish the new entry
	newEntry->value = valueToInsert; // The value of the entry from input
	newEntry->next = front; // This new entry points to the old front of the list
	newEntry->prev = (struct doublyLinkedListEntry *) 0;

	// Establish the backlink from the existing list
	front->prev = newEntry;

	return newEntry; // Return the new front of the list	
}

// Insert an entry into a sorted list
struct doublyLinkedListEntry *insertDLL (struct doublyLinkedListEntry *front, int valueToInsert)
{
	return front;
}

// Get the head of the list (value of the first entry)
int headDLL(struct doublyLinkedListEntry *front)
{
	if (front != (struct doublyLinkedListEntry *) 0)
		return front->value;
	else
		return -1; // ERROR - TODO: Add some appropriate error handling
}

// Get the tail of the list (all but the first entry)
struct doublyLinkedListEntry *tailDLL(struct doublyLinkedListEntry *front)
{
	if (front != (struct doublyLinkedListEntry *) 0)
		return front->next;
	else
		return front; // ERROR - TODO: Add some appropriate error handling?
}

// Remove the first entry which matches the given value
struct doublyLinkedListEntry *removeFirstByValDLL(struct doublyLinkedListEntry *front, int valueToRemove)
{
	return front;
}

// Remove all of the entries which match the given value
struct doublyLinkedListEntry *removeAllByValDLL(struct doublyLinkedListEntry *front, int valueToRemove)
{
	return front;
}

// Remove the entry that is pointed to by the input pointer
struct doublyLinkedListEntry *removeByRefDLL(struct doublyLinkedListEntry *front, struct doublyLinkedListEntry *entryToRemove)
{
	return front;
}

// Print the contents of a list
void printDLL (struct doublyLinkedListEntry *front)
{
	printf("Print not implemented yet \n");
}

// Test the doubly linked list methods
void testDLL(void)
{
	printf("Test not implemented yet \n");
}


