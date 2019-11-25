//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
<<<<<<< HEAD
//Authors: Ciara Sookarry, Anna Shaughnessy 
//Date: 22/11/19 (Update as necessary)
||||||| merged common ancestors
//Authors: Ciara Sookarry, 
//Date: 21/11/19 (Update as necessary)
=======
//Authors: Ciara Sookarry, Roger Shanahan, Aoife O`Doherty
//Date: 21/11/19 (Update as necessary)
>>>>>>> c924338a79ffb3e864c1ed3cee6e30a5d7911a32

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "assignment.h"

<<<<<<< HEAD

void fillArray(double[] array, int highest_exponent, double[] coefficient){ //Function to fill array with user inputted values
  int j;
  for (j=0, j>=coefficient[highest_exponent], --j){ //For loop to fill array with value of the highest exponent first, then second highest etc
    array[j]= coefficient[j]*(x^(j)); //In the form a(x^exponent)
||||||| merged common ancestors
<<<<<<< HEAD
void fillArray(double[] array, int highest_exponent, double[] coefficient ){ 
  int j;
  double[] array;
  for (j=0, j>=coefficient[highest_exponent], j++){
    array[j]= coefficient[j]*(x^(j));
=======
void fillArray(double *ptrArray[], int high_exponent, double coefficient[])
{ 
  for (int j=high_exponent; j >= coefficient[high_exponent]; j--)
  {
    double value = (coefficient[j] );
    ptrArray[j] = &value;
>>>>>>> c924338a79ffb3e864c1ed3cee6e30a5d7911a32
  }
}

<<<<<<< HEAD
void printArray(int highest_exponent, double[] array){ //Function to print array.
  int z;
  for (z=highest_exponent, z>=0, --z){ //For loop to print array with the highest exponent value first, decreasing down.
    printf("The polynomial is: %lf", array[z]); 
||||||| merged common ancestors
void printArray(int highest_exponent, double[] array){
  int z;
  for (z=highest_exponent, z>=0, --z){
    printf("The polynomial is: %lf", array[z]);
=======
void printArray(double *ptrArray[], int high_exponent)
{
  for (int z=high_exponent; z>=0; --z)
  {
    printf("The polynomial is: %lf x^ %d", *ptrArray[z], z);
>>>>>>> c924338a79ffb3e864c1ed3cee6e30a5d7911a32
  }
}


<<<<<<< HEAD
int main(){
  int highest_exponent; //User-entered value: largest value of n for x^n
  printf("Let's enter a polynomial!!\n");
||||||| merged common ancestors
int main(){
  int highest_exponent;
=======
int main()
{
  int highest_exponent; //user-entered value: largest value of n for x^n
  printf("Let's enter a polynomial!!\n");
>>>>>>> c924338a79ffb3e864c1ed3cee6e30a5d7911a32
  printf("Input value for highest value exponent\n:");
  scanf("%d", &highest_exponent);
<<<<<<< HEAD
  double[] coefficient; //Array to store the user inputted coefficients
||||||| merged common ancestors
  int[] coefficient;
=======
  double coefficient[highest_exponent];
  double *array[highest_exponent]; //creates pointer array to fill
>>>>>>> c924338a79ffb3e864c1ed3cee6e30a5d7911a32
  
<<<<<<< HEAD
  int i;
  for (i=0, i<=highest_exponent, i++){ //Creates the array by scanning the user inputted coefficients 
||||||| merged common ancestors
  int i;
  for (i=0, i<=highest_exponent, i++){
=======
  for (int i=0; i<=highest_exponent; i++)
  {
>>>>>>> c924338a79ffb3e864c1ed3cee6e30a5d7911a32
      printf("Input the coefficient for the highest value exponent:\n");
<<<<<<< HEAD
      scanf("%lf",&coefficient[i]); 
	i=i+1;
    }
  fillArray(double[],int, double[]);
  printArray(int, double[]);
||||||| merged common ancestors
      scanf("%lf",&coefficient[i]);
	i=i+1;
    }
  fillArray();
  printArray();
=======
int main()
{
  int highestExp; //user-entered value: largest value of n for x^n
  
  printf("Let's enter a polynomial!!\n");
  printf("Enter highest exponent: ");
  scanf("%d", &highestExp);
>>>>>>> a7c8f67106824fa806526beb0b7e3301eafbf647
=======
      scanf("%lf",&coefficient[i]);
  }
  fillArray(array, highest_exponent, coefficient);
  printArray(array, highest_exponent);
>>>>>>> c924338a79ffb3e864c1ed3cee6e30a5d7911a32
}
