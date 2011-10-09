#include <stdio.h>

int main(int argc, char *argv[])
{
  int distance = 100;
  float power = 2.345f;
  double super_power = 56789.4532;
  char initial = 'M';
  char first_name[] = "Samuel";
  char last_name[] = "Breed";

  printf("wuuut %d\n", distance);
  printf("you have %f power\n", power);
  printf("wut super power %f\n", super_power);
  printf("initial %c\n", initial);
  printf("first name %s\n", first_name);
  printf("last name %s\n", last_name);
  printf("full name %s %c %s\n",
      first_name, initial, last_name);

  return 0;
}
