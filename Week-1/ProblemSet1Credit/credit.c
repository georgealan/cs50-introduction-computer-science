#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "cs50.h"

int main()
{
  long creditCardNumber = get_long("Number: ");
  long number = creditCardNumber;
  int quotient = 0;
  int i = 0;
  char str[50];
  bool firstDigitIsValid = false;
  int sumFromTheEnd = 0;
  int sumFromBegin = 0;
  int resultSum = 0;
  int multiply = 1;
  string cardName = "";

  sprintf(str, "%ld", creditCardNumber); // Convert number to string
  int cardNumberLenght = strlen(str); // Get string lenght

  // First validation to verify if number lenght is correct with standard
  if (cardNumberLenght < 13 || cardNumberLenght > 16)
  {
    printf("INVALID\n");
    return 0;
  }

  switch (str[0])
  {
    case '3':
      if (str[1] == '4' || str[1] == '7')
      {
        firstDigitIsValid = true;
        cardName = "AMEX";
      } 
      else
      {
        firstDigitIsValid = false;
      }
      break;
      
    case '4':
      firstDigitIsValid = true;
      cardName = "VISA";
      break;

    case '5':
      if (str[1] == '1' || str[1] == '2' || str[1] == '3' || str[1] == '4' || str[1] == '5')
      {
        firstDigitIsValid = true;
        cardName = "MASTERCARD";
      } 
      else
      {
        firstDigitIsValid = false;
      }
      break;
      
    default:
      firstDigitIsValid = false;
      break;
  }
  
  if (firstDigitIsValid)
  {
    do
    {
      quotient = number % 10;
      number = number / 10;
      i++;

      if (i % 2 == 0)
      {
        multiply = quotient * 2;
        if (multiply > 9)
        {
          sumFromBegin += (multiply / 10) + (multiply % 10);
        } 
        else
        {
          sumFromBegin += multiply;
        }
      } 
      else
      {
        sumFromTheEnd += quotient;
      }
    } 
    while (number > 0);

    resultSum = (sumFromBegin + sumFromTheEnd) % 10;

    if (resultSum == 0)
    {
      printf("%s\n", cardName);
      return 0;
    } 
    else
    {
      printf("INVALID\n");
      return 0;
    }
  } 
  else
  {
    printf("INVALID\n");
    return 0;
  }
}

/*
American Express uses 15-digit numbers
MasterCard uses 16 digit numbers
Visa uses 13 and 16 digit numbers

All American Express numbers start with 34 or 37
MasterCard numbers start with 51, 52, 53, 54, or 55
Visa numbers start with 4
*/