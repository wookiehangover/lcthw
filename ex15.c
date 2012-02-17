#include <stdio.h>

int main(int argc, char *argv[])
{
  // create 2 arrays we care about
  int ages[] = {23, 43, 12, 89, 2};
  char *names[] = {
    "Alan", "Frank",
    "Mary", "John", "Lisa"
  };

  // safely get the size of the ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // first way using indexing
  for(i=0; i < count; i++) {
    printf("%s has %d years alive. \n",
        names[i], ages[i]);
  }

  printf("---\n");

  // setup the pointers to the start of the arrays
  int *cur_age = ages;
  char **cur_name = names;

  // second way using pointers
  for(i=0; i < count; i++) {
    printf("%s is %d years old.\n",
        *(cur_name+i), *(cur_age+i));
  }

  printf("---\n");

  // third way, pointers are just arrays
  for(i=0; i < count; i++) {
    printf("%s is %d years old again.\n",
        cur_name[i], cur_age[i]);
  }

  printf("---\n");

  // fourth way with pointers in a stupid complex way
  for(cur_name = names, cur_age = ages;
      (cur_age - ages) < count;
      cur_name++, cur_age++)
  {
    printf("%s lived %d years for far.\n",
        *cur_name, *cur_age);
  }

  printf("---\n");

  for(i=0; i < count; i++) {
    printf("name: %p age: %p.\n",
        &cur_name[i], &cur_age[i]);
  }

  return 0;
}

