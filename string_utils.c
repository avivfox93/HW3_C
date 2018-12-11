/*
 * string_utils.c
 *
 *  Created on: 11 Dec 2018
 *      Author: aviv
 */

#include "string_utils.h"

int get_name_from_file(FILE* file, char** name)
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

