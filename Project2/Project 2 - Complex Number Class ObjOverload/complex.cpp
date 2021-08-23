/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: 
Due Date: 9/13/18
Instructor: Jie Hu Meichsner
*/

#include <iostream>
#include "complex.h"

complex::complex(double initial_real, double initial_imag)
{
	real = initial_real;
	imag = initial_imag;
}

ostream& operator<<(ostream& out, const complex& c) {
	out << c.real << " + " << c.imag << "i" << endl;
	return out;
}

istream& operator>>(istream& in, complex& c) {
	in >> c.real >> c.imag;
	return in;
}
