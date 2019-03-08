#include <iostream>
using namespace std;

template <typename T>
struct treeNode //structure which comprises the binary sorted tree
{
	T value;
	treeNode* leftPointer;
	treeNode* rightPointer;
};

template <class T>
class sTree //binary sorted tree class
{
private:
	treeNode<T>* root; //value for the root of the tree
public:
	sTree(); //default constructor
	treeNode<T>* getRoot() const; //getter, returns the address of the tree root node
	void addArray(T* arrayStart, T* arrayEnd); //adds array of <T> to the tree
	void addType(T* value, treeNode<T>* node); //add a single <T> to the tree
	void swap(T &first, T &second); //swap two <T> by reference
	treeNode<T>* scan(T input, treeNode<T>* node); //quickly scans the tree to check for the value <T>
	void deleteTree(treeNode<T>* node); //deletes node and children
	~sTree(); //destructor
};

int main()
{
	int arr[] = { 35, 18, 48, 72, 60, 25, };//array given by instructions
	int arrSize = sizeof(arr) / sizeof(int); //outputs the number of values contained in the array

	sTree<int> binarySearchTree; //sTree declared using integers
	binarySearchTree.addArray(arr, arr + arrSize); //inserts the array into the binary search tree

	int numberOfScans = 2;
	for (int i = 0; i < numberOfScans; i++) //loop executes numberOfScans times
	{
		int searchInt; //declared integer to search for
		cout << "Enter Integer to search for: ";
		cin >> searchInt; //input value placed into integer
		cout << (binarySearchTree.scan(searchInt, binarySearchTree.getRoot()) ? "True" : "False") << endl; //call to find function
	} //end for

	binarySearchTree.~sTree(); //call to destructor to free up memory
	system("PAUSE");
	return 0;
} //end main

template<class T>
sTree<T>::sTree() //default constructor
{
	root = NULL;
} //end constructor

template<class T>
treeNode<T>* sTree<T>::getRoot() const //getter for the pointer to the root
{
	return root;
} //end method getRoot

template<class T>
void sTree<T>::addArray(T* arrayStart, T* arrayEnd)
{
	while (arrayStart != arrayEnd) //will loop through all numbers in array passed
	{
		sTree<T>::addType(arrayStart, root);
		arrayStart += 1;
	} //end while
} //end method addArray

template<class T>
void sTree<T>::addType(T* value, treeNode<T>* node)
{
	treeNode<T>* newNode = new treeNode<T>; //creation of new node
	newNode->value = *value; //set value of the new node to the first value in the array
	newNode->leftPointer = newNode->rightPointer = NULL; //set both pointers of the new binary node to NULL

	if (!root) //will execute only once to establish the root node
	{
		root = newNode;
		newNode = NULL;
		delete newNode;
	}
	else if (*value < node->value) //execute if value is smaller than node number
	{
		if (node->leftPointer == NULL) //execute if left pointer points to NULL
		{
			node->leftPointer = newNode;
			newNode = NULL;
			delete newNode;
		} //end if
		else if (*value < node->leftPointer->value) //execute if value is smaller than both current and next smaller number
		{
			sTree<T>::addType(value, node->leftPointer);
		} //end else if
		else //execute if value is in between current and next smaller number
		{
			sTree<T>::swap(*value, node->leftPointer->value);
			sTree<T>::addType(value, node->leftPointer);
		} //end else
	} //end else if
	else if (*value > node->value) //execute if value is larger than node number
	{
		if (node->rightPointer == NULL) //execute if right pointer points to NULL
		{
			node->rightPointer = newNode;
			newNode = NULL;
			delete newNode;
		} //end if
		else if (*value > node->rightPointer->value) //execute if value is larger than both current and next larger number
		{
			sTree<T>::addType(value, node->rightPointer);
		} //end else if
		else //execute if value is in between current and next larger number
		{
			sTree<T>::swap(*value, node->rightPointer->value);
			sTree<T>::addType(value, node->rightPointer);
		} //end else
	} //end else if
	else
	{
		cout << "duplicate value" << endl; //code to deal with duplicate value goes here
	} //end else
} //end method addNumber

template<class T>
void sTree<T>::swap(T &first, T &second)
{
	T temp; //create temp variable
	temp = second; //set temp value to value in second
	second = first; //set second value to value in first
	first = temp; //set first value to value in temp
} //end method swap

template<typename T>
treeNode<T>* sTree<T>::scan(T input, treeNode<T>* node) //method for locating a value and returning address of that value
{
	if (!node || node->value == input) //execute if null node or value is found
	{
		return node;
	} //end if
	else if (input < node->value) //if value is smaller, move down the binary tree to next smaller value
	{
		return sTree<T>::scan(input, node->leftPointer);
	} //end if
	else //if value is larger, move down binary tree to next larger value
	{
		return sTree<T>::scan(input, node->rightPointer);
	}
} //end method find

template<class T>
void sTree<T>::deleteTree(treeNode<T>* node) //recursive function for deleting parent and children
{
	if (node) //execute if the node has a value
	{
		deleteTree(node->leftPointer);
		deleteTree(node->rightPointer);
		node = NULL;
		delete node;
	} //end if
} //end method deleteTree

template<class T>
sTree<T>::~sTree()
{
	deleteTree(root); //call to delete node, will recursively delete all children
} //end destructor
