// Single Linked List : 단일 연결 리스트
// 단, 이 경우 헤드를 시작으로 바로 함수를 사용하므로 위험하다. (헤드까지 pop_back()이 가능하므로)
// 이를 막기 위해서는 헤드가 아닌 연결리스트의 인덱스를 가리키는 이중 포인터를 사용하거나,
// 함수 단에서, 혹은 노드 단에서 헤드 도달 여부를 확인하고 이를 핸들링할 수 있게 설계해야 한다.

#include <iostream>
#include <string>

#include "node.hpp"

int main()
{
  Node *head = Node::list("World!\n");
  head->push_back("Hello");
  head->insert(1, " ");
  std::cout << head->erase(2);
  std::cout << head->pop_back();
  std::cout << head->pop_back();
  return 0;
}