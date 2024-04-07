// Reflection:
// My experience during the completion of this programming assignment was pretty good. The things that I learned during the creation of this assignment were arrays mostly. 
//The most difficult task was to check whether a word has ended meaning it is not a letter, it took alot of time. Secondly when I started this assignment, 
//I didn't know how to run 2 c files together in a project. Then I wrote the readFile function in the same c source file so that I can run the file until it showed cannot 
//read file. This is the one of the problems I took a lot of time to figure out. Slowly thereafter I learned how to create a project and include both c files and rebuild all 
//at the same time to compile all files together. Then the other task was to print the histogram. The normalised histogram isn't yet properly coded as it prints 
//the number of x same as the number of words appearing of same word length and the output looks ugly. I tried to accomplish it but had to submit it as I had less time.


#include <stdio.h>
#include <string.h>
#include "fileInput.h" 

#define MAX_FILE 1000000
#define MAX_WORD_LENGTH 20

void processFile(const char textStr[], int size);
void printHistogram(const int counts[]);

int isLetter(char i) {
    return (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z');
}

//This is the main function which reads the file and processes the text of file
int main(int argc, char** argv) {
    char textStr[MAX_FILE]; 
    int len = readFile("wonder.txt", textStr);
    
    if (len == -1) { //It checks if the fileName is incorrect or cannot locate the file
        printf("An error occurred\n");
        
    }
    else //Processes file if it can read it successfully
    processFile(textStr, len);
    
    return 0;
}

//This function processes the file and counts the length of the words along with the 
void processFile(const char textStr[], int size) {
   int wordLengths[MAX_WORD_LENGTH + 1] = {0}; 
    int wlCounter = 0;
    int commonWl = 0;
    int shortestWl = MAX_WORD_LENGTH;
    int longestWl = 0;
    
    for (int i = 0; i < size; i++) { //Counts the length of the word and finds shortest, longest and common word lengths
        if (isLetter(textStr[i])) { 
            wlCounter++;
        } else { 
            if (wlCounter > 0 && wlCounter <= MAX_WORD_LENGTH) {
                wordLengths[wlCounter]++;
                if (wlCounter < shortestWl) {
                    shortestWl = wlCounter;
                }
                if (wlCounter > longestWl) {
                    longestWl = wlCounter;
                }
                if (wordLengths[wlCounter] > wordLengths[commonWl]) {
                    commonWl = wlCounter;
                }
            }
            wlCounter = 0; 
        }
    }
    
    // This function prints the histogram
    printHistogram(wordLengths);
 
    printf("\nStatistics are shown below:\n");
    printf("The most common word length in the given file is %d\n", commonWl);
    printf("The shortest word length in the given file is %d\n", shortestWl);
    printf("The longest word length in the given file is %d\n", longestWl);
}

//This function prints the histogram. Pass it the word length counts array.
void printHistogram(const int counts[]) {
    printf("Word length counts:\n");
    for (int i = 1; i <= MAX_WORD_LENGTH; i++) {//Prints the number of counts of the word lengths
        printf("%d  ", i);
        for (int j = 0; j < counts[i]; j++) { //prints the x for the number of counts
            printf("x");
        }
        printf(" %d\n", counts[i]);
    }
    
}



