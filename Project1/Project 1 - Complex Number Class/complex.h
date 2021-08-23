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
	/* Contstructor;
	@param initial_real the real number
	@param initial_imag the imaginary number
	@pre None
	@post sets the values of real and imag to 0;
	*/
	complex(double initial_real = 0, double initial_imag = 0);
	
	/* MODIFICATION MEMBER FUNCTIONS */

	/* allows the user to set the value of the complex number
	@pre None
	@post The user's entered complex number is stored */
	void setData()
	{
		cin >> this->real >> this->imag;
	}

	/* Adds the users complex numbers
	@pre None
	@post Adds the complex numbers and returns the answer */
	complex add(complex);

	/* Subtracts the users complex numbers
	@pre None
	@post Subtracts the complex numbers and returns the answer */
	complex sub(complex);

	/* Multiplies the users complex numbers
	@pre None
	@post Multiplies the complex numbers and returns the answer */
	complex mult(complex);

	/* Divides the users complex numbers
	@pre None
	@post Divides the complex numbers and returns the answer */
	complex div(complex);


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