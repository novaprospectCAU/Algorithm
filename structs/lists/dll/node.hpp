#include <string>
#include <iostream>

struct Node
{
  std::string name;
  struct Node *next;
  struct Node *prev;
};
