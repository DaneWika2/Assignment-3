/********************************************************************
*** NAME : Dane Wika ***
*** CLASS : CSC 300 ***
*** ASSIGNMENT : 3 ***
*** DUE DATE : 10/5/22***
*** INSTRUCTOR : GAMRADT ***
*********************************************************************
*** DESCRIPTION : Stack Program ***
*** Using the following commands Constructor, Deconstructor, Copy, Pop, Push, Peek, View ***
********************************************************************/
// None
// Constructor, Deconstructor, Copy, Pop, Push, Peek, View; using Strings; Const string in push
// Main is Main.cpp; Tests all the functions listed above in various ways

// ***** PROGRAM STARTS *****

#include "stack.h"
#include <iomanip>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

/********************************************************************
*** FUNCTION Stack constructor ***
*********************************************************************
*** DESCRIPTION : Initilizes the values in a Stack object ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : Null values for top, next and SNodePtr ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
Stack::Stack()
{
   top = nullptr;
   SNode *next = nullptr;
   SNode *SNodePtr = nullptr;
}

/********************************************************************
*** FUNCTION Stack Copy Constructor ***
*********************************************************************
*** DESCRIPTION : Copys the values from one stack to another ***
*** INPUT ARGS : oldStack ***
*** OUTPUT ARGS :  None ***
*** IN/OUT ARGS : Push(tempstring) ***
*** RETURN : None ***
********************************************************************/
Stack::Stack(Stack &oldStack)
{
   SNode *SNodePtr; 
   SNodePtr = oldStack.top;
   string tempstring;


   if (oldStack.top == nullptr)
   {
      cout << "List is empty";
      cout << endl;
   }
   else
   {
   int i = 0;
   int L = 0;

    while(oldStack.top != nullptr)
    {
     i++;
     oldStack.top = oldStack.top->next;
    }
    oldStack.top = SNodePtr;
   
   for(i; i>0; i--)
      {
         L = i;
         for(L; L>1; L--)
         {
            oldStack.top = oldStack.top->next;
         }
         oldStack.pop(tempstring);
         oldStack.push(tempstring);
         push(tempstring);
         oldStack.top = SNodePtr; 
      }
   }
}


/********************************************************************
*** FUNCTION Stack Deconstructor ***
*********************************************************************
*** DESCRIPTION : Deletes all objects on call or at end of the program ***
*** INPUT ARGS : All created objects ***
*** OUTPUT ARGS : None***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
Stack::~Stack()
{
   SNode *SNodePtr;  
   SNodePtr = top;

   while (top != nullptr)
   {
      SNodePtr = SNodePtr->next;
      delete top;
      top = SNodePtr;
   }
}


/********************************************************************
*** FUNCTION Push ***
*********************************************************************
*** DESCRIPTION : Puts a value on top of the stack ***
*** INPUT ARGS : stringIn ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void Stack::push(const SElement stringIn)
{
   SNodePtr newNode = new SNode();
   if(newNode == NULL)
   {
      cout << "newNode could not be created";
      cout << endl;
   }
   else
   {
   newNode->element = stringIn;
   newNode->next = top;
   top = newNode;
   }
}


/********************************************************************
*** FUNCTION Pop ***
*********************************************************************
*** DESCRIPTION : Pops a value off of the stack for use ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : String ***
*** IN/OUT ARGS : None***
*** RETURN : None ***
********************************************************************/
void Stack::pop(SElement &string)
{   
   // If the list is empty, do nothing.
   if (top == nullptr)
   {
      cout << "List is empty";
      cout << endl;
   }
   else
   {
      string = top->element;
      delete top;
      top = top->next;
   }
}


/********************************************************************
*** FUNCTION Peek ***
*********************************************************************
*** DESCRIPTION : outputs the top value in the stack without removing it ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : String***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void Stack::peek(SElement &string)
{
   SNode *SNodePtr;  
   if (top == nullptr)
   {
      cout << "List is empty";
      cout << endl;
   }
   else
   {
      pop(string);
      push(string);
   }
}

/********************************************************************
*** FUNCTION View ***
*********************************************************************
*** DESCRIPTION : Displayes each element in the stack without removing any ***
*** INPUT ARGS : None ***
*** OUTPUT ARGS : None ***
*** IN/OUT ARGS : None ***
*** RETURN : None ***
********************************************************************/
void Stack::view()
{
   string tempstring;
   SNode *SNodePtr;
   SNodePtr = top;
   
   if(top == nullptr)
   {
       cout << "List is empty";
      cout << endl;
   }
   else
   {
      cout << "TOP ->";
      while(top != nullptr)
      {
         pop(tempstring);
         push(tempstring);
         cout << tempstring;
         cout << " -> ";
         top =  top->next;
      }
      top = SNodePtr;
      cout << "BACK" << endl;
   }
}