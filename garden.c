/*
 * garden_utils.c
 *
 *  Created on: 11 Dec 2018
 *      Author: aviv
 */

#include "garden.h"

void loadGardenFromFile(FILE* file, Garden* garden)
{
	int i;
	readNameFromFile(file,&(garden->name));
	fscanf(file,"%d %d\n",(int*)&(garden->type),&(garden->num_of_children));
	garden->children = (Child*)malloc(sizeof(Child)*garden->num_of_children);
	for(i = 0 ; i < garden->num_of_children ; i++)
		loadChildFromFile(file,(garden->children + i));
}

void printGarden(const Garden* garden)
{
	int i;
	printf("Name: %-11s Type: %-15s %d Children:\n",
			garden->name,typeToString(garden->type),garden->num_of_children);
	Child* child = garden->children;
	for(i = 0 ; i < garden->num_of_children ; i++,child++)
		printChild(child);
}

Garden* findGarden(const City* city, char** name, int loop)
{
	int i,exist;
	Garden* garden;
	char in[GARDEN_NAME_LENGTH] = {0};
	do{
		printf("\nGive me the Kindergarten Name:\n");
		scanf("%s",in);
		if(name != NULL)
		{
			*name = malloc(strlen(in)*sizeof(char));
			strcpy(*name,in);
		}
		garden = city->gardens;
		if(garden == NULL) return NULL;
		for(i = 0; i < city->num_of_gardens ; i++, garden++)
			if(!strcmp(in,garden->name))
				return garden;
		printf("\nNo such Kindergarten");
	}while(loop);
	return NULL;
}

void saveGarden(FILE* file,const Garden* garden)
{
	int i;
	Child* child = garden->children;
	fprintf(file,"%-11s %d %d\n",garden->name,garden->type,garden->num_of_children);
	for(i = 0 ; i < garden->num_of_children ; i++,child++)
		saveChild(file,child);
}
