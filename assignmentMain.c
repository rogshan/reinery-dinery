//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
//Authors: Ciara Sookarry, Roger Shanahan, 
//Date: 21/11/19 (Update as necessary)

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "assignment.h"

void fillArray(double *ptrArray[], int high_exponent, double coefficient[])
{ 
  for (int j=high_exponent; j >= coefficient[high_exponent]; j--)
  {
    double value = (coefficient[j] );
    ptrArray[j] = &value;
  }
}

void printArray(double *ptrArray[], int high_exponent)
{
  for (int z=high_exponent; z>=0; --z)
  {
    printf("The polynomial is: %lf x^ %d", *ptrArray[z], z);
  }
}


int main()
{
  int highest_exponent; //user-entered value: largest value of n for x^n
  printf("Let's enter a polynomial!!\n");
  printf("Input value for highest value exponent\n:");
  scanf("%d", &highest_exponent);
  double coefficient[highest_exponent];
  double *array[highest_exponent]; //creates pointer array to fill
  
  for (int i=0; i<=highest_exponent; i++)
  {
      printf("Input the coefficient for the highest value exponent:\n");
      scanf("%lf",&coefficient[i]);
  }
  fillArray(array, highest_exponent, coefficient);
  printArray(array, highest_exponent);
}
