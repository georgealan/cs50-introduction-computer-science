#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "cs50.h"

int main(void) 
{
  string word = get_string("Write a word: ");
  string result = "Yes";
  int stringLenght = strlen(word);

  for (int i = 0; i < stringLenght; i++)
  {
    if (toupper(word[i]) > toupper(word[i + 1]) && toupper(word[i + 1]) != 0)
    {
      result = "No";
    }
  }

  printf("%s\n", result);
}

/*
Alphabetical Exercise
Check if a lowercase string's characters are on alphabetical order. If yes, print "Yes".
If not print "No".

asciichart.com
*/