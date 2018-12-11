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
#include "utils.h"
#include "types.h"
#include "child.h"
#include "garden.h"

#define FILENAME "DataFile.txt"
#define GARDEN_NAME_LENGTH 32

void readCity(City*);
void showCityGardens(const City*);
void showSpecificGardenInCity(const City*);
void saveCity(const City*);
void cityAddGarden(City*);
void addChildToSpecificGardenInCity(City*);
void birthdayToChild(City*);
int countChova(const City*);
void ReleaseCity(City*);

int readNameFromFile(FILE*,char**);
const char* typeToString(garden_type);

#endif /* UTILS_H_ */
