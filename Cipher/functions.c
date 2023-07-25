/*****************************************************************
 * Define all of the functions for the cipher encrypt and decrypt 
 * @author: Runquan Ye
 * @version: Winter 2018
 ****************************************************************/

#include "functions.h"
#define MAX 26



/***************************************************************************
 * remove duplicate characters in array word and return the resulting string
 * @param: character array
 * @return: word  A string has already be remove duplicate letters 
 **************************************************************************/
char* removeDuplicates(char word []){	
	int i, position;
	char* temp = (char *) malloc((strlen(word) + 1) * sizeof(char));
	strcpy(temp, word);
	if (strlen(word) < 2)
	{
		free(temp);
		return word;
	}
	position = 1;
	for (i = 1; i < strlen(word); i++){
		if(targetFound(word, position, temp[i]) == 0){
			word[position] = temp[i];
			position++;
		}	
	}
	word[position] = '\0';
	free(temp);
	return word;
}



/**************************************************************************
 * search the first num characters in array charArray for character target
 * return a non-zero integer if found, otherwise, return 0
 * @param: charArray for input character array
 * @param: num for the size of input character array
 * @param: target for the search target
 * @return: 1 if found the target or 0 if doesn't found the target 
 *************************************************************************/
int targetFound(char charArray[], int num, char target){
	int i;
	for (i = 0; i < num; i++){
		if(charArray[i] == target){
			return 1;
		}
	}
	return 0;
}



/*****************************************************************************************
 * Initialize the encrypt array with appropriate cipher letters according to the given key
 * @param: key for input character array
 * @param: encrypt for input character array
 ****************************************************************************************/
void initializeEncryptArray(char key[], char encrypt[]){

	char* temp = (char *)malloc(27 * sizeof(char));

	temp = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

	strcpy(encrypt, key);
	
	strcat(encrypt, temp);

	removeDuplicates(encrypt);
}



/*****************************************************************************************
 * Initialize decrypt array with appropriate substitute letters based on the encrypt array
 * @param: decrypt for input character array
 * @param: encrypt for input character array
 ****************************************************************************************/
void initializeDecryptArray(char encrypt[], char decrypt[]){
	int i;	

	char temp[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

	for (i = 0; i < strlen(encrypt); i++){
		decrypt[encrypt[i] - 'A'] = temp[i];
	}

	decrypt[27] = '\0';
}



/**************************************************************************
 * process data from the input file and write the result to the output file
 * pass the encrypt array to parameter substitute if encryption is intended
 * pass the decrypt array to parameter substitute if decryption is intended
 * @param: inf for input FILE
 * @param: outf for output FILE
 * @param: substitute for input character array
 *************************************************************************/
void processInput(FILE * inf, FILE * outf, char substitute[]){
	char ch;

	while ( fscanf(inf, "%c", &ch) != EOF )
	{
		if (isupper(ch)){
			ch = substitute[ch -'A'];
		}

		fprintf(outf, "%c", ch);
	
	}
	 
}
