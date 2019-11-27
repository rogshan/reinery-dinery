//assignment.h
//
//Header file containing function declarations and polynomial type definition
//
//Author: Ciara Sookarry
//Date: 22/11/19

//declarations of functions to create link list
void createNodeList(int max_coefficients);
void displayList(int highest_exponent);

//declarations of functions to manipulate polynomial
double addPoly(double coeff1, double coeff2);
double subtract(double coeff1, double coeff2);
double multiplyPoly();

/*
typedef struct{
  //I have no idea how we'll do this since the number of terms is variable
}polynomial;

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
