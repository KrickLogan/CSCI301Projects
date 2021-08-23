/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project6\
Due Date: 10/26/18
Instructor: Jie Hu Meichsner
*/

#ifndef CALCULATOR_
#define CALCULATOR_
#include <string>
#include <stdexcept>
#include "PrecondViolatedExcep.h"

class Calculator {
private:

public:
	Calculator();
	bool isBalanced(std::string expr) throw(PrecondViolatedExcep);
	std::string InfixToPostfix(std::string expr);
	bool isOperand(char c);
	bool isOperator(char c);
	int precedence(char op);
	bool checkHigherPrecedence(char op1, char op2);
	int solvePostfix(std::string expr);
};
#include "calculator.cpp"
#endif