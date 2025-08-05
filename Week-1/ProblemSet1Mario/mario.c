#include <stdio.h>
#include "cs50.h"

void printLine(int numberOfLines);
void printBlocks(int line, int numberOfLines);

int actualLine = 0;
char block = '#';
char space = ' ';

int main(void)
{
  int height;

  do
  {
    height = get_int("Height: ");
  } while (height < 1 || height > 8);

  printLine(height);
}

void printLine(int numberOfLines)
{
  do
  {
    actualLine++;
    printBlocks(actualLine, numberOfLines);

  } while (actualLine < numberOfLines);
}

void printBlocks(int line, int numberOfLines)
{
  int capacity = (numberOfLines * 2) + 3;
  char arr[capacity];
  int whiteSpaces = numberOfLines - line - 1;

  for (int i = 0; i < capacity - 1; i++)
  {
    if (i <= whiteSpaces)
    {
      arr[i] = space;
      continue;
    }
    if (i == numberOfLines || i == numberOfLines + 1)
    {
      arr[i] = space;
      continue;
    }
    if (i < (capacity - 2) - whiteSpaces)
    {
      arr[i] = block;
      continue;
    }

  }

  arr[capacity - 1] = '\0';

  printf("%s\n", arr);
}
