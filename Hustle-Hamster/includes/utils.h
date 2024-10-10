/**
 * @file utils.h
 * @author Abby Fernandes, Katelynn Wink
 * 
 * @brief File containing utility functions to be used throughout the application.
 * 
 * This file contains several functions, global variables, and preprocessor directives that are necessary for this application, but would clutter up the main file significantly.
 */

#pragma once

#include <fstream>
#include <limits>
#include <random>
#include <sys/stat.h>


#include "all_includes.h"

#define WIN32_LEAN_AND_MEAN // Necessary to remove ambiguity errors caused in windows.h library
#include <windows.h>
#include <conio.h>
#undef max // necessary for handling user input using the max function from <limits> as windows has a defined macro


/* The standard delay used for printing */
extern unsigned int stdDelay;
/* The Inital default activities */
extern vector<string> defaultActivities; 
/* Separator for formatting */
extern char separator[]; 

/**
 * Print the report for the given journal entry.
 *
 * @param journalEntry the daily Journal entry to print
*/
void printReport(Journal &journalEntry);

/**
 * Writes to the text file
 * 
 * @param journalEntry the journal entry to export.
 * @param ostream to write to 
*/
void writeToFile(std::ostream &file, Journal &journalEntry);


/**
 * Export the given journal entry to a text file.
 * 
 * @param journalEntry the journal entry to export.
 */
void exportJournal(Journal &journalEntry);

/**
 * Method to type out strings in terminal (animation)
 *
 * @param p string to print
 */
void TYPE(const string& p);

void delay(int time);

/**
 * Method to print generic Hammy the Hamster Friend.
 */
void printHammy();

/**
 * Method to print a happy Hammy the Hamster Friend.
 */
void printHammyHappy();

/**
 * Method to print a sad Hammy the Hamster Friend.
 */
void printHammySad();

/**
 * Prints the menu and calls method based on user input
 * 
 * (enter 0 for devs)
 * 
 * @see menuHelp.h
 */
void menu(); 

/**
 * Get the desktop path of the current user. 
 * 
 * @return The desktop path of the current user. Will throw an exception if there is an issue with obtaining the path.
 */
string getDesktopPath();

/////////////////////////////////
//Code From Stacknoverflow
//"https://stackoverflow.com/questions/38931856/disallow-input-at-certain-times"/>

/**
 * Disables input
*/
void disableInput(void);

/**
 * Enables input
*/
void enableInput(void);

/** 
 * Sets console mode
 * 
 * @param bit console mode flag to control behaviour
 * @param onElseOff boolean, off or on
*/
void setConsoleMode(DWORD bit, bool onElseOff);

/** 
 * Discard the input buffer that currently exists 
 * 
*/
void discardInputBuffer(); 

/**
 * Turns off Echo so user input is not seen in terminal
*/
void turnEchoOff(void);

/**
 * Turns on Echo so user can see their input
*/
void turnEchoOn(void);

/**
 * System will not wait for enter key to be pressed to continue
*/
void turnCanonOff(void);

/**
 * System will wait for enter key to be pressed to continue
*/
void turnCanonOn(void);

/**
* Get a random number from zero to the maximum value.
*
* Adapted from this Reddit post:
* https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
*
* @param max The maximum value (inclusive)
*/
int randomNumber(int max);

/**
* Create a directory called HamsterHangout on the user's desktop.
* 
*/
void createHamsterHangoutDirectory();

/**
 * Get file name for the daily journal.
 * 
 * Journals named in the format: "journal-{year}-{month}-{day}.txt"
 *
 * @return The file name for the  daily journal.
 */
string getFileName();

/**
* Check whether a file system item (such as a file or directory) exists with the given path. 
* 
* If checking a directory exists, ensure that the path ends with a forward or back slash, otherwise a file of the same name with no file extension would cause this method to return true. 
* 
* @return 1 (true) if the given item was found to exist, 0 (false) otherwise.
*/
bool itemExists(const string& path);

/**
 * Get the full path for the HamsterHangout directory on the user's desktop.
 *
 * @return The HamsterHangout path of the current use. Will throw an exception if there is an issue with obtaining the path.
 */
string getHamsterHangoutPath();

/**
* Check whether the user has opened Hamster Hangout before. 
* 
* This is based on whether the HamsterHangout directory exists on their desktop.
* 
* @return 1 (true) if this is the first time that they've opened the app, 0 (false) otherwise. Will throw an exception if there is an issue with obtaining the path of the desktop directory.
*/
bool isFirstOpen();

/**
* Check whether the user has already exported a journal entry today.
*
* This is based on whether the text file named based on the current date already exists.
*
* @return 1 (true) if they have already exported a journal entry today, 0 (false) otherwise. Will throw an exception if there is an issue with obtaining the path of the desktop directory.
*/
bool isFirstOfDay();

/**
* Read yes/no from user input. 
* 
* Only accepts "y"/"yes" or "n"/"no" (case insensitive).
* 
* @returns The characters 'y'/'n' based on word/character entered by the user.
*/
char readYN();

/**
* Read integer from user input.
*
* Only accepts integers within the specified range (inclusive).
* 
* @param min The minimum value allowable.
* @param max The maximum value allowable.
*
* @returns The integer entered by the user.
*/
int readInt(int min, int max);

/**
* Read string from user input.
* 
* Will only take the first line of user input. i.e. anything preceeding a '\n'.
* 
* Will also reject empty strings;
* 
* @returns The string entered by the user.
*/
string readString();

/**
* Read a single word from user input.
*
* Will also reject empty strings;
*
* @returns The word entered by the user.
*/
string readWord();

/**
* Convert a given string to lower case characters. 
* 
* @param s The string to convert. This variable will not be changed. 
* 
* @return The lower case version of the string.
*/
string stringToLower(const string& s);

/**
* Trim the trailing whitspace from a given string.
* 
* @param The string to trim. This variable will be changed. 
* 
* @return The trimmed string.
*/
string trim(string &s);