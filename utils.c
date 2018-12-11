/*
 * utils.c
 *
 *  Created on: 10 Dec 2018
 *      Author: aviv
 */

#include "utils.h"

void readCity(City* city)
{
	int i;
	FILE* file = fopen(FILENAME,"r");
	fscanf(file,"%d\n",&(city->num_of_gardens));
	city->gardens = (Garden*)malloc(city->num_of_gardens * sizeof(Garden));
	for(i = 0 ; i < city->num_of_gardens ; i++)
		loadGardenFromFile(file, (city->gardens + i));
	fclose(file);
}

void readNameFromFile(FILE* file, char* name, int max_size)
{
	int i;
	char read;
	for(i = 0 ; i < GARDEN_NAME_LENGTH ; i++,name++)
	{
		read = fgetc(file);
		*name = read;
		if(read == ' ' || read == '\n' || read == 0)
		{
			*name = 0;
			return;
		}
	}
}

void loadGardenFromFile(FILE* file, Garden* garden)
{
	int i;
	garden->name = (char*)malloc(sizeof(char) * GARDEN_NAME_LENGTH);
	readNameFromFile(file, garden->name, GARDEN_NAME_LENGTH);
	fscanf(file,"%d %d",(int*)&(garden->type),&(garden->num_of_children));
	garden->children = (Child*)malloc(sizeof(Child)*garden->num_of_children);
	for(i = 0 ; i < garden->num_of_children ; i++)
		loadChildFromFile(file,(garden->children + i));
}

void loadChildFromFile(FILE* file, Child* child)
{
	char ch;
	fscanf(file,"%d %d",&(child->id),&(child->age));
	for(ch = fgetc(file) ; ch != '\n' && ch != 0 ; ch = fgetc(file));
}

const char* typeToString(garden_type type)
{
	switch(type)
	{
	case CHOVA:
		return "Chova";
	case TROM_CHOVA:
		return "Trom Chova";
	case TROM_TROM_CHOVA:
		return "Trom Trom Chova";
	default:
		return "Gan";
	}
}

void showCityGardens(const City* city)
{
	int i,j;
	Garden* garden = city->gardens;
	if(garden == NULL) return;
	for(i = 0 ; i < city->num_of_gardens ; i++,garden++)
	{
		printf("\nKindergarden %d:\n",i+1);
		printGarden(garden);
	}
}

void printGarden(const Garden* garden)
{
	int i;
	printf("Name: %-11s Type: %-11s %d Children:\n",
			garden->name,typeToString(garden->type),garden->num_of_children);
	Child* child = garden->children;
	for(i = 0 ; i < garden->num_of_children ; i++,child++)
		printChild(child);
}

void printChild(const Child* child)
{
	printf("ID: %d Age: %d\n",child->id,child->age);
}

Garden* findGarden(const City* city, char** name, int loop)
{
	int i,exist;
	Garden* garden;
	char* in = malloc(GARDEN_NAME_LENGTH*sizeof(char));
	if(name != NULL)
		*name = in;
	do{
		printf("\nGive me the Kindergarten Name:\n");
		scanf("%s",in);
		garden = city->gardens;
		if(garden == NULL) return NULL;
		for(i = 0; i < city->num_of_gardens ; i++, garden++)
		{
			if(!strcmp(in,garden->name))
			{
				return garden;
			}
		}
		printf("\nNo such Kindergarten");
	}while(loop);
	return NULL;
}

Child* findChild(const Garden* garden, int loop)
{
	int i,exist,id;
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
	}while(loop);
	return NULL;
}

void showSpecificGardenInCity(const City* city)
{
	Garden* garden = findGarden(city,NULL,0);
	if(garden != NULL)
		printGarden(garden);
}

void saveGarden(FILE* file,const Garden* garden)
{
	int i;
	Child* child = garden->children;
	fprintf(file,"%-11s %d %d\n",garden->name,garden->type,garden->num_of_children);
	for(i = 0 ; i < garden->num_of_children ; i++,child++)
		saveChild(file,child);
}

void saveChild(FILE* file ,const Child* child)
{
	fprintf(file,"%d %d\n",child->id,child->age);
}

void saveCity(const City* city)
{
	int i;
	Garden* garden = city->gardens;
	FILE* file = fopen(FILENAME,"a");
	fprintf(file,"%d\n",city->num_of_gardens);
	for(i = 0 ; i < city->num_of_gardens ; i++,garden++)
		saveGarden(file,garden);
	fclose(file);
}

void cityAddGarden(City* city)
{
	int i,num_child;
	if(city == NULL)return;
	Garden* gardens;
	char* name;
	garden_type type;
	do{
		gardens = findGarden(city,&name,0);
		if(gardens != NULL)
			printf("\nThis Kindergarten already in list\n");
	}while(gardens != NULL);
	city->gardens = realloc(city->gardens,(city->num_of_gardens + 1)*sizeof(Garden));
	if(city->gardens == NULL)return;
	gardens = city->gardens + city->num_of_gardens;
	city->num_of_gardens++;
	gardens->name = name;
	printf("\nGarden Type:\nEnter %d for Chova\nEnter %d for Trom Chova\nEnter %d for Trom Trom Chova\n",
			CHOVA,TROM_CHOVA,TROM_TROM_CHOVA);
	scanf("%d",(int*)&(gardens->type));
	printf("\nChildren count:\n");
	scanf("%d",&num_child);
	for(i = 0 ; i < num_child ; i++)
		addChild(gardens);
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

void addChildToSpecificGardenInCity(City* city)
{
	char* name;
	Garden* garden = findGarden(city,&name,0);
	if(garden == NULL)return;
	addChild(garden);
}

void birthdayToChild(City* city)
{
	Child* child;
	Garden* garden;
	garden = findGarden(city,NULL,0);
	if(garden == NULL)return;
	child = findChild(garden,0);
	if(child == NULL)return;
	child->age++;
}

int countChova(const City* city)
{
	int i,count;
	Garden* garden = city->gardens;
	for(i = 0, count = 0 ; i < city->num_of_gardens ; i++,garden++)
		if(garden->type == CHOVA)
			count += garden->num_of_children;
	return count;
}

void ReleaseCity(City* city)
{
	int i,j;
	Garden* garden = city->gardens;
	Child* child;
	for(i = 0 ; i < city->num_of_gardens ; i++,garden++)
	{
		free(garden->children);
		free(garden->name);
	}

	free(city->gardens);
}
