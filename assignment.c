//assignment.c
//
//Contains operations for use on polynomials
//date: 2019/11/27
//author: Roger Shanahan, Ciara Sookarry

//I think we'll need to make a polynomial type

#include "assignment.h"

/*
void readPolynomial(struct polynomial poly[10])
{
  int totalNum; //total number of values

  printf("Please enter the total number of terms used in the polynomial");
  scanf("&d", &totalNum);
  
  printf("Please enter the coefficient and exponent\n");
  for(int i = 0l i<totalNum; i++)
  {
    printf("Enter the coeffieient (%d): ", i+1);
    scanf("%lf", &poly[i].coefficient);
    printf("Enter the exponent (%d): ", i+1);
    scanf("%lf", &poly[i].exponent);
  }
  return totalNum;
}
*/
void createNodeList(int max_coefficients)
{
  struct node *fnNode, *tmp;
  int num, i;
  stnode = (struct node *)malloc(sizeof(struct node));
  if(stnode == NULL) //check whether the fnnode is NULL and if so no memory allocation
  {
    printf(" Memory can not be allocated.");
  }
  else // reads data for the node through keyboard
  {
    printf("Input coefficient for highest value exponent: ");
    scanf("%d", &num);
    stnode->num = num;      
    stnode->nextptr = NULL; // links the address field to NULL
    tmp = stnode;
    for(i=2; i<=max_coefficients; i++) // Creating n nodes and adding to linked list
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
		      tmp = tmp->nextptr;                    // advances the position of current node
	    	}
	      else
		    {
		      printf("%d\n", tmp->num); 
	    	}
	    }
    }
  }
}

//double addPoly(double coeff1, coeff2)
//Adds coefficients of each x^n term
//Maybe uses a for loop?????
//Inputs: coefficients of 2 terms
//Output: sum of 2 coefficents
double addPoly(double coeff1, double coeff2)
{
  //I'm not really sure how to code this right now
}

//double subtractPoly(double coeff1, coeff2)
//Subtractss coefficients of each x^n term
//Maybe uses a for loop?????
//Inputs: coefficients of 2 terms
//Output: sum of 2 coefficents
double subtractPoly(double coeff1, double coeff2)
{
  //I'm not really sure how to code this right now
}

//double multiplyPoly(polynomial poly, double constant)
//Multiplies each coefficient by a double and returns each
//Inputs: polynomial type, double constant
//Output: polynomial with each coefficient multiplied by a double
double multiplyPoly()
{
  
}
