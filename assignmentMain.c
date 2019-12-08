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
  
  return 0;
}


  


   
