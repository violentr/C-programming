#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
  char name[30];
  int age;
  bool isVerified;
} user;


user *createUser(char name[], int age, bool isVerified){
  user *newUser = malloc(sizeof(user));
  strcpy(newUser->name, name);
  newUser->age = age;
  newUser->isVerified = isVerified;
  return newUser;
}


int main(){
  user *me = createUser("Mike Beado", 34, true);
  printf("%s is %d years old \n", me->name,  me->age);

  // release used memory
  free(me);
  return 0;
}
