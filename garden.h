/*
 * garden.h
 *
 *  Created on: 11 Dec 2018
 *      Author: aviv
 */

#ifndef GARDEN_H_
#define GARDEN_H_

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "types.h"

#define GARDEN_NAME_LENGTH 32

void loadGardenFromFile(FILE*,Garden*);
void printGarden(const Garden*);
Garden* findGarden(const City*,char**,int);
void saveGarden(FILE*,const Garden*);

#endif /* GARDEN_H_ */
