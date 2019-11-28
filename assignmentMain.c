//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
//Authors: Ciara Sookarry, Roger Shanahan, Aoife O`Doherty, Anna Shaughnessy
//Date: 26/11/19 (Update as necessary)

#include <stdlib.h>
#include <stdio.h>
#include "assignment.h"


int main()
{
  int highest_exponent = 0;
  int max_coefficients = highest_exponent+1;
  createNodeList(max_coefficients);
  displayList(highest_exponent);
  return 0;
}


  


   
