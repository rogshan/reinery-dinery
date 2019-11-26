//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
//Authors: Ciara Sookarry, Roger Shanahan, Aoife O`Doherty, Anna Shaughnessy
//Date: 25/11/19 (Update as necessary)

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
//#include "assignment.h"

/*
void fillArray(double *ptrArray[], int highest_exponent, double coefficient[]) //Function to fill coefficient array with user inputted values
{ 
  for (int j=highest_exponent; j >= coefficient[highest_exponent]; j--)//For loop to fill array with value of the exponent order of decreasing value 
  {
    double value = (coefficient[j] );
    ptrArray[j] = &value;
  }
}

void printArray(double *ptrArray[], int highest_exponent) //Function to print array.
{
  for (int z=highest_exponent; z>=0; --z) //For loop to print array with the highest exponent value first, decreasing down
  {
    printf("The polynomial is: %lf x^ %d", *ptrArray[z], z);
  }
}

*/

struct node 
  {
    int num;                        //Data of the node
    struct node *nextptr;           //Address of the next node
  }*stnode;

void createNodeList(int max_coefficients)
{
    struct node *fnNode, *tmp;
    int num, i;
    stnode = (struct node *)malloc(sizeof(struct node));

    if(stnode == NULL) //check whether the fnnode is NULL and if so no memory allocation
    {
        printf(" Memory can not be allocated.");
    }
    else
    {
// reads data for the node through keyboard

        printf(" Inputcoefficient for highest value exponent: ");
        scanf("%d", &num);
        stnode->num = num;      
        stnode->nextptr = NULL; // links the address field to NULL
        tmp = stnode;
// Creating n nodes and adding to linked list
        for(i=2; i<=max_coefficients; i++)
        {
            fnNode = (struct node *)malloc(sizeof(struct node));
            if(fnNode == NULL)
            {
                printf(" Memory can not be allocated.");
                break;
            }
            else
            {
                printf(" Input coefficient for next value: ");
                scanf(" %d", &num);
 
                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL
 
                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr; 
            }
        }
    }
}

void displayList()
{
    struct node *tmp;
    if(stnode == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = stnode;
        while(tmp != NULL)
        {
            printf(" Data = %d\n", tmp->num);       // prints the data of current node
            tmp = tmp->nextptr;                     // advances the position of current node
        }
    }
}

int main()
{
  
  int highest_exponent; //user-entered value: largest value of n for x^n
  printf("Let's enter a polynomial!!\n");
  printf("Input value for highest value exponent:\n");
  scanf("%d", &highest_exponent);
  /*
  double coefficient[highest_exponent];//stores the user inputted coefficients
  double *array[highest_exponent]; //creates pointer array to fill
*/
  

  int max_coefficients = highest_exponent+1;
       	printf("\n\n Linked List : To create and display Singly Linked List :\n");
       	printf("-------------------------------------------------------------\n");
		
    
    createNodeList(max_coefficients);
    printf("\n Data entered in the list : \n");
    displayList();
    return 0;
  
     
    // fillArray(array, highest_exponent, coefficient); //Calling function fillArray
    // printArray(array, highest_exponent); //Calling function printArray
}


  


   
