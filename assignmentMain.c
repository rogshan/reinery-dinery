//assignmentMain.c
//Main file for CE4703 assignment 3
//Contains user interface for user inputs
//Authors: Ciara Sookarry, Roger Shanahan, Aoife O`Doherty, Anna Shaughnessy
//Date: 2019/12/08

#include <stdlib.h>
#include <stdio.h>
#include "assignment.h"

typedef enum {PASS, FAIL} test;

test testAddNode();
test testAddNode();
test testDeletePoly();
test testPolyAdd();
test testPolySubtract();
test testMultiplyPoly();
test testDividePoly();
test testNormalisePoly();
test testReturnOrder();
test testPrintPolynomial();

//////////////////////////////
// main()
// tests the functions in assignemnt.c
//////////////////////////////
int main()
{
  testAddNode();
  testAddNode();
  testDeletePoly();
  testPolyAdd();
  testPolySubtract();
  testMultiplyPoly();
  testDividePoly();
  testNormalisePoly();
  testReturnOrder();
  testPrintPolynomial();
}


// Tests the createPoly function
  // Checks if the return value is null or not
  test testCreatePoly()
  {
    polynomial *polyTest = createPoly();        //creates a polynomial for the test
    //if not NULL returned
    if(polyTest != NULL)
    {
      printf("createPoly() passed test");
      return PASS;
    }
    else
    {
      printf("createPoly() failed test");
      return FAIL;
    }
  }
  
  // Tests the addNode() function
  // Checks if return value is a pointer to the new node or not
  test testAddNode()
  {
    stNode *testNode = malloc(sizeof(stNode *));        //creates a node for the test
    testNode->coeff = 1;                            //assigns a value to the coefficient of the node
    testNode->pow = 2;                              //assigns a value to the power of the node
    polynomial *polyTest = createPoly();            //creates a polynomial for the test
    addnode(testNode, polyTest);
    //if pointer returned
    if(polyTest->current->nextptr == testNode)
    {
      printf("addNode() passed test");
      return PASS;
    }
    else
    {
      printf("addNode() failed test");
      return FAIL;
    }
  }
  
   // Tests the deletePoly() function
  // Sees is return value is a pointer to a new node or not
  test testDeletePoly()
  {
    polynomial *polyTest = createPoly();        //creates a node for the test
    int order = 4;                           //sets the order
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = (7-i);        //assigns a value to the coefficient of the node
      testNode->pow = i;              //assigns a value to the power of the node
      addnode(testNode, polyTest);    //adds the node to the polynomial
    }
    //if pointer returned
    if(deletePoly(polyTest) == 0)
    {
      printf("polyAdd() passed test");
      return PASS;
    }
    else
    {
      printf("polyAdd() failed test");
      return FAIL;
    }
  }
  
  // Tests the polyAdd() function
  // Checks if a return value is a pointer to a polynomial or not
  test testPolyAdd()
  {
    polynomial *poly1 = createPoly();        //creates a polynomial for the test
    int order = 5;                           //sets the order
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = (7-i);        //assigns a value to the coefficient of the node
      testNode->pow = i;              //assigns a value to the power of the node
      addnode(testNode, poly1);    //adds the node to the polynomial
    }
    polynomial *poly2 = createPoly();        //creates a polynomial for the test
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = i;          //assigns a value to the coefficient of the node
      testNode->pow = i;              //assigns a value to the power of the node
      addnode(testNode, poly2);    //adds the node to the polynomial
    }
    polynomial *poly = createPoly();        //creates a polynomial for the test
    polyAdd(poly1, poly2, poly);
    poly1->current = poly1->head;
    poly2->current = poly2->head;
    poly->current = poly->head;
    for(int i = 0; i<=order; i++)
    {
      while(poly->current->nextptr != NULL)
      {
        if(poly->current->coeff != ((7-i) + i) || poly->current->pow != i)
        {
          deletePoly(poly1);
          deletePoly(poly2);
          deletePoly(poly);
          printf("polyAdd() failed test");
          return FAIL;
        }
        poly1->current = poly1->current->nextptr;
        poly2->current = poly2->current->nextptr;
        poly->current = poly->current->nextptr;
      }
    }
    printf("polyAdd() passed test");
    return PASS;
  }
  
   // Tests the polySubtract() function
  // Checks if return value is a pointer to a new polynomial or not
  test testPolySubtract()
  {
    polynomial *poly1 = createPoly();        //creates a polynomial for the test
    int order = 5;
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = (9-i);          //assigns a value to the coefficient of the node
      testNode->pow = i;              //assigns a value to the power of the node
      addnode(testNode, poly1);    //adds the node to the polynomial
    }
    polynomial *poly2 = createPoly();        //creates a polynomial for the test
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = i+3;          //assigns a value to the coefficient of the node
      testNode->pow = i+1;              //assigns a value to the power of the node
      addnode(testNode, poly2);    //adds the node to the polynomial
    }
    polynomial *poly = createPoly();        //creates a polynomial for the test
    polySubtract(poly1, poly2, poly);
    poly1->current = poly1->head;
    poly2->current = poly2->head;
    poly->current = poly->head;
    for(int i = 0; i<=order; i++)
    {
      while(poly->current->nextptr != NULL)
      {
        if(poly->current->coeff != ((9-i) - (i+3)) || poly->current->pow != i)
        {
          deletePoly(poly1);
          deletePoly(poly2);
          deletePoly(poly);
          printf("polySubtract() failed test");
          return FAIL;
        }
        poly1->current = poly1->current->nextptr;
        poly2->current = poly2->current->nextptr;
        poly->current = poly->current->nextptr;
      }
    }
    printf("polySubtract() passed test");
    return PASS;
  }
  
   // Tests the multiplyPoly() function
  // Checks if return value is a pointer to a new node or not
  test testMultiplyPoly()
  {
    polynomial *poly1 = createPoly();        //creates a polynomial for the test
    int order = 4;
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = (5-i);          //assigns a value to the coefficient of the node
      testNode->pow = i-2;              //assigns a value to the power of the node
      addnode(testNode, poly1);    //adds the node to the polynomial
    }
    polynomial *poly2 = createPoly();        //creates a polynomial for the test
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = i-2;          //assigns a value to the coefficient of the node
      testNode->pow = i;              //assigns a value to the power of the node
      addnode(testNode, poly2);    //adds the node to the polynomial
    }
    polynomial *poly = createPoly();        //creates a polynomial for the test
    multiplyPoly(poly1, poly2, poly);
    poly1->current = poly1->head;
    poly2->current = poly2->head;
    poly->current = poly->head;
    for(int i = 0; i<=order; i++)
    {
      while(poly->current->nextptr != NULL)
      {
        if(poly->current->coeff != ((5-i) * (i-2)) || poly->current->pow != i)
        {
          deletePoly(poly1);
          deletePoly(poly2);
          deletePoly(poly);
          printf("multiplyPoly()) failed test");
          return FAIL;
        }
        poly1->current = poly1->current->nextptr;
        poly2->current = poly2->current->nextptr;
        poly->current = poly->current->nextptr;
      }
    }
    printf("multiplyPoly() passed test");
    return PASS;
  }
  
   // Tests the dividePoly() function
  // Checks if return value is a pointer to a new node or not
  test testDividePoly()
  {
    polynomial *poly1 = createPoly();        //creates a polynomial for the test
    int order = 6;
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = (7-i);          //assigns a value to the coefficient of the node
      testNode->pow = i;              //assigns a value to the power of the node
      addnode(testNode, poly1);    //adds the node to the polynomial
    }
    polynomial *poly2 = createPoly();        //creates a polynomial for the test
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = (3*i);          //assigns a value to the coefficient of the node
      testNode->pow = i;              //assigns a value to the power of the node
      addnode(testNode, poly2);    //adds the node to the polynomial
    }
    polynomial *poly = createPoly();        //creates a polynomial for the test
    dividePoly(poly1, poly2, poly);
    poly1->current = poly1->head;
    poly2->current = poly2->head;
    poly->current = poly->head;
    for(int i = 0; i<=order; i++)
    {
      while(poly->current->nextptr != NULL)
      {
        if(poly->current->coeff != ((7-i) / (3*i)) || poly->current->pow != i)
        {
          deletePoly(poly1);
          deletePoly(poly2);
          deletePoly(poly);
          printf("dividePoly() failed test");
          return FAIL;
        }
        poly1->current = poly1->current->nextptr;
        poly2->current = poly2->current->nextptr;
        poly->current = poly->current->nextptr;
      }
    }
    printf("dividePoly() passed test");
    return PASS;
  }
  
   // Tests the normalisePoly() function
  // Sees is return value is a pointer to a new node or not
  test testNormalisePoly()
  {
    polynomial *poly1 = createPoly();        //creates a polynomial for the test
    int order = 3;
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = (5+i);          //assigns a value to the coefficient of the node
      testNode->pow = i;              //assigns a value to the power of the node
      addnode(testNode, poly1);    //adds the node to the polynomial
    }
    polynomial *polyN = createPoly();        //creates a polynomial for the test
    normalisePoly(poly1, polyN);
    poly1->current = poly1->current->nextptr;
    polyN->current = polyN->current->nextptr;
    for(int i = 0; i<=order; i++)
    {
      while(polyN->current->nextptr != NULL)
      {
        if(polyN->current->coeff != (5+i)/6 || polyN->current->pow != i)
        {
          deletePoly(poly1);
          deletePoly(polyN);
          printf("normalisePoly() failed test");
          return FAIL;
        }
        poly1->current = poly1->current->nextptr;
        polyN->current = polyN->current->nextptr;
      }
    }
    printf("normalisePoly() passed test");
    return PASS;
  }
  
   // Tests the returnOrder() function
  // Sees is return value is greater than zero
  test testReturnOrder()
  {
    polynomial *polyTest = createPoly();        //creates a polynomial for the test
    int order = 6;
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = (4*i);          //assigns a value to the coefficient of the node
      testNode->pow = i;              //assigns a value to the power of the node
      addnode(testNode, polyTest);    //adds the node to the polynomial
    }
    int polyOrder = returnOrder(polyTest);
    //if pointer returned
    if(polyOrder == (4*(order-1)))
    {
      printf("returnOrder() passed test");
      return PASS;
    }
    else
    {
      printf("returnOrder() failed test");
      return FAIL;
    }
  }
  
  test testPrintPolynomial()
  {
    int order = 5;
    polynomial *polyTest = createPoly();        //creates a polynomial for the test
    for (int i = 0; i<=order; i++)
    {
      stNode *testNode = malloc(sizeof(stNode *));
      testNode->coeff = (2+i);          //assigns a value to the coefficient of the node
      testNode->pow = i;              //assigns a value to the power of the node
      addnode(testNode, polyTest);    //adds the node to the polynomial
    }
    if(printPolynomial(polyTest) == 0)
    {
      deletePoly(polyTest);
      printf("printPolynomial() passed test");
      return PASS;
    }
    else
    {
      deletePoly(polyTest);
      return FAIL;
    }
  }