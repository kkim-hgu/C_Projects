//Isiah Slater
//This program removes a struct with the specified string value
#include "file_operations.h"
#include<stdio.h>
#include<stdlib.h>
#include<String.h>

void remove(FILE *f, char *class_array[], int *department_count)
{
  printf("String to be removed: ");
  //get string from user, store in
  char input[MAX_DEPARTMENT_LENGTH];
  fgets(input, MAX_DEPARTMENT_LENGTH,f);
  int i = 0;
  while(i < *department_count && strcmp(input, (class_array + i)->department
}
