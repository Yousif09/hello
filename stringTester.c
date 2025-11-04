/**
 *
 * Yousif Alboufradi, Mason Melcher
 * 2025-10-30
 *
 * Tester file for our string function prototypes
 *
 */


 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include "string_utils.h"


 int main(int argc, char **argv) {



// replaceChar tester

char s1a[] = "hello";
replaceChar(s1a, 'l', 'z');
printf("%s\n", s1a);


char s2a[] = "racecar";
replaceChar(s2a, 'r', 'x');
printf("%s\n", s2a);

char s3a[] = "world";
replaceChar(s3a, 'l', 'e');
printf("%s\n", s3a);




// replaceCharCopy tester

char *s1b = replaceCharCopy("Yousif", 'o', 'e');
printf("%s\n", s1b);
free(s1b);

char *s2b = replaceCharCopy("Likes", 'k', 'x');
printf("%s\n", s2b);
free(s2b);

char *s3b = replaceCharCopy("Cats", 'a', 'o');
printf("%s\n", s3b);
free(s3b);


// removeChar tester

char s1c[] = "hello";
removeChar(s1c, 'l');
printf("%s\n", s1c);


char s2c[] = "racecar";
removeChar(s2c, 'r');
printf("%s\n", s2c);

char s3c[] = "world";
removeChar(s3c, 'l');
printf("%s\n", s3c);



// removeCharCopy tester

char *s1d = removeCharCopy("Yousif", 'o');
printf("%s\n", s1d);
free(s1d);

char *s2d = removeCharCopy("Likes", 'k');
printf("%s\n", s2d);
free(s2d);

char *s3d = removeCharCopy("Cats", 'a');
printf("%s\n", s3d);
free(s3d);


// lengthSplit tester

char **s1e = lengthSplit("YousifLikesCats", 3);
int strLeng = strlen("YousifLikesCats");
int n = 3;
int split = (strLeng + n -1) / n;

for(int i=0; i < split; i++) {
    printf("%s\n", s1e[i]);
    free(s1e[i]);
}
free(s1e);


char **s2e = lengthSplit("Hello World, how are you?", 3);
int strLeng1 = strlen("Hello World, how are you?");
int n1 = 3;
int split1 = (strLeng1 + n1 -1) / n1;

for(int i=0; i < split1; i++) {
    printf("%s\n", s2e[i]);
    free(s2e[i]);
}
free(s2e);


char **s3e = lengthSplit("I am good", 3);
int strLeng2 = strlen("I am good");
int n2 = 3;
int split2 = (strLeng2 + n2 -1) / n2;

for(int i=0; i < split2; i++) {
    printf("%s\n", s3e[i]);
    free(s3e[i]);
}
free(s3e);

return 0;
}