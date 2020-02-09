#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXSTRLEN 100 // 100 bytes , 100 Alpha numeric chars

int buildString(char *string){
  char *s;
  int i = sizeof("Hello");
  int stringSize = (strlen(string) + 1 ) * sizeof(char);
  printf("number %d", stringSize);
  s = (char *)malloc(i);

  strncpy(s, "Hello", i);
  printf("s is: %s \n", s);
  // allocate even more memory for the existing string
  // space of the existing string will increase in n bytes.
  realloc(s, stringSize);

  strcat(s, string);
  printf("s is now: %s \n", s);
  free(s);
  return 0;
}
char *allocateMemory(char* string){
  char *s;
  int stringSize;
  // size of string in bytes includes '\0' byte
  stringSize = (strlen(string) + 1 ) * sizeof(char);

  printf("size of word '%s' is %d bytes\n", string, stringSize);

  s = (char*)malloc(stringSize);
  /*
  https://www.tutorialspoint.com/calloc-versus-malloc-in-c
  s = (char*)calloc(stringSize, sizeof(char));
  */

  if (s == NULL){
    printf("malloc failed! \n");
    exit(0);
  }
  strncpy(s, string, stringSize);
  return s;
}

char * string_function(char *astring){
  char *s;
  s = (char *)malloc(MAXSTRLEN); // allocate memory on a heap
  s[0] = 0;
  strcat(s, "Hello ");
  strcat(s, astring);
  strcat(s, "! \n");
  return s;
}

int main(int argc, char **argv){
printf("%s ",string_function("John"));
char * randomString = allocateMemory("character and counts the number of");
printf("%s\n", randomString);
free(randomString);
buildString("John Whill");
  return 0;
}