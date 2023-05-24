#include <stdio.h>
#include <stdlib.h>

typedef struct
{
  char name[30];
  char email[100];
  int age;
} Person;

typedef struct a
{
  Person User;
  struct a *Next;
} No;

No *createUser(No *User, Person Allum);
Person form();

int main(int argc, char const *argv[])
{
  No *User = NULL;

  createUser(User, form());

  return 0;
}

Person form()
{
  Person User;

  printf("User Name: ");
  scanf(" %s", User.name);
  printf("User Email: ");
  scanf(" %s", User.email);
  printf("User age: ");
  scanf(" %s", User.age);

  return User;
}

No *createUser(No *User, Person Allum)
{
  No *NewUser;
  NewUser = malloc(sizeof(No));

  if (NewUser)
  {
    NewUser->User = Allum;
    NewUser->Next = User->Next;
  }
  else
  {
    printf("Error to alocate memory\n");
  }
}