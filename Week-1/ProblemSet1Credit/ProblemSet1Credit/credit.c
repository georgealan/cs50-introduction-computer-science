#include <stdio.h>
#include <cs50.h>

int main(void)
{
  string name = get_string("What is your name? ");
  printf("Welcome %s\n", name);
}