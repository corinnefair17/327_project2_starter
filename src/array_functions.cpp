/*
 * functionstocomplete.cpp
 *
 *  Created on: Sep 10, 2017
 *      Author: keith
 */

//============================================================================
//	TODO add necessary includes here
//============================================================================
#include <iostream>
#include "array_functions.h"
#include "utilities.h"
#include <sstream>
//============================================================================
//	stuff you will need
//============================================================================
// define a structure to track words and number of times they occur

struct entry {
	std::string word;
	int numberOccurrences;
};

// add a global array of entry structs (global to this file)

entry entries[constants::MAX_WORDS];

// add variable to keep track of next available slot in array

int nextIndex = 0;

//TODO define all functions in header file

// Zero out array that tracks words and their occurrences
void clearArray() {
	for (int i = 0; i < constants::MAX_WORDS; i++) {
		entries[i] = { "", 0 };
	}
	nextIndex = 0;
}

// How many unique words are in array
int getArraySize() {
	return nextIndex;
}

// Get data at a particular location
std::string getArrayWordAt(int i) {
	return entries[i].word;
}

// Get data at a particular location
int getArrayWord_NumbOccur_At(int i) {
	return entries[i].numberOccurrences;
}

/*
 * Loop through whole file, one line at a time
 * Call processLine on each line
 * Returns false: myfstream is not open
 *         true : otherwise
 */
bool processFile(std::fstream &myfstream) {
	if (!myfstream.is_open()) {
		return false;
	}

	return false;
}

/*
 * Take 1 line and extract all the tokens from it
 * Feed each token to processToken for recording
 */
void processLine(std::string &myString) {
	std::stringstream ss(myString);
	std::string tempToken;

	while(std::getline(ss, tempToken, constants::CHAR_TO_SEARCH_FOR)) {
		processToken(tempToken);
	}
}

// Keep track of how many times each token is seen
void processToken(std::string &token) {
	bool found = false;
	strip_unwanted_chars(token);
	for (int i = 0; i < nextIndex; i++) {
		if (token == entries[i].word) {
			found = true;
			entries[i].numberOccurrences++;
		}
	}
	if (!found && token != "") {
		entries[nextIndex].word = token;
		entries[nextIndex].numberOccurrences = 1;
		nextIndex++;
	}
}

/*
 * If you are debugging, the file must be in the project parent directory
 * In this case Project2 with the .project and .cProject files
 */
bool openFile(std::fstream &myfile, const std::string &myFileName,
		std::ios_base::openmode mode) {
	myfile.open(myFileName.c_str(), mode);
	return true;
}

// Iff myfile is open then close it
void closeFile(std::fstream &myfile) {
	if (myfile.is_open()) {
		myfile.close();
	}
}

/*
 * Serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 *          FAIL_NO_ARRAY_DATA is there are 0 entries in myEntryArray
 *          SUCCESS if all data is written and outputfilename closes OK
 */
int writeArraytoFile(const std::string &outputfilename) {
	return -10;
}

/*
 * Sort myEntryArray based on some enum value
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so) {

}

// look in utilities.h for useful functions, particularly strip_unwanted_chars!
