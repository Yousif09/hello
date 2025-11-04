/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-10-30
 *
 * Implementing several functions that involve operations on strings
 *
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 #include "string_utils.h"


 void replaceChar(char *s, char oldChar, char newChar) {
    if(s == NULL) {
        return;
    }
    if(oldChar == newChar) {
        return;
    }

    int i = 0;
    while(s[i] != '\0') {
        if(s[i] == oldChar) {
            s[i] = newChar;
        }
        i++;
    }

 }



 char * replaceCharCopy(const char *s, char oldChar, char newChar) {
    if(s == NULL) {
        return NULL;
    }
   
    char *newString = (char *) malloc( sizeof(char) * (strlen(s) + 1) );

    int i=0;
    while(s[i] != '\0') {
        if(s[i] == oldChar) {
            newString[i] = newChar;
        } else {
            newString[i] = s[i];
        }

        i++;
    }
    newString[i] = '\0';
    return newString;

 }


 void removeChar(char *s, char c) {
    if(s == NULL) {
        return;
    }

    int i = 0;
    while(s[i] != '\0') {
        if(s[i] == c) {
            for(int k=i; k < strlen(s); k++) {
                s[k] = s[k + 1];

            }

        } else {
            i++;
        }


    }
 }


 char * removeCharCopy(const char *s, char c) {
    if(s == NULL) {
        return NULL;
    }

    int count = 0;
    for(int i=0; s[i] != '\0'; i++) {
        if(s[i] != c) {
            count++;
        }

    }

    char *newString = (char *) malloc((count + 1) * sizeof(char));

    int i=0;
    int j=0;

    while(s[i] != '\0') {
            if(s[i] != c) {
                newString[j] = s[i];
                j++;
            }
            i++;

        }
        newString[j] = '\0';
        return newString;


    }






    char **lengthSplit(const char *s, int n) {
        if(s == NULL) {
            return NULL;
        }
        if(n <= 0) {
            return NULL;
        }


        int strLength = strlen(s);
        int splitStr = (strLength + n - 1) / n;

        char **newString = (char **) malloc(splitStr * sizeof(char *));

        int splitIndex = 0;
        for(int i=0; i < strLength; i+=n) {
                int remainingChar = strLength - i;
                int splitLength;

                if(remainingChar < n) {
                    splitLength = remainingChar;
                } else {
                    splitLength = n;
                }

                newString[splitIndex] = (char *) malloc((splitLength + 1) * sizeof(char ));
                strncpy(newString[splitIndex], s+i, splitLength);
                newString[splitIndex][splitLength] = '\0';
                splitIndex++;

        }

        return newString;

    }




