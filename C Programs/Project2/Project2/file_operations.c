//Contains functions that nandle reading the contents of the file intot hte array, and writes the array back to the file
#include"file_operations.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void read_file(char *argv[], class_info_t *class_array[], char *class_count)
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
  char array_size[MAX_CLASSES];
  strcpy(array_size, strtok(lines, delim));
  
  //get info on array size for class_array
  int i;
  for(i = 0; i < MAX_CLASSES; i++)
    {
      *(class_count + i) = array_size[i];
    }
  int department_count = atoi(class_count);

  //read the file data into class_array
  char *token = NULL;
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
  //close reading file
  fclose(f);
}

void save_file(char *argv[], char *class_count, class_info_t *class_array[])
{
  //open file to write
  char *filename = argv[1];
  FILE *f = fopen(filename, "w");
  int department_count = atoi(class_count);
  int i;
  fputs(class_count, f);
  fputs("\n", f);
  //insert data into file
  for(i = 0; i < department_count; i++)
    {
      fputs(class_array[i]->department, f);
      fputs(":", f);
      fputs(class_array [i]->number, f);
      fputs(":", f);
      fputs(class_array[i]->location, f);
      free(class_array[i]); //free data after being inserted
    }
}
