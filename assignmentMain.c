//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
//Authors: Ciara Sookarry, Roger Shanahan, Aoife O`Doherty, Anna Shaughnessy
//Date: 26/11/19 (Update as necessary)

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "assignment.h"


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

        printf("Input coefficient for highest value exponent: ");
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
                printf("Memory can not be allocated.");
                break;
            }
            else
            {
                printf("Input coefficient for next value: ");
                scanf(" %d", &num);
 
                fnNode->num = num;      // links the num field of fnNode with num
                fnNode->nextptr = NULL; // links the address field of fnNode with NULL
 
                tmp->nextptr = fnNode; // links previous node i.e. tmp to the fnNode
                tmp = tmp->nextptr; 
            }
        }
    }
}

void displayList(int highest_exponent)
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
	  for(int i=highest_exponent; i>=0; --i)
	    {
	      if(i>0)
		{
		  printf("%dx^%d,  ", tmp->num,i);       // prints the data of current node
		  tmp = tmp->nextptr;                     // advances the position of current node
		}
	      else
		{
		  printf("%d\n", tmp->num); 
		}
		
	    }
        }
    }
}

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


  


   
