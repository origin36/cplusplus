#include <iostream>
#include <d_random.h>
#include <d_vector.h>

using namespace std;

//write function declaration
template <typename T>
void writeMiniVector(const miniVector<T> &v);

//sort function declaration
template <typename T>
void sortMiniVector(miniVector<T> &v);

int main()
{
	miniVector<int> v; //declaration of miniVector v
	randomNumber rnd; //declaration of random number rnd

	//initialization of miniVector with 15 random numbers
	for (int i = 0; i < 15; i++)
	{
		v.push_back(rnd.random(100));
	}

	writeMiniVector(v); //output unsorted miniVector
	sortMiniVector(v); //sort miniVector
	writeMiniVector(v); //output sorted miniVector

	system("PAUSE"); //added as per instructions
	return 0;
} //end main
 
//write function
template <typename T>
void writeMiniVector(const miniVector<T> &v)
{
	for (int i = 0; i < v.size(); i++) //iterate through miniVector
	{
		cout << v[i] << " "; //output contents with a space
	} //end for
	cout << endl;
} //end writeMiniVector

//sort function
template <typename T>
void sortMiniVector(miniVector<T> &v)
{
	for (int i = 0; i < v.size() - 1; i++)
	{
		for (int j = 0; j < v.size() - 1; j++)
		{
			if (v[j] < v[j + 1])  //compares 2 adjacent numbers, if first is smaller, loop executes
			{
				swap(v[j], v[j + 1]); //swaps the 2 adjacent numbers
			} //end if
		} //end for
	} //end for
} //end sortMiniVector