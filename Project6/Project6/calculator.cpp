/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project6\
Due Date: 10/26/18
Instructor: Jie Hu Meichsner
*/

#include <string>
#include "calculator.h"
#include "LinkedStack.h"
#include "PrecondViolatedExcep.h"
#include <stdexcept>


Calculator::Calculator()
{
}
/* ----- ORIGINAL ----- */
/* Determines if an expression's well-formed and has balanced parentheses, if not throw an exception
@pre pass an expression.
@post determines if expression has balanced parentheses and well-formed, otherwise throw exception *//*
bool Calculator::isBalanced(std::string expr) throw(PrecondViolatedExcep)
{
	int openPars = 0;
	for (int i = 0; i < expr.length(); i++) {
		if (expr[i] == '(')
			openPars++;
		if (expr[i] == ')')
			openPars--;
	}

	if (openPars == 0)
		return true;
	else {
		throw(PrecondViolatedExcep("Parentheses are not balanced. Please re-enter valid expression."));
	}
}*/

bool Calculator::isBalanced(std::string expr) throw(PrecondViolatedExcep) {
	StackInterface<char>* stackPtr = new LinkedStack<char>();

	for (int i = 0; i < expr.length(); i++) {
		if (expr[i] == '(') {
			stackPtr->push(expr[i]);
		}
		else if (expr[i] == ')') {
				stackPtr->pop();
		}

	}
	if(!stackPtr->isEmpty()) {
	throw(PrecondViolatedExcep("Parentheses are not balanced. Please re-enter valid expression."));
	}
}

/* Converts an infix expression to a postfix expression
@pre must pass an infix expression
@post converts and returns the postfix expression */
std::string Calculator::InfixToPostfix(std::string expr)
{
	StackInterface<char>* stackPtr = new LinkedStack<char>();
	std::string postfix = "";

	for (int i = 0; i < expr.length(); i++) {
		if (isOperator(expr[i])) {
			while (!stackPtr->isEmpty() && stackPtr->peek() != '(' && checkHigherPrecedence(stackPtr->peek(), expr[i])) {
				postfix += stackPtr->peek();
				stackPtr->pop();
			}
			stackPtr->push(expr[i]);
		}
		else if (isOperand(expr[i])) {
			postfix += expr[i];
		}
		else if (expr[i] == '(') {
			stackPtr->push(expr[i]);
		}
		else if (expr[i] == ')') {
			while (!stackPtr->isEmpty() && stackPtr->peek() != '(') {
				postfix += stackPtr->peek();
				stackPtr->pop();
			}
			stackPtr->pop();
		}
	}
	while (!stackPtr->isEmpty()) {
		postfix += stackPtr->peek();
		stackPtr->pop();
	}
	return postfix;
}

/* Checks if a character is an Operand, integer between 0 and 9.
@pre pass a character in.
@post determines if the input character is an operand. */
bool Calculator::isOperand(char c)
{
	if (c >= '0' && c <= '9')
		return true;

	return false;
}

/* Checks if a character is an Operator, +, -, *, or /.
@pre pass a character in.
@post determines if the input character is an operator. */
bool Calculator::isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/')
		return true;

	return false;
}

/* Returns a precedence value of an operator.
@pre pass an operator character in.
@post returns a precedence value of operator. */
int Calculator::precedence(char op)
{
	switch (op) {
		case '+': return 1;
		case '-': return 1;
		case '*': return 2;
		case '/': return 2;
	}
	return 0;
}

/* Determines which of two operator characters have higher precedence.
@pre pass two operator characters in.
@post determines which of the two operators have higher precedence. */
bool Calculator::checkHigherPrecedence(char op1, char op2)
{
	int op1Prec = precedence(op1);
	int op2Prec = precedence(op2);

	return op1Prec > op2Prec ? true : false;
}

/* Calculates the solution of a postfix expression.
@pre pass a postfix expression in.
@post returns solution of postfix expression. */
int Calculator::solvePostfix(std::string expr)
{
	StackInterface<char>* stackPtr = new LinkedStack<char>();
	int val = 0;

	for (int i = 0; i < expr.length(); i++) {
		if (isOperand(expr[i])) {
			stackPtr->push(expr[i]-'0');
		}
		else if (isOperator(expr[i])) {
			int element1 = stackPtr->peek();
			stackPtr->pop();
			int element2 = stackPtr->peek();
			stackPtr->pop();

			switch (expr[i]) {
			case '+':
				val = element2 + element1;
				stackPtr->push(val);
				break;
			case '-':
				val = element2 - element1;
				stackPtr->push(val);
				break;
			case '*':
				val = element2 * element1;
				stackPtr->push(val);
				break;
			case '/':
				val = element2 / element1;
				stackPtr->push(val);
				break;
			default:
				return 0;
			}
		}
	}

	return val;
}
