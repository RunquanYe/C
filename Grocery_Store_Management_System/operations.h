/**************************************************************************
 * Define all of the functions and headers for the store management system
 * @author: Runquan Ye
 * @version: Winter 2018
 ************************************************************************/
#ifndef _H_STORE_MANAGEMENT
#define _H_STORE_MANAGEMENT

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 200

struct product
{
  char name[N];
  float quantity_value;
  char quantity_unit[N];
  float price_value;
  char price_unit[N];
  struct product *next;
};

typedef struct product product;

/***************************************************************************
 * build a node
 * @param: string product name
 * @param: float product quantity
 * @param: string product name
 * @param: float product price
 * @param: string product price unit
 * @return: object create a new node
 **************************************************************************/
product *buildNode(char pname[], float pquantity, char pquantity_unit[], float pprice, char pprice_unit[]);

/***************************************************************************
 * insert a node to the list
 * @param: object pointer-pointer l
 * @param: object node
 * @return: integer
 **************************************************************************/
int insert(product **l, product *node);

/***************************************************************************
 * remove a node from list
 * @param: object pointer l
 * @param: object pointer node
 **************************************************************************/
void rmItem(product **l, char p[]);

/***************************************************************************
 * show list
 * @param: object pointer l
 **************************************************************************/
void showList(product *l);

/***************************************************************************
 * load data from file inf
 * @param: char array inf
 * @param: object pointer-pointer l
 * @return: integer
 **************************************************************************/
int loadData(char inf[], product **l);

/***************************************************************************
 * save data to file outf
 * @param: char array outf
 * @param: object pointer l
 * @return: integer
 **************************************************************************/
int saveData(char outf[], product *l);

/***************************************************************************
 * sell product product of quantity q
 * @param: object pointer l
 * @param: char array product
 * @param: float q
 * @return: float
 **************************************************************************/
float purchase(product *l, char product[], float q);

/***************************************************************************
 * check out price of product p from list l
 * @param: object pointer l
 * @param: char array p
 **************************************************************************/
float check_price(product *l, char p[]);

/***************************************************************************
 * find a product p from list l
 * @param: object pointer l
 * @param: char array p
 **************************************************************************/
product *findItem(product *l, char p[]);

/***************************************************************************
 * the job starts here, start with loading data from the file data
 * and perform the functions by calling related functions.
 * Ends at saving data to the file data.
 * @param: char array data
 * @return: integer
 **************************************************************************/
int doIt(char data[]);

/***************************************************************************
 * display the application menu
 **************************************************************************/
void displayMenu();

#endif