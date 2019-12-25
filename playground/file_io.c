/* preprocessor directives*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/* */
//
// my custom header
#include "myheader.h"

// create constant
#define TEST_VAR 10

struct Person
{
  int age;
  char name[10];
  char surname[10];
};
char string[]="AAAAAAAAAAAAAA";
int size = sizeof(string)/sizeof(char);

void pointerFunction(){
  char * name = "Test";
  char *ptr = name;
  int size = strlen(ptr);

  printf("count %d\n", size);
  for( int i =0; i < size ; i++){
    printf("print pointer %c\n", ptr[i]);
  }
}
void usingMacros(){
  printf("this is %s\n", __FILE__);
  printf("today is %s\n", __DATE__);
}

void reallocMemory(){
  char * newchar;
  char buffer[50];
  // allocate memory for the variable
  newchar = malloc(30*sizeof(char));

  // copy string
  strcpy(newchar, "initial text made before allocating memory\n");

  // add even more memory for the variable
  newchar = realloc(newchar , *buffer);

  // concatenate string
  strcat(newchar," additional content added\n");
  printf("%s", newchar);
  printf("length of newchar %d", (int)strlen(newchar));
  free(newchar);
}

void writeFile(){
  // create new file object
  FILE * newfile;
  char filename[]="newfile.txt";
  newfile = fopen(filename, "w+");

  fprintf(newfile, "This is a test string read from %s file \n", filename);
  fclose(newfile);
}

void readFile(){
  // create new file object
  char ch;
  FILE * newfile;
  newfile = fopen("newfile.txt", "r");


  /* This will read data until 1st space met
  char file_data[200];
  fscanf(newfile, "%s", file_data);
  printf("%s\n", file_data);
  */

  /* This will read full file
  char file_data[200];
  fgets(file_data, 200, newfile);
  printf("%s\n", file_data);
  */

  /* This will read full file character by character */
  ch = fgetc(newfile);
  while(ch != EOF){
    printf("%c", ch);
    ch = fgetc(newfile);
  }
  fclose(newfile);
}

void compareString(){
  int var = !strcmp("+", "+");
  printf("variable %d\n" , var);

  if (var){
   printf("yes it is equal\n");
  }
}

int main(){
  pointerFunction();

  //reallocMemory();

  writeFile();

  readFile();

  printFactorial(TEST_VAR);

  char * command = "cd Downloads";
  char * search = "cd";
  char * dirname = not_substr(command, search);
  printf("[+] result: %s\n", dirname);

  // variable size is global
  printf("string is %d chr long\n", size);

  for (int i = 0; i < size; i++){
    if (string[i] != '\0'){
      printf("Chr %c \n", string[i]);
    }
  }

  struct Person me;
  strcpy(me.name, "Mike");
  strcpy(me.surname, "Boadem");
  me.age = 34;
  printf("my name : %s \nmy surname: %s \nmy age: %d \n", me.name, me.surname, me.age);

  compareString();
  usingMacros();
}
