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

	std::string line;
	while (!myfstream.eof()) {
		getline(myfstream, line);
		processLine(line);
	}
	return true;
}

/*
 * Take 1 line and extract all the tokens from it
 * Feed each token to processToken for recording
 */
void processLine(std::string &myString) {
	std::stringstream ss(myString);
	std::string tempToken;

	while (std::getline(ss, tempToken, constants::CHAR_TO_SEARCH_FOR)) {
		processToken(tempToken);
	}
}

// Keep track of how many times each token is seen
void processToken(std::string &token) {
	bool found = false;
	bool notEmpty = strip_unwanted_chars(token);
	std::string tokenCopy = token;
	toUpper(tokenCopy);
	for (int i = 0; i < nextIndex; i++) {
		std::string entryCopy = entries[i].word;
		toUpper(entryCopy);
		if (tokenCopy == entryCopy) {
			found = true;
			entries[i].numberOccurrences++;
		}
	}
	if (!found && notEmpty) {
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
	return myfile.good();
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
	if (nextIndex == 0) {
		return constants::FAIL_NO_ARRAY_DATA;
	}
	std::ofstream myfile;
	myfile.open(outputfilename);
	if (myfile.fail()) {
		return constants::FAIL_FILE_DID_NOT_OPEN;
	}

	for (int i = 0; i < nextIndex; i++) {
		myfile << entries[i].word << " " << entries[i].numberOccurrences
				<< std::endl;
	}
	myfile.close();

	return constants::SUCCESS;
}

/*
 * Sort myEntryArray based on some enum value
 * You must provide a solution that handles alphabetic sorting (A-Z)
 * The presence of the enum implies a switch statement based on its value
 */
void sortArray(constants::sortOrder so) {
	switch (so) {
	case constants::ASCENDING:
		for (int i = 1; i < nextIndex; i++) {
			for (int j = 1; j < nextIndex; j++) {
				std::string firstEntry = entries[j - 1].word;
				toUpper(firstEntry);
				std::string secondEntry = entries[j].word;
				toUpper(secondEntry);
				if (firstEntry > secondEntry) {
					entry tempEntry;
					tempEntry.word = entries[j - 1].word;
					tempEntry.numberOccurrences =
							entries[j - 1].numberOccurrences;
					entries[j - 1] = entries[j];
					entries[j] = tempEntry;
				}
			}
		}
		break;
	case constants::DESCENDING:
		for (int i = 1; i < nextIndex; i++) {
			for (int j = 1; j < nextIndex; j++) {
				std::string firstEntry = entries[j - 1].word;
				toUpper(firstEntry);
				std::string secondEntry = entries[j].word;
				toUpper(secondEntry);
				if (firstEntry < secondEntry) {
					entry tempEntry;
					tempEntry.word = entries[j - 1].word;
					tempEntry.numberOccurrences =
							entries[j - 1].numberOccurrences;
					entries[j - 1] = entries[j];
					entries[j] = tempEntry;
				}
			}
		}
		break;
	case constants::NUMBER_OCCURRENCES:
		for (int i = 1; i < nextIndex; i++) {
			for (int j = 1; j < nextIndex; j++) {
				if (entries[j - 1].numberOccurrences
						< entries[j].numberOccurrences) {
					entry tempEntry;
					tempEntry.word = entries[j - 1].word;
					tempEntry.numberOccurrences =
							entries[j - 1].numberOccurrences;
					entries[j - 1] = entries[j];
					entries[j] = tempEntry;
				}
			}
		}
		break;
	default:
		break;
	}
}

// look in utilities.h for useful functions, particularly strip_unwanted_chars!
