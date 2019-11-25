//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
//Authors: Ciara Sookarry, Anna Shaughnessy 
//Date: 22/11/19 (Update as necessary)

#include <stdlib.h>
#include <stdio.h>


void fillArray(double[] array, int highest_exponent, double[] coefficient){ //Function to fill array with user inputted values
  int j;
  for (j=0, j>=coefficient[highest_exponent], --j){ //For loop to fill array with value of the highest exponent first, then second highest etc
    array[j]= coefficient[j]*(x^(j)); //In the form a(x^exponent)
  }
}

void printArray(int highest_exponent, double[] array){ //Function to print array.
  int z;
  for (z=highest_exponent, z>=0, --z){ //For loop to print array with the highest exponent value first, decreasing down.
    printf("The polynomial is: %lf", array[z]); 
  }
}


int main(){
  int highest_exponent; //User-entered value: largest value of n for x^n
  printf("Let's enter a polynomial!!\n");
  printf("Input value for highest value exponent\n:");
  scanf("%d", &highest_exponent);
  double[] coefficient; //Array to store the user inputted coefficients
  
  int i;
  for (i=0, i<=highest_exponent, i++){ //Creates the array by scanning the user inputted coefficients 
      printf("Input the coefficient for the highest value exponent:\n");
      scanf("%lf",&coefficient[i]); 
	i=i+1;
    }
  fillArray(double[],int, double[]);
  printArray(int, double[]);
}
