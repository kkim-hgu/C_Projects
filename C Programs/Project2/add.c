//this program contains the instructions for adding a new class to the array of classes
#include "file_operations.h"

void add(int *department_count, class_info_t class_array[])
{
  (*department_count)++;
  char *token;
  class_info_t temp;
  //read each piece of user input
  //place it in respective location at the end of array
  printf("Enter department: ");
  fgets(token, MAX_LINE, f);
  class_array[department_count - 1] = (class_info_t *) malloc(sizeof(class_info_t));
  class_array[department_count - 1]->department = token;
  printf("Enter class number: ");
  
  printf("Enter location: ");
}
