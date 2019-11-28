//assignment.c
//Contains operations for use on polynomials
//date: 28/11/2019
//author: Roger Shanahan, Ciara Sookarry, Anna Shaughnessy

//I think we'll need to make a polynomial type

#include <stdlib.h>
#include <stdio.h>
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
//double addPoly(double coeff1, double coeff2)

double polyadd(polynomial *poly1, polynomial *poly2, polynomial *poly) 
{ 
  while(poly1->nextptr && poly2->nextptr) 
  { 
    // If power of 1st polynomial is greater then 2nd, then store 1st as it is and move its pointer 
        if(poly1->pow > poly2->pow) 
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
          
        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is and move its pointer 
        else if(poly1->pow < poly2->pow) 
        { 
            poly->pow = poly2->pow; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
          
        // If power of both polynomial numbers is same then add their coefficients 
        else
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff+poly2->coeff; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
          
        // Dynamically create new node 
        poly->next = (polynomial *)malloc(sizeof(polynomial)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
while(poly1->next || poly2->next) 
    { 
        if(poly1->next) 
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
        if(poly2->next) 
        { 
            poly->pow = poly2->pow; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
        poly->next = (polynomial *)malloc(sizeof(polynomial)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
   
  
}


//double subtractPoly(double coeff1, coeff2)
//Subtractss coefficients of each x^n term
//Maybe uses a for loop?????
//Inputs: coefficients of 2 terms
//Output: sum of 2 coefficents
//double subtractPoly(double coeff1, double coeff2)

double polysubtract(polynomial *poly1, polynomial *poly2, polynomial *poly) 
{ 
while(poly1->nextptr && poly2->nextptr) 
    { 
        // If power of 1st polynomial is greater then 2nd, then store 1st as it is and move its pointer 
        if(poly1->pow > poly2->pow) 
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
          
        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is and move its pointer 
        else if(poly1->pow < poly2->pow) 
        { 
            poly->pow = poly2->pow; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
          
        // If power of both polynomial numbers is same then subtract their coefficients 
        else
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff-poly2->coeff; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
          
        // Dynamically create new node 
        poly->next = (polynomial *)malloc(sizeof(polynomial)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
while(poly1->next || poly2->next) 
    { 
        if(poly1->next) 
        { 
            poly->pow = poly1->pow; 
            poly->coeff = poly1->coeff; 
            poly1 = poly1->next; 
        } 
        if(poly2->next) 
        { 
            poly->pow = poly2->pow; 
            poly->coeff = poly2->coeff; 
            poly2 = poly2->next; 
        } 
        poly->next = (polynomial *)malloc(sizeof(polynomial)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
}

//Multiplies each coefficient by a double and returns each
//Inputs: polynomial type, double constant
//Output: polynomial with each coefficient multiplied by a double
double multiplyPoly(polynomial *poly1, polynomial *poly2, polynomial *poly)
{
// Function two Multiply two polynomial Numbers Node* multiply(Node* poly1, Node* poly2, Node* poly3) 
{
    // Create two pointer and store the address of 1st and 2nd polynomials 
    polyNode *ptr1, *ptr2; 
    ptr1 = poly1; 
    ptr2 = poly2; 
    while (ptr1 != NULL) { 
        while (ptr2 != NULL) { 
            int coeff, power; 
  
            // Multiply the coefficient of both polynomials and store it in coeff 
            coeff = ptr1->coeff * ptr2->coeff; 
  
            // Add the powerer of both polynomials and store it in power 
            power = ptr1->power + ptr2->power; 
  
            // Invoke addnode function to create  a newnode by passing three parameters 
            poly3 = addnode(poly3, coeff, power); 
  
            // move the pointer of 2nd polynomial  two get its next term 
            ptr2 = ptr2->next; 
        } 
  
        // Move the 2nd pointer to the starting point of 2nd polynomial 
        ptr2 = poly2; 
  
        // move the pointer of 1st polynomial 
        ptr1 = ptr1->next; 
    } 
  
    // this function will be invoke to add the coefficient of the elements having same powerer from the resultant linked list 
    removeDuplicates(poly3); 
    return poly3; 
}     
}



//Divides two polynominals
double dividePoly(polynomial *poly1, polynomial *poly2, polynomial *poly4)
{
// Function two Multiply two polynomial Numbers Node* multiply(Node* poly1, Node* poly2,  Node* poly) 
{ 
  
    // Create two pointer and store the address of 1st and 2nd polynomials 
    polyNode *ptr1, *ptr2; 
    ptr1 = poly1; 
    ptr2 = poly2; 
    while (ptr1 != NULL) { 
        while (ptr2 != NULL) { 
            int coeff, power; 
  
            // Divide the coefficient of both polynomials and store it in coeff 
            coeff = ptr1->coeff / ptr2->coeff; 
  
            // Subtract the power of both polynomials and store it in power 
            power = ptr1->power - ptr2->power; 
  
            // Invoke addnode function to create a newnode by passing three parameters 
            poly4 = addnode(poly4, coeff, power); 
  
            // move the pointer of 2nd polynomial two get its next term 
            ptr2 = ptr2->next; 
        } 
  
        //   Move the 2nd pointer to the starting point of 2nd polynomial 
        ptr2 = poly2; 
  
        // move the pointer of 1st polynomial 
        ptr1 = ptr1->next; 
    } 
  
    // this function will be invoke to add  the coefficient of the elements  having same powerer from the resultant linked list 
    removeDuplicates(poly4); 
    return poly4; 
}     
}

//Name:     void printPolynomial(struct Node *poly)
//Purpose:  Prints the polynoomial given to stdout
//          Uses a while loop so that it will run through all the values of the polynomial
//          until it reaches the end (ie NULL)
//Inputs:   struct Node *polynomial
//Output:   prints the polynomial to stdout

void printPolynomial(struct Node *poly) //printPolynomial function accepts the structure of polynomial
{
  poly->current = poly->head;           //sets the current polynomial to the head
  while(poly->current != NULL)          //while current state is not NULL
  {
    if((poly->current->coeff)>0)        //if the coefficient is greater than zero
    {
      if(poly->next = NULL)
      {
        fprintf("%lf x^(%d) ", poly->current->coeff, poly->current->power);
      }
      else
      {
        fprintf("%lf x^(%d) + ", poly->current->coeff, poly->current->power); //print the coeffieient and power followed by a poitive sign
      }
    }
    else
    {
      fprintf("%lf x^(%d) ", poly->current->coeff, poly->current->power);   //print the coeffieient and power with no sign
                                                                            //this is because if the value is negative the value for the coeffieient will already contain a negative sign
    } 
    poly->current = poly->next;         //move the polynomial to the next value
  }
}

// int returnOrder()
// returns the order of the polynomial
// i.e. the highest power of x^n with a coefficient != 0
//
//Parameter: polynomial of type polynomial
//Returns: integer value of highest power
int returnOrder(polynomial *poly1)
{
  //make the head the current node
  polynomial->current = polynomial->head;
  //move to the next node
  //this will be the term with the highest power...
  // ...becuase of the order we chose to print in
  polynomial->current = polynomial->current->nextptr;
  //return the power associated with this first node
  return polynomial->current->pow;
}

