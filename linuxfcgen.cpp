#include <iostream>
using namespace std;

void printAvg(int* arrayStart, int size);

int main()
{
	int grades[5]; //create array that will hold 5 values
	int gradeSize = sizeof(grades) / sizeof(int); //number of values in array
	int repeat = 1; //stores the repeat variable

	while (repeat) //will loop until user enters 0
	{
		for (int i = 0; i < 5; i++) //loop executes 5 times and takes a grade each time and stores in array
		{
			cout << "Enter grade number " << i + 1 << endl;
			cin >> grades[i];
		}
		printAvg(grades, gradeSize); //call to print the average and highest grade
		cout << "Press 1 to continue or 0 to end." << endl;
		cin >> repeat;
	}
}

void printAvg(int * arrayStart, int size) //function to print average and highest grade
{
	int sum = 0;
	int maxGrade = 0;
	cout << "The average of the grades ";
	for (int i = 0; i < size; i++)
	{
		cout << *(arrayStart + i) << " ";
		sum += *(arrayStart + i);
		if (maxGrade < *(arrayStart + i))
		{
			maxGrade = *(arrayStart + i);
		}
	}
	cout << "is " << sum / size << "." << endl;
	cout << "The highest grade was " << maxGrade << "." << endl;
}