#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void check_env(){
  printf("ENV['COMMAND_MODE'] = %s\n",getenv("COMMAND_MODE"));
}
void run_command(char * command){
  system(command);
}
void realloc_memory(){
  char *ptr1, *ptr2;
  size_t length1, length2;
  length1 = 10;
  length2 = 20;

  ptr1 = (char *)malloc(length1);
  if (ptr1 == NULL){
    printf("Could not allocate memory \n");
    exit(1);
  }
  strcpy(ptr1, "C malloc");
  ptr2 = (char *)realloc(ptr1, length2);
  if (ptr2 == NULL){
    printf("Could not allocate memory \n");
    exit(1);
  }
  strcat(ptr2, " additional text addded\n");
  printf("%s", ptr2);
  free(ptr2);
}
int main(){
  check_env();
  run_command("ls -lA");
  realloc_memory();
  return 0;
}
