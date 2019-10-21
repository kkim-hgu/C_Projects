//Isiah Slater
//This program stores data of a Univeristy's classes

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"file_operations.h"
#include"add.h"
#include "remove.h"

int main(int argc, char *argv[])
{
  //gather filename from user with argv
  class_info_t *class_array[MAX_CLASSES];
  char class_count[MAX_CLASSES];
  read_file(argv, class_array, class_count);
  int department_count = atoi(class_count);
  int done = 0;
  int i;
  //prompt user
  while(!done)
    {
      printf("input option: ");
      char option[MAX_USER_INPUT_SIZE];
      fgets(option, MAX_USER_INPUT_SIZE, stdin);
      option[strcspn(option, "\n")] = '\0';

      //option 1: list
      if(strcmp(option, "list") == 0)
	{
	  for(i = 0; i < department_count; i++)
	    {
	      printf("%d: %s %s - %s\n", i + 1, class_array[i]->department, class_array[i]->number, class_array[i]->location);
	    }
	}

      //option 2: add
      if(strcmp(option, "add") == 0)
	{
	  add(&department_count, class_array, class_count);
	}
      //option 3: remove
      if(strcmp(option, "remove") == 0)
	{
	  remove_class(&department_count, class_array, class_count);
	}
      
      //option 4: exit
      if(strcmp(option, "exit") == 0)
	{
	  done = 1;
	  save_file(argv, class_count, class_array);
	}
    }
}
