//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
//Authors: Ciara Sookarry, Roger Shanahan, Aoife O`Doherty, Anna Shaughnessy
//Date: 26/11/19 (Update as necessary)

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "assignment.h"



int main()
{
  
  int highest_exponent; //user-entered value: largest value of n for x^n
  printf("Let's enter a polynomial!!\n\n");
  printf("Input value for highest value exponent:\n");
  scanf("%d", &highest_exponent);

  int max_coefficients = highest_exponent+1;
  createNodeList(max_coefficients);
  displayList(highest_exponent);
  return 0;
}


  


   
