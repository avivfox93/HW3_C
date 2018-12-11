/*
 * main.c
 *
 *  Created on: 10 Dec 2018
 *      Author: aviv
 */


#include <stdio.h>
#include "utils.h"

enum selection{
	EXIT = 0,
	READ_CITY,
	SHOW_CITY,
	SHOW_GARDEN,
	WRITE_CITY,
	ADD_GARDEN,
	ADD_CHILD,
	CHILD_BIRTHDAY,
	COUNT_GRADUATE
};

int menu()
{
	int option;
	printf("\n==========================\n");
	printf("Select\n\n");
	printf("%8d. Read City information from file.\n", READ_CITY);
	printf("%8d. Show all Kindergartens.\n", SHOW_CITY);
	printf("%8d. Show a specific Kindergarten.\n", SHOW_GARDEN);
	printf("%8d. Save City information to file.\n", WRITE_CITY);
	printf("%8d. Add a Kindergarten.\n", ADD_GARDEN);
	printf("%8d. Add a Child.\n", ADD_CHILD);
	printf("%8d. Birthday to a Child.\n", CHILD_BIRTHDAY);
	printf("%8d. Count Hova childrens\n", COUNT_GRADUATE);
	printf("%8d. Exit\n", EXIT);
	scanf("%d",&option);
	return option;
}

int main()
{
	City utz = { NULL,0 };
	int uReq;

	//first time read
	readCity(&utz);
	do
	{
		uReq = menu();
		switch (uReq)
		{
		case  READ_CITY:
			readCity(&utz);
			break;

		case  SHOW_CITY:
			showCityGardens(&utz);
			break;

		case  SHOW_GARDEN:
			showSpecificGardenInCity(&utz);
			break;

		case  WRITE_CITY:
			saveCity(&utz);
			break;

		case  ADD_GARDEN:
			cityAddGarden(&utz);
			break;

		case  ADD_CHILD:
			addChildToSpecificGardenInCity(&utz);
			break;

		case  CHILD_BIRTHDAY:
			birthdayToChild(&utz);
			break;

		case COUNT_GRADUATE:
			printf("There are %d children going to school next year\n",countChova(&utz));
			break;

		}
	}while (uReq!=EXIT);

	ReleaseCity(&utz);//free all allocations

	return 1;
}
