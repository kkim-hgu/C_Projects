#define MAX_DEPARTMENT_LENGTH 8
#define MAX_COURSE_NUMBER_LENGTH 8
#define MAX_COURSE_LOCATION_LENGTH 32

#define MAX_LINE 51
#define MAX_CLASSES 64
#define MAX_USER_INPUT_SIZE 7

typedef struct class_info
{
  char department [MAX_DEPARTMENT_LENGTH];
  char number [MAX_COURSE_NUMBER_LENGTH];
  char location [MAX_COURSE_LOCATION_LENGTH];
}class_info_t;

//char *read_file attempts to open a user-specified file and read its contents
//char *argv[] the file prompted in the shell
//returns: the file that is opened_
char *read_file(char *argv[], class_info_t *class_array[]);

//void save_file saves the current array state back into the text file
//char *argv[] the name of the file
//char *class_count the number of array items present
//class_info_t *class_array[] the array being written to the file
void save_file(char *argv[], char * class_count, class_info_t *class_array[]);


