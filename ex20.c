#include "dbg.h"
#include <stdlib.h>
#include <stdio.h>


void test_debug()
{
  debug("I have brown hair");
  debug("I am %d years old", 25);
}

void test_log_err()
{
  log_err("shit's broke");
  log_err("ther are %d problems in %s", 0, "space");
}

void test_log_warn()
{
  log_warn("you can safely ignore this");
  log_warn("maybe consider having a look at: %s", "/etc/passwd");
}

void test_log_info()
{
  log_info("this is something");
  log_info("it happened %f times today", 1.3f);
}

int test_check(char *file_name)
{
  FILE *input = NULL;
  char *block = NULL;

  block = malloc(100);
  check_mem(block);

  input = fopen(file_name, "r");
  check(input, "failed to open %s", file_name);

  free(block);
  fclose(input);
  return 0;

error:
  if(block) free(block);
  if(input) fclose(input);
  return -1;
}

int test_sentinel(int code)
{
  char *temp = malloc(100);
  check_mem(temp);

  switch(code) {
    case 1:
      log_info("it worked");
      break;
    default:
      sentinel("I shouldn't run");
  }

  free(temp);
  return 0;

error:
  if(temp) free(temp);
  return -1;
}

int test_check_mem()
{
  char *test = NULL;
  check_mem(test);

  free(test);
  return 1;

error:
  return -1;
}

int test_check_debug()
{
  int i = 0;
  check_debug(i != 0, "oops, i was 0");

  return 0;

error:
  return -1;
}

int main(int argc, char *argv[])
{
  check(argc == 2, "Need an argument");

  test_debug();
  test_log_err();
  test_log_warn();
  test_log_info();

  check(test_check("ex20.c") == 0, "failed with ex20.c");
  check(test_check(argv[1]) == -1, "failed with argv");
  check(test_sentinel(1) == 0, "test_sentinel failed");
  check(test_sentinel(100) == -1, "test_sentinel failed");
  check(test_check_mem() == -1, "test_check_mem failed");
  check(test_check_debug() == -1, "test_check_debug failed");

  return 0;

error:
  return 1;
}


