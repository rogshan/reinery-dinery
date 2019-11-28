//assignment.c
//Contains operations for use on polynomials
//date: 28/11/2019
//author: Roger Shanahan, Ciara Sookarry, Anna Shaughnessy, Aoife O'Doherty

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

//double polyadd(polynomial *poly1, polynomial *poly2, polynomial *poly)
//Adds coefficients of each x^n term
//Parameters: *poly1 , *poly2
//         pointers to valid polynomials
//Returns: *poly ????
//         pointer to the resultant polynomial

double polyadd(polynomial *poly1, polynomial *poly2, polynomial *poly) 
{ 
  while(poly1->nextptr && poly2->nextptr) 
  {
    if(poly1->current->pow > poly2->current->pow) // If power of 1st polynomial is greater then 2nd, then store 1st as it is and move its pointer 
    { 
      poly->current->pow = poly1->current->pow; 
      poly->current->coeff = poly1->current->coeff; 
      poly1->current = poly1->next; 
    } 
    else if(poly1->pow < poly2->pow) // If power of 2nd polynomial is greater then 1st, then store 2nd as it is and move its pointer
    { 
      poly->current->pow = poly2->current->pow; 
      poly->current->coeff = poly2->current->coeff; 
      poly2->current = poly2->next; 
    } 
    else // If power of both polynomial numbers is same then add their coefficients 
    { 
      poly->current->pow = poly1->current->pow; 
      poly->current->coeff = poly1->current->coeff+poly2->current->coeff; 
      poly1->current = poly1->next; 
      poly2->current = poly2->next; 
    }  
    // Dynamically create new node 
    poly->next = (polynomial *)malloc(sizeof(polynomial)); 
    poly->current = poly->next; 
    poly->next = NULL; 
  } 
  while(poly1->next || poly2->next) 
  { 
    if(poly1->next) 
    { 
      poly->current->pow = poly1->current->pow; 
      poly->current->coeff = poly1->current->coeff; 
      poly1->current = poly1->next; 
    } 
    if(poly2->next) 
    { 
      poly->current->pow = poly2->current->pow; 
      poly->current->coeff = poly2->current->coeff; 
      poly2->current = poly2->next; 
    } 
    poly->next = (polynomial *)malloc(sizeof(polynomial)); 
    poly->current = poly->next; 
    poly->next = NULL; 
  } 
}


//double polysubtract(polynomial *poly1, polynomial *poly2, polynomial *poly)
//Subtracts onr polynomial from another
//Parameters: 
//Returns: 

void polysubtract(polynomial *poly1, polynomial *poly2, polynomial *poly) 
{ 
  while(poly1->nextptr && poly2->nextptr) 
  { 
    if(poly1->current->pow > poly2->current->pow) // If power of 1st polynomial is greater then 2nd, then store 1st as it is and move its pointer 
    { 
      poly->current->pow = poly1->current->pow; 
      poly->current->coeff = poly1->current->coeff; 
      poly1->current = poly1->current->nextptr; 
    }   
    else if(poly1->current->pow < poly2->current->pow) // If power of 2nd polynomial is greater then 1st, then store 2nd as it is and move its pointer 
    { 
      poly->current->pow = poly2->current->pow; 
      poly->current->coeff = poly2->current->coeff; 
      poly2->current = poly2->current->nextptr; 
    }   
    else // If power of both polynomial numbers is same then subtract their coefficients 
    { 
      poly->current->pow = poly1->current->pow; 
      poly->current->coeff = poly1->current->coeff-poly2->current->coeff; 
      poly1->current = poly1->current->nextptr; 
      poly2->current = poly2->current->nextptr; 
    }     
    // Dynamically create new node 
    poly->current->nextptr = (polynomial *)malloc(sizeof(polynomial)); 
    poly->current = poly->current->nextptr; 
    poly->current->nextptr = NULL; 
  } 
  while(poly1->current->nextptr || poly2->current->nextptr) 
  { 
    if(poly1->current->nextptr) 
    { 
      poly->current->pow = poly1->current->pow; 
      poly->current->coeff = poly1->current->coeff; 
      poly1->current = poly1->current->nextptr; 
    } 
    if(poly2->current->nextptr) 
    { 
      poly->current->pow = poly2->current->pow; 
      poly->current->coeff = poly2->current->coeff; 
      poly2->current = poly2->current->nextptr; 
    } 
    poly->current->nextptr = (polynomial *)malloc(sizeof(polynomial)); 
    poly->current = poly->current->nextptr; 
    poly->current->nextptr = NULL; 
  } 
}

//Multiplies each coefficient by a double and returns each
//Parameters: polynomial type, double constant
//Returns: polynomial with each coefficient multiplied by a double
void multiplyPoly(polynomial *poly1, polynomial *poly2, polynomial *poly) // Function two Multiply two polynomial Numbers Node* multiply(Node* poly1, Node* poly2, Node* poly3) 
{
  while (poly1 != NULL) 
  { 
    while (poly2 != NULL) 
    { 
      int coeff, power; 
      coeff = poly1->current->coeff * poly2->current->coeff;    // Multiply the coefficient of both polynomials and store it in coeff 
      power = poly1->current->pow + poly2->current->pow;    // Add the powerer of both polynomials and store it in power 
      poly->current = addnode(poly, coeff, power); // Invoke addnode function to create  a newnode by passing three parameters 
      poly2->current = poly2->current->nextptr;                    // move the pointer of 2nd polynomial  two get its next term 
    }
    poly1->current = poly1->current->nextptr;  // move the pointer of 1st polynomial
  }   
  removeDuplicates(poly); // this function will be invoke to add the coefficient of the elements having same powerer from the resultant linked list 
  return poly;    
}



//Divides two polynominals
void dividePoly(polynomial *poly1, polynomial *poly2, polynomial *poly4)
{
  while (poly1 != NULL) 
  { 
    while (poly2 != NULL) 
    { 
      int coeff, power; 
      coeff = poly1->current->coeff / poly2->current->coeff; // Divide the coefficient of both polynomials and store it in coeff 
      power = poly1->current->pow - poly2->current->pow; // Subtract the power of both polynomials and store it in power 
      poly4->current = addnode(poly4, coeff, power); // Invoke addnode function to create a newnode by passing three parameters
      poly2->current = poly2->current->nextptr; // move the pointer of 2nd polynomial two get its next term 
    }
    poly1->current = poly1->current->nextptr; // Move the pointer of 1st polynomial 
  }   
  removeDuplicates(poly4); // this function will be invoke to add the coefficient of the elements having same power from the resultant linked list 
  return poly4;   
}

//Name:     void printPolynomial(struct Node *poly)
//Purpose:  Prints the polynoomial given to stdout
//          Uses a while loop so that it will run through all the values of the polynomial
//          until it reaches the end (ie NULL)
//Parameters:   struct Node *polynomial
//Returns:   prints the polynomial to stdout
void printPolynomial(polynomial *poly) //printPolynomial function accepts the structure of polynomial
{
  poly->current = poly->head;           //sets the current polynomial to the head
  while(poly->current != NULL)          //while current state is not NULL
  {
    if((poly->current->coeff)>0)        //if the coefficient is greater than zero
    {
      if(poly->current->nextptr = NULL)
      {
        printf("%lf x^(%d) ", poly->current->coeff, poly->current->pow);
      }
      else
      {
        printf("%lf x^(%d) + ", poly->current->coeff, poly->current->pow); //print the coeffieient and power followed by a positive sign
      }
    }
    else
    {
      printf("%lf x^(%d) ", poly->current->coeff, poly->current->pow);   //print the coeffieient and power with no sign
                                                                            //this is because if the value is negative the value for the coeffieient will already contain a negative sign
    } 
    poly->current = poly->current->nextptr;         //move the polynomial to the next value
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
  poly1->current = poly1->head;
  //move to the next node
  //this will be the term with the highest power...
  // ...becuase of the order we chose to print in
  poly1->current = poly1->current->nextptr;
  //return the power associated with this first node
  return poly1->current->pow;
}

double normalisePoly(polynomial *poly1, polynomial *poly5)
{ 
    // Create two pointer and store the address of the polynomial
    int coeff;
    polyNode *ptr1;
    ptr1 = poly1;
    //poly->*head->coeff ??
    poly->current->coeff=int a;
    while (ptr1 != NULL) { 
             
            // Divide the coefficients of the polynomials
            coeff = ptr1->coeff / a;  
  
            // Invoke addnode function to create a newnode by passing three parameters 
            poly5 = addnode(poly5, coeff, power); 
  
            // move the pointer of the polynomial to get its next term 
            ptr1 = ptr1->next; 
    }
    return poly5; 
}     



/////////////////////////////////////
// deletePoly()
// deletes the entire polynomial with the head-node named head
//
// parameter:head -  head of a valid list
// return: void
////////////////////////////////////
void deletePoly(polynomial *poly1)
{
  polynomial *next;

  //delete all nodes until list is empty
  //starting at the head
  poly1->current = poly1->head;

  //delete all nodes that are not the head or tail
  while(poly1->head->successor != NULL){
    next = poly1->head->successor;
    poly1->head->successor = poly1->head->successor->successor;
    free(next);
  }
  //link list is now empty
  //now delete head
  free(poly1->head);
  //and delete the list itself
  free(poly1)
}
