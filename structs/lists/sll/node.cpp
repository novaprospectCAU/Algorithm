#include "node.hpp"

/**
 * @brief 새로운 연결리스트를 만듭니다.
 *
 * @param str
 * @return Node**
 */
Node *Node::list(std::string str)
{
  Node *linked_list = new Node;
  linked_list->name = str;
  linked_list->next = nullptr;
  return linked_list;
}

/**
 * @brief 연결리스트 마지막에 새로운 노드를 추가합니다.
 *
 * @param list
 */
void Node::push_back(std::string str)
{
  Node *new_node = new Node;
  new_node->name = str;
  new_node->next = nullptr;

  Node *ptr = this;
  while (ptr->next)
  {
    ptr = ptr->next;
  }
  ptr->next = new_node;
}

/**
 * @brief 연결리스트 마지막 노드를 삭제, name을 반환합니다.
 *
 * @return std::string
 */
std::string Node::pop_back()
{
  Node *p = this;
  std::string result;
  if (!(p->next))
  {
    result = p->name;
    delete p;
    // std::cout << "warning : head is not exist anymore!" << '\n';
    return result;
  }
  Node *p_prev;
  while (p->next)
  {
    p_prev = p;
    p = p->next;
  }
  result = p->name;
  delete p;
  p_prev->next = nullptr;
  return result;
}

/**
 * @brief 중간에 원하는 노드를 삽입합니다.
 *
 * @param node (0과 양수만 취급)
 * @param str
 */
void Node::insert(int node, std::string str)
{
  // 단, 0번에 삽입하는 행동은 할 수 없도록 하였습니다. (헤드 교체)
  if (node > 0)
  {
    Node *ptr = this;
    Node *p_prev;
    while (ptr)
    {
      if (!(node--))
      {
        Node *new_node = new Node;
        new_node->name = str;
        new_node->next = ptr;
        p_prev->next = new_node;
        return;
      }
      p_prev = ptr;
      ptr = ptr->next;
    }
    std::cout << "input number is bigger than the size of list." << '\n';
    return;
  }
  std::cout << "input number must bigger than 0." << '\n';
}

/**
 * @brief 중간에 있는 노드를 삭제합니다.
 *
 * @param node
 */
std::string Node::erase(int node)
{
  // 단, 0번은 헤드를 지우게 되므로 매우 위험하다고 판단하여 0은 넣을 수 없습니다.
  if (node > 0)
  {
    Node *ptr = this;
    Node *p_prev;
    while (ptr)
    {
      if (!(node--))
      {
        p_prev->next = ptr->next;
        std::string str = ptr->name;
        delete ptr;
        return str;
      }
      p_prev = ptr;
      ptr = ptr->next;
    }
    std::cout << "input number is bigger than the size of list." << '\n';
    return "";
  }
  std::cout << "input number must bigger than 0." << '\n';
  return "";
}