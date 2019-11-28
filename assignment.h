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

//Definition of a link list node
typedef struct n //n is a dummy variable so that we can use this new data type within the struct itself
{
  double coeff; //coefficient of a term
  int order; //order of x^n term
  struct n *succesor; //pointer to the next node in the link list
}polyNode;

//Definition of polynomial type
typedef struct
{
  polyNode *head; //pointer to the head of the link list
  polyNode *current; //pointer to the current node
}polynomial;

struct node 
{
  int num;                        //Data of the node
  struct node *nextptr;           //Address of the next node
}*stnode;

/*
//creation of link list node - MIGHT BE WRONG
typedef struct n{
  int value; //value of the coefficient 
  struct n *successor; //pointer to next value
}llnode; 

//creation of link list
typedef stuct {
  llnode *head; //points to link list head
  llnode *current; //points to current node
}llist;
*/

#endif
