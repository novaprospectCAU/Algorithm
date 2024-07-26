#include <iostream>
#include <string>

#include "to_bin.hpp"
#include "to_int.hpp"

int main()
{
  int input1 = 255;
  std::string input2 = "11111111";
  std::cout << int_to_bin(input1) << " " << bin_to_int(input2) << '\n';
  return 0;
}