//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
//Authors: Ciara Sookarry, Roger Shanahan, Aoife O`Doherty, Anna Shaughnessy
//Date: 08/12/19

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
  int testCreatePoly()
  {
    polynomial *polyTest = createPoly();
    //if not NULL returned
    if(polyTest != NULL)
    {
      printf("createPoly() passed test");
      return 0;
    }
    else
    {
      printf("createPoly() failed test");
    }
  }
  
   // Tests the addNode() function
  // Sees is return value is a pointer to a new node or not
  int testAddNode()
  {
    stNode *testNode;
    testNode->coeff = 1;
    testNode->pow = 2;
    polynomial *polyTest = createPoly();
    addnode(testNode, polyTest);
    //if pointer returned
    if(polyTest->current->nextptr == testNode)
    {
      printf("addNode() passed test");
      return 0;
    }
    else
    {
      printf("addNode() failed test");
    }
  }
  
   // Tests the deletePoly() function
  // Sees is return value is a pointer to a new node or not
  int testDeletePoly()
  {
    polynomial *polyTest = createPoly();
    polyTest->current->nextptr->coeff = 1;
    polyTest->current->nextptr->pow = 0;
    //if pointer returned
    if(deletePoly(polyTest) == 0)
    {
      printf("polyAdd() passed test");
      return 0;
    }
    else
    {
      printf("polyAdd() failed test");
    }
  }
  
   // Tests the polyAdd() function
  // Sees is return value is a pointer to a polynomial or not
  int testPolyAdd()
  {
    polynomial *poly1 = createPoly();
    int order = 5;
    for (int i = 0; i<order; i++)
    {
      stNode *testNode;
      testNode->coeff = (7-i);
      testNode->pow = i;
      addnode(testNode, poly1);
    }
    polynomial *poly2 = createPoly();
    for (int i = 0; i<order; i++)
    {
      stNode *testNode;
      testNode->coeff = i;
      testNode->pow = i+2;
      addnode(testNode, poly2);
    }
    polynomial *poly = createPoly();
    polyAdd(poly1, poly2, poly);
    poly1->current = poly1->head;
    poly2->current = poly2->head;
    poly->current = poly->head;
    for(int i = 0; i<order; i++)
    {
      while(poly->current->nextptr != NULL)
      {
        if(poly->current->coeff != ((7-i) + i) || poly->current->pow != i)
        {
          deletePoly(poly1);
          deletePoly(poly2);
          deletePoly(poly);
          printf("polyAdd() failed test");
          return 1;
        }
        poly1->current = poly1->current->nextptr;
        poly2->current = poly2->current->nextptr;
        poly->current = poly->current->nextptr;
      }
    }
    printf("polyAdd() passed test");
    return 0;
  }
  
   // Tests the polySubtract() function
  // Checks if return value is a pointer to a new polynomial or not
  int testPolySubtract()
  {
    polynomial *poly1 = createPoly();
    int order = 7;
    for (int i = 0; i<order; i++)
    {
      stNode *testNode;
      testNode->coeff = (9-i);
      testNode->pow = i;
      addnode(testNode, poly1);
    }
    polynomial *poly2 = createPoly();
    for (int i = 0; i<order; i++)
    {
      stNode *testNode;
      testNode->coeff = i+3;
      testNode->pow = i+1;
      addnode(testNode, poly2);
    }
    polynomial *poly = createPoly();
    polySubtract(poly1, poly2, poly);
    poly1->current = poly1->head;
    poly2->current = poly2->head;
    poly->current = poly->head;
    for(int i = 0; i<order; i++)
    {
      while(poly->current->nextptr != NULL)
      {
        if(poly->current->coeff != ((9-i) - (i+3)) || poly->current->pow != i)
        {
          deletePoly(poly1);
          deletePoly(poly2);
          deletePoly(poly);
          printf("polySubtract() failed test");
          return 1;
        }
        poly1->current = poly1->current->nextptr;
        poly2->current = poly2->current->nextptr;
        poly->current = poly->current->nextptr;
      }
    }
    printf("polySubtract() passed test");
    return 0;
  }
  
   // Tests the multiplyPoly() function
  // Checks if return value is a pointer to a new node or not
  int testMultiplyPoly()
  {
    polynomial *poly1 = createPoly();
    int order = 4;
    for (int i = 0; i<order; i++)
    {
      stNode *testNode;
      testNode->coeff = (5-i);
      testNode->pow = i-2;
      addnode(testNode, poly1);
    }
    polynomial *poly2 = createPoly();
    for (int i = 0; i<order; i++)
    {
      stNode *testNode;
      testNode->coeff = i-2;
      testNode->pow = i;
      addnode(testNode, poly2);
    }
    polynomial *poly = createPoly();
    multiplyPoly(poly1, poly2, poly);
    poly1->current = poly1->head;
    poly2->current = poly2->head;
    poly->current = poly->head;
    for(int i = 0; i<order; i++)
    {
      while(poly->current->nextptr != NULL)
      {
        if(poly->current->coeff != ((5-i) * (i-2)) || poly->current->pow != i)
        {
          deletePoly(poly1);
          deletePoly(poly2);
          deletePoly(poly);
          printf("multiplyPoly()) failed test");
          return 1;
        }
        poly1->current = poly1->current->nextptr;
        poly2->current = poly2->current->nextptr;
        poly->current = poly->current->nextptr;
      }
    }
    printf("multiplyPoly() passed test");
    return 0;
  }
  
   // Tests the dividePoly() function
  // Checks if return value is a pointer to a new node or not
  int testDividePoly()
  {
    polynomial *poly1 = createPoly();
    int order = 8;
    for (int i = 0; i<order; i++)
    {
      stNode *testNode;
      testNode->coeff = (7-i);
      testNode->pow = i;
      addnode(testNode, poly1);
    }
    polynomial *poly2 = createPoly();
    for (int i = 0; i<order; i++)
    {
      stNode *testNode;
      testNode->coeff = (3*i);
      testNode->pow = i;
      addnode(testNode, poly2);
    }
    polynomial *poly = createPoly();
    dividePoly(poly1, poly2, poly);
    poly1->current = poly1->head;
    poly2->current = poly2->head;
    poly->current = poly->head;
    for(int i = 0; i<order; i++)
    {
      while(poly->current->nextptr != NULL)
      {
        if(poly->current->coeff != ((7-i) / (3*i)) || poly->current->pow != i)
        {
          deletePoly(poly1);
          deletePoly(poly2);
          deletePoly(poly);
          printf("dividePoly() failed test");
          return 1;
        }
        poly1->current = poly1->current->nextptr;
        poly2->current = poly2->current->nextptr;
        poly->current = poly->current->nextptr;
      }
    }
    printf("dividePoly() passed test");
    return 0;
  }
  
   // Tests the normalisePoly() function
  // Sees is return value is a pointer to a new node or not
  int testNormalisedPoly()
  {
    polynomial *poly1 = createPoly();
    int order = 6;
    for (int i = 0; i<order; i++)
    {
      stNode *testNode;
      testNode->coeff = (5+i);
      testNode->pow = i;
      addnode(testNode, poly1);
    }
    polynomial *polyN = createPoly();
    normalisePoly(poly1, polyN);
    poly1->current = poly1->current->nextptr;
    polyN->current = polyN->current->nextptr;
    for(int i = 0; i<order; i++)
    {
      while(polyN->current->nextptr != NULL)
      {
        if(polyN->current->coeff != (5+i)/6 || polyN->current->pow != i)
        {
          deletePoly(poly1);
          deletePoly(polyN);
          printf("normalisePoly() failed test");
          return 1;
        }
        poly1->current = poly1->current->nextptr;
        polyN->current = polyN->current->nextptr;
      }
    }
    printf("normalisePoly() passed test");
    return 0;
  }
  
   // Tests the returnOrder() function
  // Sees is return value is greater than zero
  int testReturnOrder()
  {
    polynomial *polyTest = createPoly();
    int order = 6;
    for (int i = 0; i<order; i++)
    {
      stNode *testNode;
      testNode->coeff = (4*i);
      testNode->pow = i;
      addnode(testNode, polyTest);
    }
    int polyOrder = returnOrder(polyTest);
    //if pointer returned
    if(polyOrder == (4*(order-1)))
    {
      printf("returnOrder() passed test");
    }
    else
    {
      printf("returnOrder() failed test");
    }
  }
  
  int testPrintPolynomial()
  {
    int order = 5;
    polynomial *polyTest = createPoly();
    for (int i = 0; i<order; i++)
    {
      stNode *testNode;
      testNode->coeff = (2+i);
      testNode->pow = i;
      addnode(testNode, polyTest);
    }
    if(printPolynomial(polyTest) == 0)
    {
      deletePoly(polyTest);
      printf("printPolynomial() passed test");
      return 0;
    }
    else
    {
      deletePoly(polyTest);
      return 1;
    }
  }
}


  


   
