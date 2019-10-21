//Isiah Slater
//This program acts as a database to academic information for a University
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LINE 51
#define MAX_CLASSES 64
#define MAX_USER_INPUT_SIZE 7

//struct definitions
#define MAX_DEPARTMENT_LENGTH 8
#define MAX_COURSE_NUMBER_LENGTH 8
#define MAX_COURSE_LOCATION_LENGTH 32

typedef struct class_info
{
  char department [MAX_DEPARTMENT_LENGTH];
  char number [MAX_COURSE_NUMBER_LENGTH];
  char location [MAX_COURSE_LOCATION_LENGTH];
}class_info_t;


//FILE open_file attempts to open a user-specified file
//char *argv[] the file prompted in the shell
//returns: the file that is opened_
FILE *open_file(char *argv[]);


int main(int argc, char *argv[])
{
  
  //read file into an input
  FILE *f = open_file(argv);

  //file_op begins
  char lines[MAX_LINE];
  
  //sort into an array of structs
  fgets(lines, MAX_LINE, f);
  //char *line_info = (char *) malloc((strlen(lines) + 1) * sizeof(char)); //what?
  char delim[2] = ":";
  char *token = strtok(lines, delim);
  int department_count = atoi(token); //how many structs to generate into an array
  // printf("%d\n", department_count);

  //dynamically create array for classes
  class_info_t *class_array[MAX_CLASSES];
  int i;
  //TODO proper memory allocation
  //read line with fgets
  //tokenize line
  //malloc memory for a class_info_t struct variable
  //assign said variable to class_array part
  class_info_t *temp = (class_info_t *) malloc(department_count * sizeof(class_info_t));
  //file_op read_file function
  for(i = 0; i < department_count && (fgets(lines, MAX_LINE, f)) != NULL; i++)
    {
      
       if((token = strtok(lines, delim)) != NULL)
	{
	  strcpy((temp + i)->department, token);
	  if((token = strtok(NULL, delim)) != NULL)
	    {
	      strcpy((temp + i)->number, token);
	      if((token = strtok(NULL, delim)) != NULL)
		{
		  strcpy((temp + i)->location, token);
		}
	    }
	}
       class_array[i] = (temp + i);
    }

  //prompt user in loop
  int done = 0;
  while(!done)
    {
      printf("input option: ");
      char option[MAX_USER_INPUT_SIZE];
      fgets(option, MAX_USER_INPUT_SIZE, stdin);
      option[strcspn(option, "\n")] = '\0';

      //option 1: list
      if(strcmp( option, "list") == 0)
	{
	  for(i = 0; i < department_count; i++)
	    {
	      printf("%d: %s %s - %s\n", i + 1, class_array[i]->department, class_array[i]->number, class_array[i]->location);
	    }
	}

      //option 2: add
      

      //option 3: remove

      
      //option 4: exit
      if(strcmp(option, "exit") == 0)
	{
	  done = 1;
	}
      
  
    }
  free(temp);
}




FILE *open_file(char *argv[])
{
  char *filename = argv[1];
  FILE *f;
  if((f = fopen(filename, "r")) == NULL)
    {
      printf("Failed to open %s.\n", filename);
      exit(-1);
    }
  return f;
}
