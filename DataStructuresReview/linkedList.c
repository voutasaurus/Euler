#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
//#include <string.h>
//#include <stddef.h>
//#include <ctype.h>
//#include <time.h>

// Constructors
struct linkedListEntry 	*newLL(void);
struct linkedListEntry 	*newLLwithvalue(int val); // Not implemented (needs storage allocated for entry)

// Add entries
struct linkedListEntry 	*consLL (struct linkedListEntry *front, int valueToInsert);
struct linkedListEntry 	*insertLL (struct linkedListEntry *front, int valueToInsert);

// List deconstuctors
int 			headLL(struct linkedListEntry *front); // Error case not handled appropriately
struct linkedListEntry 	*tailLL(struct linkedListEntry *front); // Error case not handled appropriately

// Remove entries (by value)
struct linkedListEntry 	*removeFirstByValLL(struct linkedListEntry *front, int valueToRemove);
struct linkedListEntry 	*removeAllByValLL(struct linkedListEntry *front, int valueToRemove);

// Remove entry (by reference)
struct linkedListEntry 	*removeByRefLL(struct linkedListEntry *front, struct linkedListEntry *entryToRemove);

// Print list contents
void 			printLL (struct linkedListEntry *front);

// Test functions
void 			testLL (void);

// Data Structure for Linked List
struct linkedListEntry
{
	int value;	// The value stored in this entry in the list
	struct linkedListEntry *next;	// pointer to the next entry of the list
};


// Function to create an empty list
// What does this do since the memory allocated for this struct is
// deallocated when this function returns?
// It's supposed to be a null pointer, and it seems to work anyway
// probably best to check this somehow
struct linkedListEntry *newLL (void)
{
	return ((struct linkedListEntry *) 0);
}

// Function to make a new linked list given a single value
struct linkedListEntry *newLLwithvalue (int val)
{
	struct linkedListEntry *newList = (struct linkedListEntry *) malloc (sizeof (struct linkedListEntry));

	newList->value = val;
	newList->next = (struct linkedListEntry *) 0;

	return newList;
}


// Function to add a value to the front of a list 
struct linkedListEntry *consLL (struct linkedListEntry *front, int valueToInsert)
{
	// Allocate memory for this entry on the heap
	struct linkedListEntry *newEntry = (struct linkedListEntry *) malloc(sizeof (struct linkedListEntry));

	newEntry->value = valueToInsert; // The value of the entry from input
	newEntry->next = front; // This new entry points to the old front of the list

	return newEntry; // Return the new front of the list
}

// Function to insert a value into a sorted linked list
struct linkedListEntry *insertLL (struct linkedListEntry *front, int valueToInsert)
{
	// Allocate memory for this entry on the heap
	struct linkedListEntry *newEntry = (struct linkedListEntry *) malloc(sizeof (struct linkedListEntry));

	newEntry->value = valueToInsert; // The value of that entry from input

	struct linkedListEntry *current = front; // To cycle through the list
	struct linkedListEntry *previous = (struct linkedListEntry *) 0; // follows behind current

	bool oldfront = true; // The front of the list will probably remain the same
	bool found = false;

	// Cycle to the first value greater than the insertion value
	// Linear (With an array binary search would be faster, but this is a list)
	// (With skip lists we could emulate binary search)
	while (current != (struct linkedListEntry *) 0 && !found)
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

	// If there is a value in the list <= the insertion value
	if (previous != (struct linkedListEntry *) 0)
		previous->next = newEntry; // Make the highest one point to the new entry
	else
		oldfront = false; // The newEntry is now the front of the list	

	// Make the new entry point to the next largest entry
	// If the list was empty before, then current = front, and so pointing to NULL is correct
	newEntry->next = current;

	if (oldfront)
		return front; // Return the original front of the list (the new entry is internal)
	else	
		return newEntry; // Return the new front of the list

}

// Get the head of the list (value of the first entry)
int headLL (struct linkedListEntry *front)
{
	if (front != (struct linkedListEntry *) 0)
		return front->value;
	else
		return -1; // ERROR - TODO: Add some appropriate error handling
}

// Get the tail of the list (all but the first entry)
struct linkedListEntry *tailLL (struct linkedListEntry *front)
{
	if (front != (struct linkedListEntry *) 0)
		return front->next;
	else
		return front; // ERROR - TODO: Add some appropriate error handling?
}

struct linkedListEntry *removeFirstByValLL(struct linkedListEntry *front, int valueToRemove)
{
	struct linkedListEntry *current = front; // To run through the list
	struct linkedListEntry *previous = (struct linkedListEntry *) 0; // Keeps track of the previous entry

	bool found = false; // Flag for early termination

	// Runs through the list
	while (current != (struct linkedListEntry *) 0 && !found)
	{
		if (current->value == valueToRemove)
		{
			// If there is a previous entry (ie current is not the front of the list)
			if (previous != (struct linkedListEntry *) 0)
				previous->next = current->next; // Point previous to next cutting out current
			else
				front = front->next; // Remove the front of the list

			// The current entry is now removed from the list, athough the data will still remain in allocated memory

			found = true; // This will cause the loop to terminate
		}
		else
		{
			// Go to the next entry
			previous = current;
			current = current->next;
		}
	}

	// pointer to the new list
	return front;
}

struct linkedListEntry *removeAllByValLL(struct linkedListEntry *front, int valueToRemove)
{
	struct linkedListEntry *current = front; // To run through the list
	struct linkedListEntry *previous = (struct linkedListEntry *) 0; // Keeps track of the previous entry
	struct linkedListEntry *remove = (struct linkedListEntry *) 0;

	// Runs through the list
	while (current != (struct linkedListEntry *) 0) // && !found) // Extra condition to terminate loop early
	{
		if (current->value == valueToRemove)
		{
			// REMOVE the current entry

			// If there is a previous entry (ie current is not the front of the list)
			if (previous != (struct linkedListEntry *) 0)
			{
				previous->next = current->next; // Point previous to next cutting out current
				remove = current;
				free(remove);		// Free the memory of the current entry
			}
			else // This is the front of the list
			{
				remove = front;
				free(remove);		// Free the memory of the current entry
				front = front->next; 	// Remove the front of the list
			}

			// The current entry is now removed from the list and memory has been freed

			// Continue to next entry (previous stays the same as the entry it would normally be has been removed)
			current = current->next;

		}
		else
		{
			// Go to the next entry
			previous = current;
			current = current->next;
		}
	}

	// pointer to the new list
	return front;
}

// Remove entry by reference
struct linkedListEntry *removeByRefLL(struct linkedListEntry *front, struct linkedListEntry *entryToRemove)
{
	struct linkedListEntry *current = front; // To run through the list
	struct linkedListEntry *remove = (struct linkedListEntry *) 0; // To run through the list

	if (entryToRemove == (struct linkedListEntry *) 0)
		return front; // Void reference cannot be removed

	if (front == entryToRemove)
	{
		current = front->next;
		remove = front;
		free(remove);	

		return current; // Just remove the front of the list
	}

	bool found = false;

	while (current != (struct linkedListEntry *) 0 && !found)
	{
		if (current->next == entryToRemove)
		{
			current->next = entryToRemove->next;
			found = true;
			free(entryToRemove);
		}
		else
		{
			current = current->next;
		}
	}

	return front;

}

// Function to print the contents of a list
void printLL (struct linkedListEntry *front)
{
	struct linkedListEntry *current = front;

	while (current != (struct linkedListEntry *) 0)
	{
		printf("%i \n", current->value);
		current = current->next;
	}
}

// Function for testing insertion sort
// Just shuffles the digits 1-9 in a predetermined way
int mix(int i)
{
	int m = 0;

	switch (i)
	{
	case 1:
		m = 7;
		break;
	case 2:
		m = 3;
		break;
	case 3:
		m = 9;
		break;
	case 4:
		m = 2;
		break;
	case 5:
		m = 1;
		break;
	case 6:
		m = 6;
		break;
	case 7:
		m = 8;
		break;
	case 8:
		m = 5;
		break;
	case 9:
		m = 4;
		break;
	default:
		m = 0;
	}
	
	return m;
}

// Function to test Linked Lists
void testLL (void)
{

	printf("\n");
	printf("======================================== \n");	
	printf("Linked List Test function running \n");
	printf("======================================== \n");
	printf("\n");

	int i = 0;

	// Test 1: manual list construction
	struct linkedListEntry n1, n2, n3;
	struct linkedListEntry *list_pointer_manual = &n1;

	n1.value = 100;
	n1.next = &n2;
	n2.value = 200;
	n2.next = &n3;
	n3.value = 300;
	n3.next = (struct linkedListEntry *) 0; // end of the list - null pointer

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
	printLL(list_pointer_manual);
	printf("==================== \n");

	// null test
	struct linkedListEntry *list_pointer_nullTest = (struct linkedListEntry *) 0;

	printf("Null list print (Manual version): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_nullTest);
	printf("==================== \n");

	// Test 2: newLL()

	struct linkedListEntry *list_pointer_newLL = newLL();

	printf("Null list print (newLL version): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_newLL);
	printf("==================== \n");


	// Test 3: consLL()

	struct linkedListEntry *list_pointer_consLL = newLL();
	
	// Add to new list
	list_pointer_consLL = consLL(list_pointer_consLL, 2);

	printf("Cons list print (consLL): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("2 \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_consLL);
	printf("==================== \n");

	// Fresh list for new test
	struct linkedListEntry *list_pointer_consLL_mult = newLL();

	for (i = 0; i < 10; i++)
		list_pointer_consLL_mult = consLL(list_pointer_consLL_mult, i);

	printf("Cons mult list print (consLL): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("9 \n");
	printf("8 \n");
	printf("7 \n");
	printf("6 \n");
	printf("5 \n");
	printf("4 \n");
	printf("3 \n");
	printf("2 \n");
	printf("1 \n");
	printf("0 \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_consLL_mult);
	printf("==================== \n");

	
	// Test 4: insertLL

	struct linkedListEntry *list_pointer_insertLL = newLL();
	list_pointer_insertLL = insertLL(list_pointer_insertLL, 5);

	for (i = 1; i < 10; i++)
	{
		//newEntryAlloc = &(newEntryAllocation[i]);
		list_pointer_insertLL = insertLL(list_pointer_insertLL, mix(i));
	}

	printf("Insertion list print (insertLL): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("1 \n");
	printf("2 \n");
	printf("3 \n");
	printf("4 \n");
	printf("5 \n");
	printf("5 \n");
	printf("6 \n");
	printf("7 \n");
	printf("8 \n");
	printf("9 \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_insertLL);
	printf("==================== \n");


	// Test 5: Remove Data (head / tail) - using cons mult list

	printf("Head / Tail (headLL / tailLL): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("head: 9 \n");
	printf("-------------------- \n");
	printf("tail: \n");
	printf("8 \n");
	printf("7 \n");
	printf("6 \n");
	printf("5 \n");
	printf("4 \n");
	printf("3 \n");
	printf("2 \n");
	printf("1 \n");
	printf("0 \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printf("head: %i \n", headLL(list_pointer_consLL_mult));
	printf("-------------------- \n");
	printf("tail: \n");
	printLL(tailLL(list_pointer_consLL_mult));
	printf("==================== \n");


	// Test 6a: Remove Data (removeFirstByVal) - using insert list

	list_pointer_insertLL = removeFirstByValLL(list_pointer_insertLL, 1);

	printf("Remove list print (removeFirstByValLL): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
	printf("2 \n");
	printf("3 \n");
	printf("4 \n");
	printf("5 \n");
	printf("5 \n");
	printf("6 \n");
	printf("7 \n");
	printf("8 \n");
	printf("9 \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_insertLL);
	printf("==================== \n");

	// Test 6b: Remove Data (removeAllByVal) - using insert list

	struct linkedListEntry anotherNewEntry;
	struct linkedListEntry *newEntry = &anotherNewEntry;

	list_pointer_insertLL = insertLL(list_pointer_insertLL, 2);
	list_pointer_insertLL = removeAllByValLL(list_pointer_insertLL, 2);

	printf("Remove list print (removeAllByValLL): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
//	printf("2 \n");
//	printf("2 \n");
	printf("3 \n");
	printf("4 \n");
	printf("5 \n");
	printf("5 \n");
	printf("6 \n");
	printf("7 \n");
	printf("8 \n");
	printf("9 \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_insertLL);
	printf("==================== \n");

	// Test 6c: Remove Data (removeByRef) - using insert list

	struct linkedListEntry *toRemoveByRef = list_pointer_insertLL;

	toRemoveByRef = toRemoveByRef->next->next->next->next->next->next->next;

	list_pointer_insertLL = removeByRefLL(list_pointer_insertLL, toRemoveByRef);

	printf("Remove list print (removeByRefLL): \n");
	printf("==================== \n");
	printf("Expected: \n");
	printf("==================== \n");
//	printf("2 \n");
//	printf("2 \n");
	printf("3 \n");
	printf("4 \n");
	printf("5 \n");
	printf("5 \n");
	printf("6 \n");
	printf("7 \n");
	printf("8 \n");
//	printf("9 \n");
	printf("==================== \n");
	printf("Actual: \n");
	printf("==================== \n");
	printLL(list_pointer_insertLL);
	printf("==================== \n");

	printf("\n");
	printf("================================== \n");	
	printf("Linked List Test function complete \n");
	printf("================================== \n");
	printf("\n");


}
