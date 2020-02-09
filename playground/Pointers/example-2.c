#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 4

/* check what type is variable.
#include <stdbool.h>
#define isCompatible(x, type) _Generic(x, type: true, default: false)
double doubleVar;
if (isCompatible(doubleVar, double)) {
  printf("doubleVar is of type double!\n");  // prints
}*/

int data[LENGTH];
char* words[LENGTH];

void printArray(char* data[LENGTH], char type[]){
  void *gp;
  int result = strncmp(type, "str", 3);
  char msg[] = "[E]lement of the array is: ";
  gp = data;
  char * searchResult =  result == 0 ? "Found" : "Not Found";

  printf("[R]esult %s\n", searchResult);
  for(int i=0; i < LENGTH; i++){
    if (result == 0 ){
      printf("%s %s \n", msg, *(char **)gp);
      gp = (char**)gp + 1;
    }else{
      printf("%s %d \n", msg, *(int *)gp);
      gp = (int*)gp + 1;
    }
  }
}


int main(int argc, char **argv){
  void *gp;

  printf("generic pointer example\n");

  // Initialize our string array
  for(int i=0; i < LENGTH; i++){
    data[i] = i;
  }
  for(int i=0; i < LENGTH; i++){
    printf("%d\n", data[i]);
  }

  // Initialize our string array
  words[0] = "zero";
  words[1] = "one";
  words[2] = "two";
  words[3] = "three";

  for (int i=0; i < LENGTH; i++){
    printf("%s\n", words[i]);
  }

  gp = data; //array of int

  printf("\ndata array address is %p\n", gp); //address of the first element in array;
  printf("Item pointed to by gp is %d\n", *(int *)gp);//0 (first element in the array)

  //point to the second element in the array
  gp = (int *)gp + 1;
  printf("Item pointed to by gp is %d\n", *(int *)gp);
  //* means dereferene (print the value of that address) //1 (second element in the array)
  // printArray(gp, "");

  gp = words; //array of strings
  printf("\nwords array address is %p \n",gp);
  printf("words array address is %s \n", *(char **)gp);
  gp = (char**)gp + 1;
  printf("words array address is %s \n", *(char **)gp);


  // Refactor the way how to loop with the help of pointers
  // printArray(gp, "str");
  return 0;
}

