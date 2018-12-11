/*
 * child.h
 *
 *  Created on: 11 Dec 2018
 *      Author: aviv
 */

#ifndef CHILD_H_
#define CHILD_H_

#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include "types.h"

void saveChild(FILE*,const Child*);
Child* findChild(const Garden*,int);
void printChild(const Child*);
void loadChildFromFile(FILE*,Child*);
void addChild(Garden*);

#endif /* CHILD_H_ */
