/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-11-06
 *
 * Implementing functions that involve operations on files.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "file_utils.h"

char *getFileContents(const char *filePath) {
    if(filePath == NULL) {
        return NULL;
    }


    int c;
    int counter = 0;

    FILE *f = fopen(filePath, "r");
    if(f == NULL) {
        return NULL;
    }

    c = fgetc(f);
    while(c != EOF) {
        counter++;
        c = fgetc(f);
    }

    rewind(f);


    char *fileContents = (char*) malloc((counter + 1) * sizeof(char));
    if(fileContents == NULL) {
        fclose(f);
        return NULL;
    }



    int i=0;
    c = fgetc(f);
    while(c != EOF) {
        fileContents[i] = c;
        i++;
        c = fgetc(f);
    }
    fileContents[i] = '\0';
    fclose(f);
    return fileContents;

}



char **getFileLines(const char *filePath, int *numLines) {
    if(filePath == NULL || numLines == NULL) {
        return NULL;
    }

    FILE *f = fopen(filePath, "r");
    if(f == NULL) {
        return NULL;
    }

    int c;
    int linesCount = 0;

    c = fgetc(f);
    while(c != EOF) {
        if(c=='\n') {
            linesCount++;
        }
        c = fgetc(f);
    }
    rewind(f);

    char **lines = (char**) malloc(linesCount * sizeof(char*));
    if(lines == NULL) {
        return NULL;
    }

    int lineindex = 0;
    char buffer[2001];

    char *result = fgets(buffer, sizeof(buffer), f);
    while(result != NULL) {
        int length = 0;
        while(buffer[length] != '\0' && buffer[length] != '\n' && buffer[length] != '\r') {
            length++;
        }
        buffer[length] = '\0';

        lines[lineindex] = (char*) malloc((length + 1)* sizeof(char));
        if(lines[lineindex] == NULL) {
            return NULL;
        }

        for(int i=0; i <= length; i++) {
            lines[lineindex][i] = buffer[i];
        }
        lineindex++;

        result = fgets(buffer, sizeof(buffer), f);


    }
    fclose(f);
    *numLines = lineindex;
    return lines;


}
