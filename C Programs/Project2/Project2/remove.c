//Isiah Slater
//This program removes a struct with the specified string value
#include "file_operations.h"
#include "remove.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void remove_class(int *department_count, class_info_t *class_array[], char *class_count)
{
  printf("Enter a word: ");
  getchar();
  char token[MAX_LINE];
  fgets(token, MAX_LINE, stdin);
  token[strcspn(token, "\n")] = '\0';

  int i;
  int done = FALSE;
  for( i = 0; i < *department_count && !done; i++)
    {
      if(strstr(class_array[i]->department, token) || strstr(class_array[i]->number, token))
	{
	  //printf("%d", i);
	  done = TRUE;
	  int t;
	  class_info_t *temp;
	  for(t = i; t < *department_count - 1; t++)
	    {	   
		  temp = class_array[t];
		  class_array[t] = class_array[t + 1];
		  class_array[t + 1] = temp;
	    }
	  class_array[*department_count - 1] = NULL;
	  free(class_array[*department_count - 1]);
	  *department_count -= 1;
	  sprintf(class_count, "%d", *department_count);
	}
    }
}
