#include <stdio.h>
#include <string.h>
#include <stdlib.h>
void printFactorial(int num){
  int place = num;
  int result = 1;

  while(place != 0){
    result = result * place;
    place = place -1;
  }
  printf("The factorial of number %d is %d\n", num, result);
}

/* Extract everything a part from the search string*/
char *not_substr(char buff[], char *search_string){

 int buff_size = (int)strlen(buff);
 int length = (int)strlen(search_string);
 char * result = (char *)malloc(sizeof(char)*length);
 int DEBUG = 0;

 int step = length + 1;
 int index;
 for(int i = step; i < buff_size;  i++) {
  index = i - step;
  result[index] = buff[i];
  if (DEBUG){
    printf("Result[%d]=%c\n", i, buff[i]);
  }
 }
 return result;
}

