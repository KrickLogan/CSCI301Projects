/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: /home/STCLOUDSTATE/pq8748xu
Due Date: 10/3/18
Instructor: Jie Hu Meichsner
*/

#include <iostream>

using namespace std;

const int arrSize = 5;

/* Returns the kth smallest value in arrPtr[first...last].
@param: int k is the value to determine the kth smallest value, arrPtr is a pointer to an array, first and last are integers
@pre: array available to pass
@post: Returns the kth smallest value in arrPtr[first...last] */
int kSmall(int k, int* arrPtr, int first, int last);

/* partitions the array
@param: arrPtr is a pointer to an array, size is an integer of the size of the array, pivotValue and pivotIndex are integers
@pre: array available to pass and a pivot value chosen
@post: partitions the array */
void partition(int* arrPtr, int size, int pivotValue, int& pivotIndex);

int main() {
	int* arrPtr = new int[arrSize] {10,20,30,40,50}; // dynamically allocate memory for arrPtr

	cout << "The kth smallest value in arrPtr is: " << endl;
	cout << kSmall(3, arrPtr, 0, arrSize) << endl;

	delete arrPtr; // deallocate the memory stored for arrPtr
	arrPtr = NULL; // set arrPtr to NULL to avoid dangling pointer
	
	return 0;
}

int kSmall(int k, int* arrPtr, int first, int last) {
	int pivotIndex = first;
	int p = arrPtr[first];
	int pivotValue = 0;

	partition(arrPtr, first, arrSize, pivotIndex);

	if (k < pivotIndex - first + 1)
		return kSmall(k, arrPtr, first, pivotIndex - 1);

	else if (k == pivotIndex - first + 1)
		return p;

	else
		return kSmall(k - (pivotIndex - first + 1), arrPtr, pivotIndex + 1, last);
}

void partition(int* arrPtr, int first, int last, int& pivotIndex) {
	int pivot = arrPtr[first];
	int lastS1 = first;
	int firstUnknown = first + 1; 

	for (; firstUnknown <= last; ++firstUnknown) 	{
		if (arrPtr[firstUnknown] < pivot) {
			++lastS1;
			swap(arrPtr[firstUnknown], arrPtr[lastS1]);
		}
	}

	swap(arrPtr[first], arrPtr[lastS1]);
	pivotIndex = lastS1;
}