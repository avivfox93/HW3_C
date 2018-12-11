/*
 * types.h
 *
 *  Created on: 11 Dec 2018
 *      Author: aviv
 */

#ifndef TYPES_H_
#define TYPES_H_

typedef struct child{
	int id,age;
}Child;

typedef enum gartype{
	CHOVA,
	TROM_CHOVA,
	TROM_TROM_CHOVA
}garden_type;

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

#endif /* TYPES_H_ */
