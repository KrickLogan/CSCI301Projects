/*
Author: Logan Krick
Course and Section: CSCI 301 Sec 1
StarID: pq8748xu
File Location on the server: CourseFiles\Fall2018\jhu\CSCI301s01_301s02_301s54_591s01\StudentWorkFolder\pq8748xu\Project5\Part2\
Due Date: 10/16/18
Instructor: Jie Hu Meichsner
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool checkCorrect(const string anEntry);

vector<string> dict; // vector to hold all the correct words from dictionary file.

int main() {
	vector<string> checkWords; // vector to hold all the words to be checked
	vector<string> incorrectWords; // vector to hold all incorrect words
	string checkFile, word;
	string dictFile = "dictionary.txt";

	// Read from "dictionary.txt" and add each word to the vector dict.
	ifstream dictionary(dictFile.c_str());
	if (!dictionary) {
		std::cout << "Unable to open file: dictionary.txt" << endl << "The program will now terminate" << endl;
		return 0;
	}
	else if (dictionary) {
		while (getline(dictionary, word)) {
			dict.push_back(word);
		}
	}
	dictionary.close();

	// Ask user for the filename of a list of words to be checked.
	std::cout << "Enter the name of the file that contains words to check: ";
	cin >> checkFile;
	std::cout << endl;

	// Read from user inputted filename and add each word to the vector checkWords.
	ifstream wordsToCheck(checkFile.c_str());
	if (!wordsToCheck)
		std::cout << "Unable to open file: " << checkFile << endl;
	else if (wordsToCheck) {
		while (getline(wordsToCheck, word)) {
			checkWords.push_back(word);
		}
	}
	wordsToCheck.close();
	
	// Check if words are incorrect or not
	// If incorrect add the incorrect string to the vector, incorrectWords.
	int size = checkWords.size();
	for (int i = 0; i < size; i++) {
		if (!checkCorrect(checkWords[i])) {
			incorrectWords.push_back(checkWords[i]);
		}
	}

	// Display the incorrect words
	std::cout << endl << "The following words in file " << checkFile << " are spelled incorrectly: " << endl;
	int incorrectSize = incorrectWords.size();
	for (int i = 0; i < incorrectSize; i++)
		std::cout << incorrectWords[i] << endl;

		return 0;
}

	/* Given a string, anEntry, this function will determine if said string exists within the dict vector.
	@pre dict vector must contain values, must have a target to search for.
	@post determines whether the target, anEntry, is found within dict vector. */
bool checkCorrect(const string anEntry) {
	bool found = false;
	int dictSize = dict.size();

	for (int i = 0; !found && (i < dictSize); i++)
	{
		if (anEntry == dict[i])
		{
			found = true;
		}
	}

	return found;
}