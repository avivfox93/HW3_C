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
	ReleaseCity(city);
	FILE* file = fopen(FILENAME,"r");
	if(file == NULL)return;
	fscanf(file,"%d\n",&(city->num_of_gardens));
	city->gardens = (Garden*)malloc(city->num_of_gardens * sizeof(Garden));
	for(i = 0 ; i < city->num_of_gardens ; i++)
		loadGardenFromFile(file, (city->gardens + i));
	fclose(file);
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

void showSpecificGardenInCity(const City* city)
{
	Garden* garden = findGarden(city,NULL,0);
	if(garden != NULL)
		printGarden(garden);
}

void saveCity(const City* city)
{
	int i;
	Garden* garden = city->gardens;
	FILE* file = fopen(FILENAME,"w");
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
	if(garden == NULL)return;
	for(i = 0 ; i < city->num_of_gardens ; i++,garden++)
	{
		free(garden->children);
		free(garden->name);
	}

	free(city->gardens);
}

int readNameFromFile(FILE* file, char** name)
{
	int i,count;
	char ch;
	count = 0;
	do
	{
		ch = fgetc(file);
		count++;
	}while(isalpha(ch));
	*name = (char*)malloc(count*sizeof(char));
	fseek(file,-count,SEEK_CUR);
	for(i = 0 ; i < count ; i++)
		*(*name + i) = fgetc(file);
	*(*name + count - 1) = 0;
	return count;
}
