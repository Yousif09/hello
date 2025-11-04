/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-10-30
 *
 * Header file for the string function prototypes
 *
 */



/**
 * replaces instances of a given character with a different
 * character in a string.
 */
 void replaceChar(char *s, char oldChar, char newChar);


/**
 * takes a string and creates a new copy of it but with instances
 * of a given character replaced wth a different character
 */
char * replaceCharCopy(const char *s, char oldChar, char newChar);


/**
 * takes a string and removes all instances of
 * a certain character from it
 */
void removeChar(char *s, char c);


/**
 * creates a new copy of a string but with all instances of a
 * specified character removed from it
 */
char * removeCharCopy(const char *s, char c);


/**
 * takes a string and splits it up to an array of strings. The split is
 * length-based (the function will take an integer n and will split the given string up into length n strings)
 *
 *
 */
char **lengthSplit(const char *s, int n);

