//Contains functions that nandle reading the contents of the file intot hte array, and writes the array back to the file
#include"file_operations.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *read_file(char *argv[], class_info_t *class_array[])
{
  //open file
  FILE *f = NULL;
  char *filename = argv[1];
  if((f = fopen(filename, "r")) == NULL)
    {
      printf("Failed to open %s.\n", filename);
      exit(-1);
    }

  //read file
  char delim[2] = ":";
  char lines[MAX_LINE];
  fgets(lines, MAX_LINE, f);
  char *token = strtok(lines, delim);
  char *class_count = token;
  int department_count = atoi(token);
  
  int i;
  for(i = 0; i < department_count && (fgets(lines, MAX_LINE, f)) != NULL; i++)
    {
      class_array[i] = (class_info_t *) malloc(sizeof(class_info_t));
      if((token = strtok(lines, delim)) != NULL)
	{
	  strcpy((class_array[i])->department, token);
	  if((token = strtok(NULL, delim)) != NULL)
	    {
	      strcpy((class_array[i])->number, token);
	      if((token = strtok(NULL, delim)) != NULL)
		{
		  strcpy((class_array[i])->location, token);
		}
	    }
	}
    }
  fclose(f);
  return class_count;
}

void save_file(char *argv[], char * class_count, class_info_t *class_array[])
{
  char *filename = argv[1];
  FILE *f = fopen(filename, "w");
  int department_count = atoi(class_count);
  int i;
  //char *class_count = itoa(department_count,str , 10);
  for(i = 0; i < department_count; i++)
    {
      //TODO fix into string first argument 
      fputs(class_count, f);
      fputs(class_array[i]->department, f);
      fputs(":", f);
      fputs(class_array [i]->number, f);
      fputs(":", f);
      fputs(class_array[i]->location, f);
      fputs("\n", f);
      free(class_array[i]);
    }
}
