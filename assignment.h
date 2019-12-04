//assignment.h
//
//Header file containing function declarations and polynomial type definition
//
//Author: Ciara Sookarry, Roger Shanahan
//Date: 04/12/19
#ifndef ASSIGNMENT_H
#define ASSIGNMENT_H

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

// Link list error messages
//typedef enum {ok, illegalNode, noMemory}llError;

//declarations of functions to create and edit link list itself
//void createNodeList(int max_coefficients);
//void displayList(int highest_exponent);
polynomial *createPoly();
stNode addnode(stNode *node, polynomial *poly1);
void deletePoly(polynomial *poly1);
void printPolynomial(polynomial *poly);

//declarations of functions to manipulate polynomial
polynomial polyAdd(polynomial *poly1, polynomial *poly2, polynomial *poly);
polynomial polySubtract(polynomial *poly1, polynomial *poly2, polynomial *poly);
polynomial multiplyPoly(polynomial *poly1, polynomial *poly2, polynomial *poly);
polynomial dividePoly(polynomial *poly1, polynomial *poly2, polynomial *poly);
polynomial normalisePoly(polynomial *poly1, polynomial *poly5);
int returnOrder(polynomial *poly1);


#endif
