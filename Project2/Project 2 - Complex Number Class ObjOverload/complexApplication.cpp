/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: 
Due Date: 9/14/18
Instructor: Jie Hu Meichsner
*/

#include <iostream>
#include "complex.h"

using namespace std;

complex c1;
complex c2;
complex c;

int main()
{
	cout << "Enter the first complex: real_part imaginary_part" << endl;
	cin >> c1;
	cout << endl;

	cout << "Enter the second complex: real_part imaginary_part" << endl;
	cin >> c2;
	cout << endl;

	cout << "The two complex numbers entered are: " << endl;
	cout << "c1 = " << c1;
	cout << "c2 = " << c2 << endl;

	c = c1 + c2;
	cout << "c1 + c2 = " << c;
	c = c1 - c2;
	cout << "c1 - c2 = " << c;
	c = c1 * c2;
	cout << "c1 * c2 = " << c;
	c = c1 / c2;
	cout << "c1 / c2 = " << c;

	return 0;
}