/*
[Title] Length Of Last Word
[Level] Easy
[Acceptance] 32.5%
[DATE] June. 20. 2020
[TIME] 3:00PM ~ 3:15PM (15m) 

[Questions]
Given a string s consists of upper/lower-case alphabets and empty space characters ' ', return the length of last word (last word means the last appearing word if we loop from left to right) in the string.
If the last word does not exist, return 0.
Note: A word is defined as a maximal substring consisting of non-space characters only.

[Example Output & Input]
- Input: "Hello World"
- Output: 5
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
    int i, j;
    int length;

    //print input strings
    printf("Input: ");
    for(i=1; i<argc; i++){
        printf("%s ", argv[i]);    
    }
    printf("\n");

    //print result(length of last words)
    length = strlen(argv[(argc-1)]);
    printf("Output: %d\n", length);
}

