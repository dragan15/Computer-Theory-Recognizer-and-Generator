#include<iostream>
#include<string>
using namespace std;

//-------------------------------------------------------
// CS421 HW1 
// Write a recognizer in C++ for L = {x | x is a binary number}.
// Your name: Dragan Lukic
//-------------------------------------------------------

//  The recognizer function should return TRUE or FALSE 
//  checking each character
//  to make sure it is 0 or 1. (leading 0's are allowed).
bool recognizer(string s)
{
while(s.length() > 0) //while there is a string
 {
  for(int i = 0; i < s.length(); i++) //while the increment is less than the length of the variable
   {
    if(s[i] != '0' && s[i] !='1') //checks if the array is binary or not
     {
      return false;
     }
   }
   return true;
 }
}// end of recognizer

//main: Given a string (from E) cined from the user, pass it to
//      the recognizer function.
//      Cout YES IN L or NO NOT IN L depending on what was returned.
int main()
{
 string input;
cout << "Enter a number and this program will determin if it's binary or not:" << endl;
getline(cin, input);
if(recognizer(input) == true)
  {
   cout << input << " " <<  "It is in L" << endl;
  }
  else
  {
   cout << input << " " << "Not in L" << endl;
  }
 return 0;

    // feel free to put it in a loop 

}// end of main
