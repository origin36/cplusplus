#include <iostream>
#include <string>
using namespace std;

struct AddressNode //struc with string for name and a pointer called AddressNode that points to the next AddressNode
{
	string name;
	AddressNode* next;
};

class ABook //class ABook with private pointer and methods stated in instructions
{
private:
	AddressNode* topPtr; //pointer to top of list

public:
	ABook(); //default constructor for ABook
	AddressNode* getTopPtr(); //method for accessing private pointer topPtr
	void Insert(string NewItem); //method to insert string at starting location
	void SortedInsert(string NewItem); //method to insert string in sorted location
	string Remove(string& item); //method to remove and output string on top of stack
	~ABook(); //deconstructor
};

int main()
{
	ABook Book; //constructor called for string type; memory allocation
	string newName; //declaration of string newName
	string nameToRemove; //declaration of string nameToRemove

	Book.Insert("Precious"); //insert Precious into list
	Book.SortedInsert("Ken"); //insert Ken into listed(sorted)
	Book.SortedInsert("Eileen"); //insert Eileen into list(sorted)
	Book.SortedInsert("Frank"); //insert Frank into list(sorted)

	cout << "Sorted List:" << endl;
	
	while (Book.getTopPtr() != NULL) //iterate until the topPtr is NULL
	{
		Book.Remove(nameToRemove); //remove item at top of stack
		cout << nameToRemove << endl; //return removed item
	} //end while

	Book.~ABook(); //destructor called; memory freed up

	system("PAUSE");
	return 0;
} //end main

ABook::ABook() //constructor
{
	topPtr = NULL; //initialize address of topPtr to NULL
} //end constructor

AddressNode* ABook::getTopPtr() //method for accessing private pointer topPtr
{
	return topPtr;
}

void ABook::Insert(string NewItem)
{	
	AddressNode* createNode = new AddressNode; //create a new AddressNode
	createNode->name = NewItem; //place NewItem string into newly created AddressNode

	if (topPtr == NULL) //execute if list is empty
	{
		createNode->next = NULL; //change pointer of newly created node to NULL to indicate that it is last in the list
		topPtr = createNode; //change pointer topPtr to newly created node to indicate that it is first in the list
	} //end if
	else //execute if list has values, placing new value at top of the stack, not used in this assignment
	{
		createNode->next = topPtr; //change pointer of newly created node to point to topPtr address
		topPtr = createNode; //change topPtr address to newly created node to indicate top of list
	} //end else
	createNode = NULL; //prevent dangling pointer
	delete createNode; //delete pointer createNode to free up memory
} //end method Insert

void ABook::SortedInsert(string NewItem)
{
	AddressNode* createNode = new AddressNode; //create a new AddressNode
	createNode->name = NewItem; //set the name in newly created AddressNode to NewItem
	if (topPtr == NULL) //execute if list is empty
	{
		createNode->next = NULL; //change pointer of newly created node to NULL to indicate that it is last in the list
		topPtr = createNode; //change pointer topPtr to newly created node to indicate that it is first in the list
	} //end if
	else if (topPtr->name >= createNode->name) //execute if ASCII code of new name is less than or equal to the first name in linked list
	{
		createNode->next = topPtr; //next pointer in newly created node changed to point to old top of list
		topPtr = createNode; //change the top of the list to point to newly created node
	} //end if
	else
	{
		AddressNode* back = topPtr; //pointer to adjacent address nodes, back node
		AddressNode* front = topPtr->next; //pointer to adjacent address nodes, front node

		while (front != NULL) //execute while loop until pointer front is NULL
		{
			if (front->name >= createNode->name) //execute if the ASCII code of the top name is less than or equal to ASCII code of new name
			{
				createNode->next = front; //change the newly created node next pointer to point to front link
				back->next = createNode; //change the back link to point to the newly created node
				break; //break out of while loop since new data was added
			} //end if
			else //execute if ASCII code of front name is less than new name
			{
				back = front; //change the back pointer to the front pointer
				front = front->next; //increment the front pointer to next pointer
			} //end else
		} //end while
		if (front == NULL) //execute if ASCII code of the new name is less than all names in the linked list stack
		{
			createNode->next = NULL; //set the next value to NULL since it is the top in the stack
			back->next = createNode; //link the back AddressNode to the newly added AddressNode
		} //end if
	} //end else
	createNode = NULL;
	delete createNode; //delete pointer createNode to free up memory
} //end method SortedInsert

string ABook::Remove(string& item) //Remove element from the top of the stack and return the item.
{
	item = topPtr->name; //set the item to the name the topPtr AddressNode is pointing to
	if (topPtr->next != NULL) //execute if not at bottom of stack; delete node on top of stack
	{
		AddressNode* temp = topPtr; //temporary pointer to next element
		topPtr = topPtr->next; //set topPtr to point to next element
		temp = NULL; //prevent dangling pointer
		delete temp; //delete pointer and free memory
	} //end if
	else //execute if at bottom of stack to delete last AddressNode
	{
		topPtr = NULL; //prevent dangling pointer
		delete topPtr; //delete pointer to free up memory
	} //end else
	return item;
} //end method remove

ABook::~ABook() //destructor
{
	while (topPtr != NULL) //execute for each link still present in the list (not used in this program)
	{
		AddressNode* temp = topPtr; //set up temp AddressNode pointer
		topPtr = topPtr->next; //set the top pointer to the next link
		delete temp; //delete the temp link
	}

	topPtr = NULL; //prevent dangling pointer
	delete topPtr; //delete the top pointer
} //end destructor
