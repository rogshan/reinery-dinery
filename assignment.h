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

//declarations of functions to manipulate polynomial
double polyadd(struct Node *poly1, struct Node *poly2, struct Node *poly);
double polysubtract(struct Node *poly1, struct Node *poly2, struct Node *poly);
double multiplyPoly(struct Node *poly1, struct Node *poly2, struct Node *poly);
double dividePoly(struct Node *poly1, struct Node *poly2, struct Node *poly);
int returnOrder(polynomial poly1);

//Definition of a link list node
typedef struct n //n is a dummy variable so that we can use this new data type within the struct itself
{
  double coeff; //coefficient of a term
  int pow; //power of x^n term
  struct n *successor; //pointer to the next node in the link list
}stnode;

//Definition of polynomial type
typedef struct
{
  polyNode *head; //pointer to the head of the link list
  polyNode *current; //pointer to the current node
}polynomial;

#endif
