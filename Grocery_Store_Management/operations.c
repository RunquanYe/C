/*****************************************************************
 * Define all of the functions for the store management system
 * @author: Runquan Ye
 * @version: Winter 2018
 ****************************************************************/

#include "operations.h"

/***************************************************************************
 * build a node
 * @param: string product name
 * @param: float product quantity
 * @param: string product name
 * @param: float product price
 * @param: string product price unit
 * @return: object create a new node
 **************************************************************************/
product *buildNode(char pname[], float pquantity, char pquantity_unit[], float pprice, char pprice_unit[])
{
	product *p = (product *)malloc(sizeof(product));

	strcpy(p->name, pname);
	p->quantity_value = pquantity;
	strcpy(p->quantity_unit, pquantity_unit);
	p->price_value = pprice;
	strcpy(p->price_unit, pprice_unit);

	if (p == NULL)
	{
		puts("InbuildNode: Memory Allocation Failed!");
		return NULL;
	}

	return p;
}

/***************************************************************************
 * insert a node to the list
 * @param: object pointer-pointer l
 * @param: object node
 * @return: integer 1 for true; 0 for false
 **************************************************************************/
int insert(product **l, product *node)
{
	product *current = *l;

	product *tmp = (product *)malloc(sizeof(product));

	strcpy(tmp->name, node->name);
	tmp->quantity_value = node->quantity_value;
	strcpy(tmp->quantity_unit, node->quantity_unit);
	tmp->price_value = node->price_value;
	strcpy(tmp->price_unit, node->price_unit);

	if (current == NULL)
	{
		*l = tmp;
		return 1;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
		return 1;
	}
}

/***************************************************************************
 * remove a node from list
 * @param: object pointer l
 * @param: object pointer node
 **************************************************************************/
void rmItem(product **l, char p[])
{
	product *current = *l;
	product *previous = current;
	while (current != NULL)
	{
		if ((current->name) == p)
		{
			if (previous == current)
				*l = (current->next);
			else
				previous->next = current->next;

			free(current);
			return;
		}
		previous = current;
		current = current->next;
	}
}

/***************************************************************************
 * show list
 * @param: object pointer l
 **************************************************************************/
void showList(product *l)
{
	if (l == NULL)
	{
		puts("The store does not have any products yet.");
	}
	else
	{
		printf("* The product is: %s\n", l->name);
		printf("* The product's quantity value: %f\n", l->quantity_value);
		printf("* The product's quantity unit: %s\n", l->quantity_unit);
		printf("* The product's price: %f\n", l->price_value);
		printf("* The product's price unit: %s\n", l->price_unit);
		printf("-------------------------------------------------\n");

		if (l->next != NULL)
		{
			showList(l->next);
		}
	}
}

/***************************************************************************
 * load data from file inf
 * @param: char array inf
 * @param: object pointer-pointer l
 * @return: integer
 **************************************************************************/
int loadData(char inf[], product **l)
{
	char pname[N], pquantity_unit[N], pprice_unit[N];
	float pquantity, pprice;
	int readitem;

	product *head = *l;

	FILE *fin = fopen(inf, "r");

	if (fin == NULL)
	{
		printf("In Load: File open failed (%s)\n", inf);
		return 0;
	}

	while (1)
	{
		readitem = fscanf(fin, "%s %f %s %f %s\n", pname, &pquantity, pquantity_unit, &pprice, pprice_unit);
		if (readitem < 5)
		{
			break;
		}
		if (*l == NULL)
		{
			*l = buildNode(pname, pquantity, pquantity_unit, pprice, pprice_unit);
		}
		else
		{
			insert(l, buildNode(pname, pquantity, pquantity_unit, pprice, pprice_unit));
		}
	}
	fclose(fin);
	return 0;
}

/***************************************************************************
 * save data to file outf
 * @param: char array outf
 * @param: object pointer l
 * @return: integer
 **************************************************************************/
int saveData(char outf[], product *l)
{
	FILE *fout = fopen(outf, "w");
	if (fout == NULL)
	{
		printf("In Save: File open failed (%s)\n", outf);
		return 0;
	}

	product *tmp = l;

	while (tmp != NULL)
	{
		fprintf(fout, "%s %f %s %f %s\n", tmp->name, tmp->quantity_value, tmp->quantity_unit, tmp->price_value, tmp->price_unit);
		tmp = tmp->next;
	}

	fclose(fout);
}

/***************************************************************************
 * sell product product of quantity q
 * @param: object pointer l
 * @param: char array product
 * @param: float q
 * @return: float
 **************************************************************************/
float purchase(product *l, char pname[], float q)
{

	product *temp = l;
	temp = findItem(l, pname);
	if (temp != NULL)
	{
		if (q > temp->quantity_value)
		{
			return 0;
		}
		else
		{
			temp->quantity_value = (temp->quantity_value) - q;
			return (q * (temp->price_value));
		}
	}
	else
	{
		return 0;
	}
}

/***************************************************************************
 * check out price of product p from list l
 * @param: object pointer l
 * @param: char array p
 * @return: integer for found match product's sell price
 **************************************************************************/
float check_price(product *l, char p[])
{
	product *temp = l;

	while (temp != NULL)
	{
		if (strcmp((temp->name), p) == 0)
		{
			printf("The price for the %s is: %f\n", (temp->name), (temp->price_value));
			return temp->price_value;
		}

		temp = temp->next;
	}
	return 0;
}

/***************************************************************************
 * find a product p from list l
 * @param: object pointer l
 * @param: char array p
 * @return: object pointer for found match product
 **************************************************************************/
product *findItem(product *l, char p[])
{
	product *temp = l;

	while (temp != NULL)
	{
		if (strcmp((temp->name), p) == 0)
		{
			printf("Found the product (%s), you are searching for.\n", temp->name);
			return temp;
		}
		temp = temp->next;
	}
	return NULL;
}

/***************************************************************************
 * display the Store Application Menu
 **************************************************************************/
void displayMenu()
{
	puts("Welcome to Runquan Ye Grocery Store!");
	puts("Please let me know what you want to do by typing one of the number");
	puts("==================================================================");
	puts("1: Add product to store			2: Purchase product from store");
	puts("3: Check price of a product		4: Show products in store");
	puts("5: Clean up a product from store	6: Find product");
	puts("7: Inventory				8: Done for today");
}

/***************************************************************************
 * the job starts here, start with loading data from the file data
 * and perform the functions by calling related functions.
 * Ends at saving data to the file data.
 * @param: char array data
 * @return: integer
 **************************************************************************/
int doIt(char data[])
{
	product *head = NULL, *p;
	int choice, done = 0;
	float tmp, quantity, price, revenues = 0;
	char input[N], unit[N], priceUnit[N];
	system("clear");

	loadData(data, &head);

	while (!done)
	{
		displayMenu();
		puts("What is your command?");
		fflush(stdin);
		scanf("%d", &choice);
		fflush(stdin);

		switch (choice)
		{
		case 1:
			printf("1: Add product to store\n");
			puts("What item you want to add into the store?");
			fflush(stdin);
			scanf("%s", input);
			fflush(stdin);

			p = findItem(head, input);

			puts("How many/much you want to add into the store?");
			fflush(stdin);
			scanf("%f", &quantity);
			fflush(stdin);

			if (p == NULL && quantity > 0)
			{
				puts("What is the quantity unit of the item you want to add into the store?");
				fflush(stdin);
				scanf("%s", unit);
				fflush(stdin);

				puts("How much you want to sell that?");
				fflush(stdin);
				scanf("%f", &price);
				fflush(stdin);

				puts("What is the price unit of the item you want to add into the store?");
				fflush(stdin);
				scanf("%s", priceUnit);
				fflush(stdin);

				insert(&head, buildNode(input, quantity, unit, price, priceUnit));
			}
			else if (p != NULL && quantity > 0)
			{
				p->quantity_value += quantity;
				printf("Add %f of %s into the store.\n", quantity, p->name);
			}
			else
			{
				puts("Your command has error");
			}
			puts("**********************************************************************");
			break;
		case 2:
			printf("2: Purchase product from store\n");
			puts("What item you want to buy?");
			fflush(stdin);
			scanf("%s", input);
			fflush(stdin);
			p = findItem(head, input);
			if (p != NULL)
			{
				puts("How many you want to buy?");
				fflush(stdin);
				scanf("%f", &tmp);
				fflush(stdin);

				if (tmp <= (p->quantity_value))
				{
					revenues = revenues + purchase(head, input, tmp);
					printf("Process finished! You paid %f %s for %f %s of the %s\n", revenues, p->price_unit, tmp, p->quantity_unit, p->name);
					if ((p->quantity_value) == 0)
					{
						printf("%s has been all sell out!!!\n", p->name);
						rmItem(&head, p->name);
					}
				}
				else
				{
					printf("Sorry, we only have %f %s for %s now. Please remake your order.\n", p->quantity_value, p->quantity_unit, p->name);
				}
			}
			else
			{
				puts("Sorry! We don't have this product in the store.\n");
			}
			puts("**********************************************************************");
			break;
		case 3:
			printf("3: Check price of a product\n");
			puts("What item you are looking for?");
			fflush(stdin);
			scanf("%s", input);
			fflush(stdin);

			p = findItem(head, input);

			if (p != NULL)
			{
				check_price(head, input);
			}
			else
			{
				puts("Sorry! We don't have such item!!!");
			}
			puts("**********************************************************************");
			break;
		case 4:
			printf("4: Show products in store\n");
			showList(head);
			puts("**********************************************************************");
			break;
		case 5:
			printf("5: Clean up a product from store\n");
			puts("What item you want to be removed?");
			fflush(stdin);
			scanf("%s", input);
			fflush(stdin);

			p = findItem(head, input);

			if (p != NULL)
			{
				rmItem(&head, p->name);
				puts("The item has been removed!!!");
			}
			else
			{
				puts("Sorry! The store no longer has that item!!!");
			}
			puts("**********************************************************************");
			break;
		case 6:
			printf("6: Find product\n");
			puts("What item you are looking for?");
			fflush(stdin);
			scanf("%s", input);
			fflush(stdin);

			p = findItem(head, input);

			if (p != NULL)
			{
				printf("* The product is: %s\n", p->name);
				printf("* The product's quantity value: %f\n", p->quantity_value);
				printf("* The product's quantity unit: %s\n", p->quantity_unit);
				printf("* The product's price: %f\n", p->price_value);
				printf("* The product's price unit: %s\n", p->price_unit);
			}
			else
			{
				puts("Sorry! We don't have such item!!!");
			}
			printf("-------------------------------------------------\n");
			puts("**********************************************************************");
			break;
		case 7:
			printf("7: Inventory\n");
			printf("The current daily revenues for this store is: %f dollars.\n", revenues);
			puts("There still have these items available for you in the store!");
			showList(head);
			puts("**********************************************************************");
			break;
		case 8:
			printf("8: Done for today\n");
			saveData(data, head);
			puts("Thank you! Bye!");
			puts("**********************************************************************");
			done = 1;
			break;
		}
	}
	return 0;
}