/*	This program is used to calculate addition, subtraction, multiplication, and division of complex numbers
	given two complex numbers by the user. 
	
@file: complexApplication.cpp
@Author: Logan Krick
@Date: 9/6/2018
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
	c1.setData();
	cout << endl;

	cout << "Enter the second complex: real_part imaginary_part" << endl;
	c2.setData();
	cout << endl;

	cout << "The two complex numbers entered are: " << endl;
	cout << "c1 = " << c1.get_real() << " + " << c1.get_imag() << "i" << endl;
	cout << "c2 = " << c2.get_real() << " + " << c2.get_imag() << "i" << endl << endl;

	cout << "The arithmetic operations on these two complex numbers are:" << endl;
	c = c1.add(c2);
	cout << "c1 + c2 = " << c.get_real() << " + " << c.get_imag() << "i" << endl;
	c = c1.sub(c2);
	cout << "c1 - c2 = " << c.get_real() << " + " << c.get_imag() << "i" << endl;
	c = c1.mult(c2);
	cout << "c1 * c2 = " << c.get_real() << " + " << c.get_imag() << "i" << endl;
	c = c1.div(c2);
	cout << "c1 / c2 = " << c.get_real() << " + " << c.get_imag() << "i" << endl;

	return 0;
}