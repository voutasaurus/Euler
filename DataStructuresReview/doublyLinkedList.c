#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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

// Remove entries (by value) -TODO
struct doublyLinkedListEntry 	*removeFirstByValDLL(struct doublyLinkedListEntry *front, int valueToRemove);
struct doublyLinkedListEntry 	*removeAllByValDLL(struct doublyLinkedListEntry *front, int valueToRemove);

// Remove entry (by reference) - TODO
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

	// Allocate memory for this entry on the heap
	struct doublyLinkedListEntry *newEntry = (struct doublyLinkedListEntry *) malloc(sizeof (struct doublyLinkedListEntry));

	newEntry->value = valueToInsert; // The value of that entry from input

	struct doublyLinkedListEntry *current = front; // To cycle through the list
	struct doublyLinkedListEntry *previous = (struct doublyLinkedListEntry *) 0; // follows behind current

	bool oldfront = true; // The front of the list will probably remain the same
	bool found = false;

	// Cycle to the first value greater than the insertion value
	// Linear (With an array binary search would be faster, but this is a list)
	// (With skip lists we could emulate binary search)
	while (current != (struct doublyLinkedListEntry *) 0 && !found)
	{
		if (newEntry->value >= current->value)
		{
			// Keep track of the last entry we looked at
			// It will need to point to the inserted entry
			previous = current; 
			// Go to the next entry because the current entry is still <= the insertion value
			current = current->next;
		}
		else
		{
			found = true; // We've found the insertion spot, so exit the loop
		}
	}

	// If previous is null then the newEntry is at the front so prev should point to null
	// If previous is not null then newEntry->prev should point to it
	newEntry->prev = previous;

	// If there is a value in the list <= the insertion value
	if (previous != (struct doublyLinkedListEntry *) 0)
		previous->next = newEntry; // Make the highest one point to the new entry
	else
		oldfront = false; // The newEntry is now the front of the list	

	// Make the new entry point to the next largest entry
	// If the list was empty before, then current = front, and so pointing to NULL is correct
	newEntry->next = current;

	// If current points to an active entry then it should be next after newEntry
	// newEntry->next already points to current, now current must point back to newEntry
	if (current != (struct doublyLinkedListEntry *) 0)
		current->prev = newEntry;

	if (oldfront)
		return front; // Return the original front of the list (the new entry is internal)
	else	
		return newEntry; // Return the new front of the list

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
	struct doublyLinkedListEntry *current = front;

	while (current != (struct doublyLinkedListEntry *) 0)
	{
		printf("%i \n", current->value);
		current = current->next;
	}
}

// Test the doubly linked list methods
void testDLL(void)
{

	// Start
	printf("\n");
	printf("======================================== \n");	
	printf("Doubly Linked List Test function running \n");
	printf("======================================== \n");
	printf("\n");

	// Test 1: manual list construction
	struct doublyLinkedListEntry n1, n2, n3;
	struct doublyLinkedListEntry *list_pointer_manual = &n1;

	n1.prev = (struct doublyLinkedListEntry *) 0;
	n1.value = 100;
	n1.next = &n2;

	n2.prev = &n1;
	n2.value = 200;
	n2.next = &n3;

	n3.prev = &n2;
	n3.value = 300;
	n3.next = (struct doublyLinkedListEntry *) 0; // end of the list - null pointer

	printf("Manual list print: \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("100 \n");
	printf("200 \n");
	printf("300 \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printDLL(list_pointer_manual);
	printf("==================== \n");

	// End
	printf("\n");
	printf("========================================= \n");	
	printf("Doubly Linked List Test function complete \n");
	printf("========================================= \n");
	printf("\n");

}


