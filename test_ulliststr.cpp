#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr dat;
  dat.push_front("7");
  dat.push_back("6");
  dat.push_back("8");
  dat.push_front("9");
  //dat.push_front("8");
  //dat.push_back("9");

  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << dat.get(3) << endl;
  // prints: 8 7 9
  cout << dat.size() << endl;  // prints 3 since there are 3 strings stored

  dat.pop_front();
  //dat.pop_front();
  cout << dat.get(0) << " " << dat.get(1) << " " << dat.get(2) << endl;
  cout << dat.size() << endl;

}
