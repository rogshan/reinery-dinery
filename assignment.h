//assignment.h
//
//Header file containing function declarations and polynomial type definition
//
//Author: Ciara Sookarry, Roger Shanahan
//Date: 22/11/19
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

//declarations of functions to create link list
void createNodeList(int max_coefficients);
void displayList(int highest_exponent);

//Definition of a link list node
typedef struct n //n is a dummy variable so that we can use this new data type within the struct itself
{
  double coeff; //coefficient of a term
  int pow; //power of x^n term
  struct n *nextptr; //pointer to the next node in the link list
}stNode;

//Definition of polynomial type
typedef struct
{
  stNode *head; //pointer to the head of the link list
  stNode *current; //pointer to the current node
}polynomial;

//declarations of functions to manipulate polynomial
void polyadd(polynomial *poly1, polynomial *poly2, polynomial *poly);
void polysubtract(polynomial *poly1, polynomial *poly2, polynomial *poly);
void multiplyPoly(polynomial *poly1, polynomial *poly2, polynomial *poly);
void dividePoly(polynomial *poly1, polynomial *poly2, polynomial *poly);
void normalisePoly(polynomial *poly1, polynomial *poly5);

void deletePoly(polynomial *poly1);
int returnOrder(polynomial *poly1);

#endif
