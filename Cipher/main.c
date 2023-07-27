/*****************************************************************
 * Main function for running the cipher programe
 * @author: Runquan Ye
 * @version: Winter 2018
 ****************************************************************/
#include "functions.h"

int main(int argc, char *argv[])
{

	FILE *fin, *fout;
	char choice;
	char *encrypt = (char *)malloc(27 * sizeof(char));
	char *decrypt = (char *)malloc(27 * sizeof(char));
	char *key = (char *)malloc(sizeof(argv[2]) * sizeof(char));

	choice = *argv[1];

	strcpy(key, argv[2]);

	fin = fopen(argv[3], "r");

	fout = fopen(argv[4], "w");

	if (argc != 5)
	{
		printf("Function d for decryption and e for encryption");
		exit(1);
	}

	if (fin == NULL || fout == NULL)
	{
		printf("File could not be opened\n");
		exit(1);
	}

	initializeEncryptArray(key, encrypt);

	initializeDecryptArray(encrypt, decrypt);

	if (choice == 'd')
	{
		processInput(fin, fout, decrypt);
	}

	if (choice == 'e')
	{
		processInput(fin, fout, encrypt);
	}

	fclose(fin);
	fclose(fout);

	return 0;
}
