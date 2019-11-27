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
double addPoly(double coeff1, double coeff2);
double subtract(double coeff1, double coeff2);
double multiplyPoly();

typedef struct
{
  double coefficient; //the coefficient
  int exponent;       //the exponent
}polynomial

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