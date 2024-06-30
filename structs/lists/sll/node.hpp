#include <string>
#include <iostream>

struct Node
{
  std::string name;
  struct Node *next;

  static Node *list(std::string str);
  void push_back(std::string str);
  std::string pop_back();
  void insert(int node, std::string str);
  std::string erase(int node);
};
