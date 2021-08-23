/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project6\
Due Date: 10/26/18
Instructor: Jie Hu Meichsner
*/

#include "calculator.h"
#include "LinkedStack.h"
#include "PrecondViolatedExcep.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
	Calculator calc;
	string infixExpr;
	char yesNo;
	bool cont = true;

	while (cont == true) {
		cout << "Enter an Infix Expression: ";
		cin >> infixExpr;

		// run code and if an exception is thrown catch it.
		try {
			calc.isBalanced(infixExpr); // Checks if parentheses are balanced and throws exception if not balanced.

			string postfixExpr = calc.InfixToPostfix(infixExpr); // Convert infix expression to postfix and store in postfixExpr.
			cout << "The Postfix expression is: " << postfixExpr << endl;

			int value = calc.solvePostfix(postfixExpr); // Calculate the solution of the postfix expression and store in int value.
			cout << "The answer to your expression is: " << value << endl << endl;

			cout << "Would you like to continue? y/n : ";
			cin >> yesNo; // check if user would like to continue.
			cout << endl;

			if (yesNo == 'y')
				cont = true;
			else
				cont = false;
		}
		// catch exception if thrown.
		catch (PrecondViolatedExcep e) {
			cout << e.what() << endl; // output exception string.
		}
	}
	return 0;
}