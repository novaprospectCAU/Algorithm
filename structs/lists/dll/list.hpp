#include "node.hpp"

class List
{
public:
  static List *list(std::string str);
  List(std::string str);
  ~List();
  void push_back(std::string str);
  std::string pop_back();
  void push_front(std::string str);
  std::string pop_front();
  void insert(int node, std::string str);
  std ::string erase(int node);
  int size();
  void clear();
  void destroy();

  Node *head;

private:
};