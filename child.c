/*
 * child.c
 *
 *  Created on: 11 Dec 2018
 *      Author: aviv
 */

#include "child.h"

void saveChild(FILE* file ,const Child* child)
{
	fprintf(file,"%d %d\n",child->id,child->age);
}

Child* findChild(const Garden* garden, int loop)
{
	int i,id;
	Child* child = garden->children;
	if(garden == NULL || child == NULL) return NULL;
	do{
		printf("\nEnter Child ID:\n");
		scanf("%d",&id);
		for(i = 0; i < garden->num_of_children ; i++,child++)
		{
			if(child->id == id)
			{
				return child;
			}
		}
		printf("No Such Child");
	}while(loop == LOOP_FOR_RESULT);
	return NULL;
}

void printChild(const Child* child)
{
	printf("ID:%-6d Age:%d\n",child->id,child->age);
}

void loadChildFromFile(FILE* file, Child* child)
{
	fscanf(file,"%d %d\n",&(child->id),&(child->age));
}

void addChild(Garden* garden)
{
	int i,id,age,exist;
	Child* child;
	if(garden->children != NULL)
		garden->children = realloc(garden->children,(garden->num_of_children+1)*sizeof(Child));
	else
		garden->children = malloc(garden->num_of_children*sizeof(Child));
	child = garden->children + garden->num_of_children;
	do{
		printf("\nID No.:\n");
		scanf("%d",&id);
		for(i = 0, exist = 0 ; i < garden->num_of_children ; i++)
			if((garden->children + i)->id == id)
			{
				exist = 1;
				break;
			}
		if(exist)
			printf("\nThis child is in the Kindergarten\n");
	}while(exist);
	garden->num_of_children++;
	printf("\nAge:\n");
	scanf("%d",&age);
	child->age = age;
	child->id = id;
}
