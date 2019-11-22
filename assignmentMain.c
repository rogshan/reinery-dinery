//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
//Authors: Ciara Sookarry, 
//Date: 21/11/19 (Update as necessary)

#include <stdlib.h>
#include <stdio.h>
#include "assignment.h"

void fillArray(double[] array, int highest_exponent, double[] coefficient )
{ 
  double[] array;
  for (int j=0, j>=coefficient[highest_exponent], j++)
  {
    array[j]= coefficient[j]*(x^(j));
  }
}

void printArray(int highest_exponent, double[] array)
{
  int z;
  for (z=highest_exponent, z>=0, --z)
  {
    printf("The polynomial is: %lf", array[z]);
  }
}


int main()
{
  int highest_exponent; //user-entered value: largest value of n for x^n
  printf("Let's enter a polynomial!!\n");
  printf("Input value for highest value exponent\n:");
  scanf("%d", &highest_exponent);
  int[] coefficient;
  
  int i;
  for (i=0, i<=highest_exponent, i++)
  {
      printf("Input the coefficient for the highest value exponent:\n");
      scanf("%lf",&coefficient[i]);
	i=i+1;
    }
  fillArray();
  printArray();
}
