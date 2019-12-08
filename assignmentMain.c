//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
//Authors: Ciara Sookarry, Roger Shanahan, Aoife O`Doherty, Anna Shaughnessy
//Date: 04/12/19 (Update as necessary)

#include <stdlib.h>
#include <stdio.h>
#include "assignment.h"

//////////////////////////////
// main()
// tests the functions in assignemnt.c
//////////////////////////////
int main()
{
  // Tests the createPoly function
  // Sees is return value is null or not
  createPoly();
  //if NULL returned
  if(){
    printf("createPoly() failed test");
  }else{
    printf("createPoly() passed test");
  }
  
   // Tests the addNode() function
  // Sees is return value is a pointer to a new node or not
  addNode(newNode, poly);
  //if pointer returned
  if(){
    printf("addNode() passed test");
  }else{
    printf("addNode() failed test");
  }
  
  ///I HAVE NO IDEA HOW TO TEST DELETENODE()
  
   // Tests the polyAdd() function
  // Sees is return value is a pointer to a polynomial or not
  polyAdd(poly1, poly2, poly);
  //if pointer returned
  if(*poly){
    printf("polyAdd() passed test");
  }else{
    printf("polyAdd() failed test");
  }
  
   // Tests the polySubtract() function
  // Sees is return value is a pointer to a new polynomial or not
  addNode(poly1, poly2, poly);
  //if pointer returned
  if(*poly){
    printf("polySubtract() passed test");
  }else{
    printf("polySubtract() failed test");
  }
  
   // Tests the multiplyPoly() function
  // Sees is return value is a pointer to a new node or not
  multiplyPoly(poly1, poly2, poly);
  //if pointer returned
  if(*poly){
    printf("multiplyPoly() passed test");
  }else{
    printf("multiplyPoly() failed test");
  }
  
   // Tests the dividePoly() function
  // Sees is return value is a pointer to a new node or not
  multiplyPoly(poly1, poly2, poly);
  //if pointer returned
  if(*poly){
    printf("dividePoly() passed test");
  }else{
    printf("dividePoly() failed test");
  }
  
   // Tests the normalisePoly() function
  // Sees is return value is a pointer to a new node or not
  normalisePoly(poly1, poly5);
  //if pointer returned
  if(*poly5){
    printf("normalisePoly() passed test");
  }else{
    printf("normalisePoly() failed test");
  }
  
   // Tests the returnOrder() function
  // Sees is return value is greater than zero
  returnOrder(poly1);
  //if pointer returned
  if(poly1->current->pow >= 0){
    printf("returnOrder() passed test");
  }else{
    printf("returnOrder() failed test");
  }
  
  // NO IDEA HOW TO TEST PRINTPOLYNOMIAL EITHER
}


  


   
