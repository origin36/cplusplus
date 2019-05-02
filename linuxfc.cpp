#include <iostream>
using namespace std;

void printAvg(int* arrayStart, int size); //function that prints the array and calculated average

int main()
{
    int grades[] = { 77, 85, 80, 94, 97 }; //grades array as per instructions
    int gradeSize = sizeof(grades) / sizeof(int); //retrieve the array size and store as gradeSize

    printAvg(grades, gradeSize); //pass parameters into function printAvg
} //end main

void printAvg(int* arrayStart, int size)
{
    int sum = 0;
    cout << "The average of the grades ";
    for (int i = 0; i < size; i++) //iterate loop size times
    {
        cout << *(arrayStart + i) << " "; //dereference and print number
        sum += *(arrayStart + i); //dereference number and add to array
    } //end for
    cout << "is " << sum / size << endl; //print the average
} //end printAvg
