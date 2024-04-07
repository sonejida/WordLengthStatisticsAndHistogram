#include <stdio.h>
#include "fileInput.h"

// ** Do not make any changes to this file **

// Reads a text file into a char array (string).
// 'fileName' is the name of the text file to read.
// 'textStr' returns the text from the file as a string. You must pass
//           a char array that is large enough to hold the entire file.
//           Use MAX_FILE when declaring the array.
// Return value: Returns the number of characters read, or -1 on errors.
// Example calling sequence:
//    char str[MAX_FILE];
//    int len = readFile("wonder.txt", str);
//    if (len == -1) {
//        printf("An error occurred\n");
//    }
//    else {
//        // Process the characters in 'str' here
//    }
int readFile(const char fileName[], char textStr[]) 
{
    FILE* fptr;
    char ch;
    int size = 0;

    // Open the file for reading
    if ((fptr = fopen(fileName, "r")) == NULL) {
        fprintf(stderr, "Error, failed to open %s: ", fileName);
        perror("");
        return -1;
    }

    // Read the entire file and place it in 'textStr'
    while ((ch = fgetc(fptr)) != EOF) {
        if (size == MAX_FILE - 1)
            break;
        textStr[size++] = ch;
    }

    // Ensure the string is null-terminated
    textStr[size] = '\0';

    // Close the file
    fclose(fptr);
    
    return size;
}

