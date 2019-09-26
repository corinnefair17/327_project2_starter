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
//============================================================================
//	stuff you will need
//============================================================================
//TODO define a structure to track words and number of times they occur

struct entry {
	std::string word;
	int numberOccurrences;
};

//TODO add a global array of entry structs (global to this file)

entry entries [constants::MAX_WORDS];

//TODO add variable to keep track of next available slot in array

int nextIndex = 0;

//TODO define all functions in header file

// Zero out array that tracks words and their occurrences
void clearArray() {

}

// How many unique words are in array
int getArraySize() {

}

// Get data at a particular location
std::string getArrayWordAt(int i) {

}

// Get data at a particular location
int getArrayWord_NumbOccur_At(int i) {

}

/*
 * Loop through whole file, one line at a time
 * Call processLine on each line
 * Returns false: myfstream is not open
 *         true : otherwise
 */
bool processFile(std::fstream &myfstream) {

}

/*
 * Take 1 line and extract all the tokens from it
 * Feed each token to processToken for recording
 */
void processLine(std::string &myString) {

}

// Keep track of how many times each token is seen
void processToken(std::string &token) {

}

/*
 * If you are debugging, the file must be in the project parent directory
 * In this case Project2 with the .project and .cProject files
 */
bool openFile(std::fstream& myfile, const std::string& myFileName,
		std::ios_base::openmode mode) {

}

// Iff myfile is open then close it
void closeFile(std::fstream& myfile) {

}

/*
 * Serializes all content in myEntryArray to file outputfilename
 * returns  FAIL_FILE_DID_NOT_OPEN if cannot open outputfilename
 *          FAIL_NO_ARRAY_DATA is there are 0 entries in myEntryArray
 *          SUCCESS if all data is written and outputfilename closes OK
 */
int writeArraytoFile(const std::string &outputfilename) {

}

/*
 * Sort myEntryArray based on some enum value
 * You must provide a solution that handes alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so) {

}

//TODO look in utilities.h for useful functions, particularly strip_unwanted_chars!
