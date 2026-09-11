#include <string>
#include <vector>
#include <iostream>
#include <sstream>

#include "ulliststr.h"

using namespace std;

//Use this file to test your ulliststr implementation before running the test suite

int main(int argc, char* argv[])
{
  ULListStr list;

  list.push_back("2");
  list.push_back("4");
  list.push_front("6");
  list.push_back("8");

  cout << list.get(0) << endl;
  cout << list.get(1) << endl;
  cout << list.get(2) << endl;
  cout << list.get(3) << endl;

  cout << "Front item: " << list.front() << endl;
  cout << "Back item: " << list.back() << endl;
  cout << "Size: " << list.size() << endl;

  list.pop_front();
  cout << "After pop_front function: " << list.get(0) << endl;

  list.pop_back();
  cout << "After pop_back function: " << list.get(0) << endl;

  return 0;
}
