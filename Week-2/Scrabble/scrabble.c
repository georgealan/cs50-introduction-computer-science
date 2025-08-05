#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "cs50.h"

// Points assigned to each letter of the alphabet
int POINTS[] = { 1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10 };
char LETTERS[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

int compute_score(string word);

int main(void)
{
  // Get input words from both players
  string word1 = get_string("Player 1: ");
  string word2 = get_string("Player 2: ");

  // Score both words
  int score1 = compute_score(word1);
  int score2 = compute_score(word2);

  // TODO: Print the winner
  if (score1 == score2)
  {
    printf("Tie!\n");
  }
  else if (score1 > score2)
  {
    printf("Player 1 wins!\n");
  }
  else
  {
    printf("Player 2 wins!\n");
  }
}

int compute_score(string word)
{
  int wordLenght = strlen(word);
  int result = 0;

  for (int i = 0; i < wordLenght; i++)
  {
    for (int j = 0; j < 26; j++)
    {
      if (toupper(word[i]) == LETTERS[j])
      {
        result += POINTS[j];
        continue;
      }
    }
  }

  return result;
}
