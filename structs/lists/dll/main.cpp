// double linked list : 이중 연결 리스트
// 기존 단일 연결리스트로는 앞부분을 추가, 삭제하는 로직에 어려움이 있어,
// 이중 포인터를 사용하여 구성합니다.

#include <iostream>
#include <string>

#include "list.hpp"

int main()
{
  List *list = List::list("Hello World!");

  list->push_back("a ");
  list->push_back("b ");
  list->push_back("d ");
  list->push_back("e ");
  list->insert(3, "c ");

  std::cout << list->pop_front();
  std::cout << list->erase(1);
  std::cout << list->pop_front();
  std::cout << list->pop_front();
  std::cout << list->pop_front();
  std::cout << list->pop_front();
  std::cout << list->pop_front();

  std::cout << list->size() << '\n';

  return 0;
}