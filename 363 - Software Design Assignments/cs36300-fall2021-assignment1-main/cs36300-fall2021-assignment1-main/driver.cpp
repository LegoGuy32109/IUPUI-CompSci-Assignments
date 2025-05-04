#include "Array.h"
#include <iostream>
#include <cassert> // for assert

int main (int argc, char * argv [])
{
  Array a = Array();
  a.resize(11);
  a[10] = 'f';
  std::cout << a[10] << "\n";

  std::cout << "this program works\n";
  return 0;
}
