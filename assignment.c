//assignment.c
//Contains operations for use on polynomials
//date: 2019/12/08
//author: Roger Shanahan, Ciara Sookarry, Anna Shaughnessy, Aoife O'Doherty

#include <stdlib.h>
#include <stdio.h>
#include "assignment.h"


/////////////////////////////////////
// createPoly()
// creates an empty link list 
// head points to tail (NULL)
//
// Parameters: none
// Returns: pointer to list if successful
//          NULL if failed
/////////////////////////////////////

polynomial *createPoly()
{
  polynomial *poly1;
  poly1 = (polynomial *) malloc(sizeof(polynomial)); //allocate memory for poly1
  //check if memory allocated successfully
  if (poly1 != NULL)
  {
    //SUCCESS
    //try to allocate memory for the head
    poly1->head = (stNode *) malloc(sizeof(stNode));
    //check if memory allocated successfully
    if (poly1->head != NULL)
    {
      //SUCCESS
      //point head to tail
      poly1->head->nextptr = NULL;
      //make head the current node
      poly1->current = poly1->head;
    }
    else
    {
      //memory allocation to head failed
      //de-allocate poly1 and set to NULL
      free(poly1);
      poly1 = NULL;
    }
  }
  return poly1; //Failure will return NULL, Success returns a pointer
}

/////////////////////////////////////
// addnode()
// adds a node/term to the polynomial after the current node
//
// Parameters: stNode - data to be contained in the new node
//             poly1  - polynomial in which to add new node
// Returns: Success: pointer to new node
//          Failure: NULL
/////////////////////////////////////

stNode addnode(stNode *node, polynomial *poly1)
{
  stNode *newNode;
  
  // allocate memory for new node
  newNode = (stNode *) malloc(sizeof(stNode));
  if (newNode == NULL)
  {
    //allocation failed
    printf("There is no memory");
  }
  else
  {
    //allocation successful
    //associate data with newNode
    *newNode = *node;
    //place newNode into link list
    //set successor of current node to successor of newNode
    newNode->nextptr = poly1->current->nextptr;
    //set successor of current node to newNode
    poly1->current->nextptr = newNode;
  }
  return *newNode;
}

/////////////////////////////////////
// deletePoly()
// deletes the entire polynomial with the head-node named head
//
// parameter:head -  head of a valid list
// return: void
////////////////////////////////////

int deletePoly(polynomial  *poly1)
{
  polynomial *next  = malloc(sizeof(polynomial *));

  //delete all nodes until list is empty
  //starting at the head
  poly1->current = poly1->head;

  //delete all nodes that are not the head or tail
  while(poly1->head->nextptr != NULL)
  {
    next->current = poly1->head->nextptr;
    poly1->head->nextptr = poly1->head->nextptr->nextptr;
    free(next);
  }
  //link list is now empty
  //now delete head
  free(poly1->head);
  //and delete the list itself
  free(poly1);
  return 0;
}
/////////////////////////////
//double polyadd(polynomial *poly1, polynomial *poly2, polynomial *poly)
//Adds coefficients of each x^n term
//Parameters: *poly1 , *poly2
//         pointers to valid polynomials
//Returns: *poly - pointer to the resultant polynomial
////////////////////////////

polynomial polyAdd(polynomial *poly1, polynomial *poly2, polynomial *poly) 
{
  //Set current nodes to the head
  poly1->current = poly1->head;
  poly2->current = poly2->head;
  
  while(poly1->current->nextptr != NULL && poly2->current->nextptr != NULL) // check that tail isn't reached 
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
    else // If power of both polynomial numbers is same then add their coefficients 
    { 
      poly->current->pow = poly1->current->pow; 
      poly->current->coeff = poly1->current->coeff+poly2->current->coeff; 
      poly1->current = poly1->current->nextptr; 
      poly2->current = poly2->current->nextptr; 
    }  
    // Dynamically create new node
    //stNode newNode; 
    //addnode(newNode, poly);
    poly->current->nextptr = malloc(sizeof(stNode *)); 
    poly->current = poly->current->nextptr; 
    poly->current->nextptr = NULL; 
  } 
  while(poly1->current->nextptr == NULL || poly2->current->nextptr == NULL ) // if one polynomial reaches tail before the other
  { 
    if(poly1->current->nextptr != NULL) //if poly1->current->nextptr is not tail
    { 
      poly->current->pow = poly1->current->pow; 
      poly->current->coeff = poly1->current->coeff; 
      poly1->current = poly1->current->nextptr; 
    } 
    if(poly2->current->nextptr != NULL) //if poly2->current->nextptr is not tail
    { 
      poly->current->pow = poly2->current->pow; 
      poly->current->coeff = poly2->current->coeff; 
      poly2->current = poly2->current->nextptr; 
    }
    //
    poly->current->nextptr = malloc(sizeof(stNode *)); 
    poly->current = poly->current->nextptr; 
    poly->current->nextptr = NULL; 
  }
  return *poly;
}

////////////////////////////////
//double polysubtract(polynomial *poly1, polynomial *poly2, polynomial *poly)
//Subtracts one polynomial from another

//Parameters: poly1 - the polynomial to have the other subtracted from
//            poly2 - the polynomial to subtract from poly1
//            poly  - the resultant polynomial
//Returns: *poly - pointer to the resultant polynomial
///////////////////////////////

polynomial polySubtract(polynomial *poly1, polynomial *poly2, polynomial *poly) 
{ 
  while(poly1->current->nextptr != NULL && poly2->current->nextptr != NULL) //Check that current nodes are not tail 
  {
    // set current nodes to head
    poly1->current = poly1 ->head;
    poly2->current = poly2->head;
    
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
    poly->current->nextptr = malloc(sizeof(stNode *)); 
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
    poly->current->nextptr = malloc(sizeof(stNode *)); 
    poly->current = poly->current->nextptr; 
    poly->current->nextptr = NULL; 
  }
  return *poly;
}

////////////////////////////////////////
//Multiplies each coefficient by a double and returns each
//Parameters: polynomial type, double constant
//Returns: polynomial with each coefficient multiplied by a double
////////////////////////////////////////

polynomial multiplyPoly(polynomial *poly1, polynomial *poly2, polynomial *poly)
// Function two Multiply two polynomial Numbers Node* multiply(Node* poly1, Node* poly2, Node* poly3) 
{
  while (poly1 != NULL) 
  { 
    while (poly2 != NULL) 
    { 
      stNode *temp  = malloc(sizeof(stNode *));               //creates a temporary node that contains a coefficient and a power
      temp->coeff = poly1->current->coeff * poly2->current->coeff;    // Multiply the coefficient of both polynomials and store it in coeff 
      temp->pow = poly1->current->pow + poly2->current->pow;    // Add the powerer of both polynomials and store it in power 
      *poly->current = addnode(temp, poly); // Invoke  function to create  a newnode by passing three parameters 
      poly2->current = poly2->current->nextptr;                    // move the pointer of 2nd polynomial  two get its next term 
    }
    poly1->current = poly1->current->nextptr;  // move the pointer of 1st polynomial
  }   
  //removeDuplicates(poly); // this function will be invoke to add the coefficient of the elements having same power from the resultant linked list
  return *poly;
}


///////////////////////////////////
//Divides two polynominals
///////////////////////////////////
polynomial dividePoly(polynomial *poly1, polynomial *poly2, polynomial *poly)
{
  while (poly1 != NULL) 
  { 
    while (poly2 != NULL) 
    { 
      stNode *temp  = malloc(sizeof(stNode *));     //creates a temporary node that contains a coefficient and a power
      temp->coeff = poly1->current->coeff / poly2->current->coeff; // Divide the coefficient of both polynomials and store it in coeff 
      temp->pow = poly1->current->pow - poly2->current->pow; // Subtract the power of both polynomials and store it in power 
      *poly->current = addnode(temp, poly); // Invoke addnode function to create a newnode by passing twp parameters
      poly2->current = poly2->current->nextptr; // move the pointer of 2nd polynomial two get its next term 
    }
    poly1->current = poly1->current->nextptr; // Move the pointer of 1st polynomial 
  }   
  //removeDuplicates(poly); // this function will be invoke to add the coefficient of the elements having same power from the resultant linked list
  return *poly;
}


/////////////////////////////////////
// normalisePoly()
// divides all coefficients of the polynomial by the value of the coefficient of the highest order term
//
// parameter: *poly1 - polynomial 
// return: *poly5 - new polynomial with all coefficient of *poly1 divided by the coefficient of its highest order term
////////////////////////////////////
polynomial normalisePoly(polynomial *poly1, polynomial *poly5)
{ 
  poly1->current = poly1->head; // Set current node to the head
  double a = poly1->head->nextptr->coeff; // assign a to the coefficient of the node after head
  stNode *temp  = malloc(sizeof(stNode *));                   //creates a temporary node that contains a coefficient and a power
  while (poly1->current != NULL) 
  {          
    // Divide the coefficients of the polynomials
    temp->coeff = (poly1->current->coeff) / a;  
    temp->pow = poly1->current->pow;
    // Invoke addnode function to create a newnode by passing two parameters 
    *poly5->current = addnode(temp, poly5); 
    // move the pointer of the polynomial to get its next term 
    poly1->current = poly1->current->nextptr; 
  }
  return *poly5;
}

//////////////////////////////////
// int returnOrder()
// returns the order of the polynomial
// i.e. the highest power of x^n with a coefficient != 0
//
//Parameter: polynomial of type polynomial
//Returns: integer value of highest power
//////////////////////////////////
int returnOrder(polynomial *poly)
{
  int highestOrder = 0;
  //make the head the current node
  poly->current = poly->head;
  //move to the next node
  //this will be the term with the highest power...
  // ...becuase of the order we chose to print in
  while(poly->current->nextptr != NULL && highestOrder == 0) 
  {
    if(poly->current->coeff != 0)
    {
      highestOrder = poly->current->coeff;
    }
    else
    {
      poly->current = poly->current->nextptr;
    }
  }
  //return the power associated with this first node
  return highestOrder;
}

////////////////////////////////////////
//Name:     void printPolynomial(struct Node *poly)
//Purpose:  Prints the polynoomial given to stdout
//          Uses a while loop so that it will run through all the values of the polynomial
//          until it reaches the end (ie NULL)
//Parameters:   struct Node *polynomial
//Returns:   void
///////////////////////////////////////

int printPolynomial(polynomial *poly) //printPolynomial function accepts the structure of polynomial
{
  if(poly == NULL)
    return 1;
  poly->current = poly->head;           //sets the current polynomial to the head
  while(poly->current != NULL)          //while current state is not NULL
  {
    if((poly->current->coeff)>0)        //if the coefficient is greater than zero
    {
        printf("+ %lf x^(%d) ", poly->current->coeff, poly->current->pow); //print the coeffieient and power preceeded by a positive sign
    }
    else
    {
      printf("%lf x^(%d) ", poly->current->coeff, poly->current->pow);   //print the coeffieient and power with no sign
                                                                         //this is because if the value is negative the value for the coeffieient will already contain a negative sign
    } 
    poly->current = poly->current->nextptr;         //move the polynomial to the next value
  }
  return 0;
}

