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

#define GARDEN_NAME_MAX_INPUT 32

#define LOOP_FOR_RESULT 1
#define DONT_LOOP_FOR_RESULT 0

void loadGardenFromFile(FILE*,Garden*);
void printGarden(const Garden*);
Garden* findGarden(const City*,char**,int);
void ReleaseGarden(Garden*);
void saveGarden(FILE*,const Garden*);

#endif /* GARDEN_H_ */
