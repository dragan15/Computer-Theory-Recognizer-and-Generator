#include <iostream>
#include <string>
#include <cstdlib>
#include <iostream>
#include "queue.h"
using namespace std;


 // include queue.h or equivalent such as <queue>

//----------------------------------------------
// CS421 HW1 
// Write a generator in C++ for L = {x | x is a binary number}.
// Your name: **
//----------------------------------------------

// Copy the recognizer function here from the other file.
bool recognizer(string s)
{
while(s.length() >0)
{
  for(int i = 0; i < s.length(); i++)
   {
    if(s[i] != '0' && s[i] !='1') //checks if the array is binary or not
     {
      return false;
     }
   }
   return true;
 }
}// end of recognizer


// main: It should create each string over E = {0,1,2} systematically
//   (short to long) and pass each string to the recognizer function
//   created in Part a).  Hint: use a queue to generate strings
//   Only those strings for which the recognizer returned TRUE
//   should be displayed. 
//   Keeps on going until the queue overflows but the user can
//   terminate the program with control-C 
//   after about 20 strings have been displayed.
int main()
{
  int count = 0;
  queue Q1;
  Q1.add("0");
  Q1.add("1");
  Q1.add("2");
  string input;
  string token;
  while(true)
    {
        try{
        Q1.remove(token);

          if(recognizer(token) == true)
            {
              cout << token << endl;
              count++;
            }

          if(count == 20)
            {
              count++;
              cout << "over 20 items have been checked enter exit to stop program\n";
              cin >> input;
              if(input == "exit" || input == "EXIT")
                {
                  cout << "Program Terminating...\n"; exit(1);
                }
            }

          Q1.add(token + "0");
          Q1.add(token + "1");
          Q1.add(token + "2");
        }

      catch(queue::Overflow)
        {cerr << "Error: Overflow\n"; exit(1);}
      catch(queue::Underflow)
        {cerr << "Error: Underflow\n"; exit(1);}
    }// end of while
  return 0;
}// end of main
