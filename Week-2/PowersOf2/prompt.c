#include <stdio.h>
#include "cs50.h"

int main(void)
{
  int n;

  do
  {
    n = get_int("Write the size of the array you want: ");
  } while (n < 1);

  int array[n];
  int number = 1;

  // Fill the array
  for (int i = 0; i < n; i++)
  {
    array[i] = number;
    number *= 2;
  }
  
  // Print the array
  for (int i = 0; i < n; i++)
  {
    printf("%d\n", array[i]);
  }
}

/*
Exercise Powers of 2
Create a program that prompts the user for a size, n.
Dynamically create an array of that size, where each element is 2 times the previous one.
Start the array at 1.
Print the array, integer by integer.
*/