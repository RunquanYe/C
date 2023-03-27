#ifndef H_CIPHERFUNCTION
#define H_CIPHERFUNCTION

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*****************************************************************
 * Define all of the functions for the cipher encrypt and decrypt 
 * @author: Runquan Ye
 * @version: Winter 2018
 ****************************************************************/

// remove duplicate characters in array word and return the resulting string
char * removeDuplicates(char word []);


// search the first num characters in array charArray for character target
// return a non-zero integer if found, otherwise, return 0
int targetFound(char charArray[], int num, char target);


// initialize the encrypt array with appropriate cipher letters according to the given key
void initializeEncryptArray(char key[], char encrypt[]);


// initialize decrypt array with appropriate substitute letters based on the encrypt array
void initializeDecryptArray(char encrypt[], char decrypt[]);

// process data from the input file and write the result to the output file
// pass the encrypt array to parameter substitute if encryption is intended
// pass the decrypt array to parameter substitute if decryption is intended
void processInput(FILE * inf, FILE * outf, char substitute[]);

#endif
