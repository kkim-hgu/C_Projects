//this program contains the instructions for adding a new class to the array of classes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "file_operations.h"
#include "add.h"

void add(int *department_count, class_info_t *class_array[], char *class_count)
{
  //increase occupied array size
  (*department_count)++;
  sprintf(class_count, "%d", *department_count);
  //read each piece of user input
  //place it in respective location at the end of array
  printf("Enter department: ");
  char token[MAX_LINE];
  fgets(token, MAX_LINE, stdin);
  token[strcspn(token, "\n")] = '\0';
  //dynamically allocate struct pointer and assign values
  class_array[*department_count - 1] = (class_info_t *) malloc(sizeof(class_info_t));
  strcpy(class_array[*department_count - 1]->department, token);
  
  printf("Enter class number: ");
  fgets(token, MAX_LINE, stdin);
  token[strcspn(token, "\n")] = '\0';
  strcpy(class_array[*department_count - 1]->number, token);
  
  printf("Enter location: ");
  fgets(token, MAX_LINE, stdin);
  strcpy(class_array[*department_count - 1]->location, token);
}
