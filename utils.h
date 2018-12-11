/*
 * utils.h
 *
 *  Created on: 10 Dec 2018
 *      Author: aviv
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "string_utils.h"

#define FILENAME "DataFile.txt"
#define GARDEN_NAME_LENGTH 32

typedef enum gartype{
	CHOVA,
	TROM_CHOVA,
	TROM_TROM_CHOVA
}garden_type;

typedef struct child{
	int id,age;
}Child;
typedef struct garden{
	char* name;
	garden_type type;
	Child* children;
	int num_of_children;
}Garden;
typedef struct city{
	Garden* gardens;
	int num_of_gardens;
}City;

void readCity(City*);
void showCityGardens(const City*);
void showSpecificGardenInCity(const City*);
void saveCity(const City*);
void cityAddGarden(City*);
void addChildToSpecificGardenInCity(City*);
void birthdayToChild(City*);
int countChova(const City*);
void ReleaseCity(City*);

void loadGardenFromFile(FILE*,Garden*);
void loadChildFromFile(FILE*,Child*);
void readNameFromFile(FILE*,char*,int);
const char* typeToString(garden_type);
void printGarden(const Garden*);
void printChild(const Child*);
void saveChild(FILE*,const Child*);
void addChild(Garden*);
void addChildToGarden(Child*,Garden*);
Garden* findGarden(const City*,char**,int);
Child* findChild(const Garden*,int);

#endif /* UTILS_H_ */
