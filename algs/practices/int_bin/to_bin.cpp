#include "to_bin.hpp"

std::string int_to_bin(int input)
{
  std::string output = "0b";
  if (input == 0)
  {
    return (output + "0");
  }
  while (input)
  {
    if (input % 2)
    {
      output += "1";
    }
    else
    {
      output += "0";
    }
    input /= 2;
  }
  return output;
}