//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
//Authors: Ciara Sookarry, Roger Shanahan, Aoife O`Doherty, Anna Shaughnessy
//Date: 25/11/19 (Update as necessary)

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "assignment.h"
    
void fillArray(double *ptrArray[], int high_exponent, double coefficient[]) //Function to fill coefficient array with user inputted values
{ 
  for (int j=high_exponent; j >= coefficient[high_exponent]; j--)//For loop to fill array with value of the exponent order of decreasing value 
  {
    double value = (coefficient[j] );
    ptrArray[j] = &value;
  }
}

void printArray(double *ptrArray[], int high_exponent) //Function to print array.
{
  for (int z=high_exponent; z>=0; --z) //For loop to print array with the highest exponent value first, decreasing down
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
  double coefficient[highest_exponent];//stores the user inputted coefficients
  double *array[highest_exponent]; //creates pointer array to fill

  for (int i=0; i<=highest_exponent; i++) //Creates the array by scanning the user inputted coefficients 
  {
    printf("Input the coefficient for the highest value exponent:\n");
    scanf("%lf",&coefficient[i]); 
  }
  fillArray(array, highest_exponent, coefficient); //Calling function fillArray
  printArray(array, highest_exponent); //Calling function printArray
}
