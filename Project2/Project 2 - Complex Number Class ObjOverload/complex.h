/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: 
Due Date: 9/13/18
Instructor: Jie Hu Meichsner
*/

#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>

using namespace std;

class complex
{
private:

	double real;
	double imag;

public:
	/* Contstructor; */
	/*
	@param initial_real the real number
	@param initial_imag the imaginary number
	@pre None
	@post sets the values of real and imag to 0; */
	complex(double initial_real = 0, double initial_imag = 0);
	
	/* Operation Overloading */

	/* allows the user to set the value of the complex number
	@pre None
	@post The user's entered complex number is stored */
	friend istream& operator>>(istream& in, complex& c);

	/* prints the value of the complex number
	@pre None
	@post The user's entered complex number is printed */
	friend ostream& operator<<(ostream& out, const complex& c);

	/* Adds the users complex numbers
	@pre None
	@post Adds the complex numbers and returns the answer using operation overloading */
	complex operator+(const complex& c) {
		complex tmp;

		tmp.real = real + c.real;
		tmp.imag = imag + c.imag;

		return tmp;
	}

	/* Subtracts the users complex numbers
	@pre None
	@post Subtracts the complex numbers and returns the answer using operation overloading */
	complex operator-(const complex& c) {
		complex tmp;

		tmp.real = real - c.real;
		tmp.imag = imag - c.imag;

		return tmp;
	}

	/* Multiplies the users complex numbers
	@pre None
	@post Multiplies the complex numbers and returns the answer using operation overloading */
	complex operator*(const complex& c) {
		complex tmp;

		tmp.real = real * c.real - imag * c.imag;
		tmp.imag = real * c.imag + c.real*imag;

		return tmp;
	}

	/* Divides the users complex numbers
	@pre None
	@post Divides the complex numbers and returns the answer using operation overloading */
	complex operator/(const complex& c) {
		complex tmp;

		tmp.real = (real*c.real + imag * c.imag) / (c.real*c.real + c.imag*c.imag);
		tmp.imag = (imag*c.real - real * c.imag) / (c.real*c.real + c.imag*c.imag);

		return tmp;
	}

	/* CONSTANT MEMBER FUNCTIONS */

	/* returns the value of real
	@pre None
	@post The value returned is the real number*/
	double get_real() const { return real; }

	/* returns the value of imag
	@pre None
	@post The value returned is the imaginary number*/
	double get_imag() const { return imag; }

};

#endif