/*	File: complex.cpp
	Class Implemented: complex */

#include <iostream>
#include "complex.h"

complex::complex(double initial_real, double initial_imag)
{
	real = initial_real;
	imag = initial_imag;
}

complex complex::add(complex c)
{
	complex tmp;

	tmp.real = real + c.real;
	tmp.imag = imag + c.imag;

	return tmp;
}

complex complex::sub(complex c)
{
	complex tmp;

	tmp.real = real - c.real;
	tmp.imag = imag - c.imag;

	return tmp;
}

complex complex::mult(complex c)
{
	complex tmp;

	tmp.real = real*c.real - imag*c.imag;
	tmp.imag = real*c.imag + c.real*imag;

	return tmp;
}

complex complex::div(complex c)
{
	complex tmp;

	tmp.real = (real*c.real + imag*c.imag) / (c.real*c.real + c.imag*c.imag);
	tmp.imag = (imag*c.real - real*c.imag) / (c.real*c.real + c.imag*c.imag);

	return tmp;
}