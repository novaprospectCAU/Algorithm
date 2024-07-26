#include "to_int.hpp"

int bin_to_int(std::string input)
{
  int output = 0;
  for (char c : input)
  {
    output *= 2;
    if (c == '1')
    {
      output += 1;
    }
  }
  return output;
}