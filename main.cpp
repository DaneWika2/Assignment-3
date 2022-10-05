// Dane Wika
// 9/20/2022
// CSC300, 10:00
//Int List main program

#include <iomanip>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include "Stack.h"
#include <string>
#include <stack>

using namespace std;

int main()
{
//makes list an object
Stack Stack1;


string str1 = "insert";
string pop;
string peek;
string strpeek;
 

//function calls

Stack1.push("one");
Stack1.push("two"); 
Stack1.push("three"); 
Stack1.view();

Stack1.pop(pop);
Stack1.view();

Stack1.pop(pop);
Stack1.push(str1); 
Stack1.view();

Stack1.push("four"); 
Stack1.push(pop); 
Stack1.view();

Stack1.~Stack();

Stack1.pop(str1);
Stack1.push(str1);
Stack1.push("five"); 
Stack1.peek(str1);
Stack1.push(str1);
Stack1.view();

//cout << str1 << endl;

Stack1.push("six");
Stack1.push("seven"); 
Stack1.push("eight"); 
Stack1.view();

Stack Stack2(Stack1);

Stack2.pop(str1);

cout << "Final:" << endl;
Stack1.view();
Stack2.view();

    return 0;
}
