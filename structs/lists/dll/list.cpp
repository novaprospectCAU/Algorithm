#include "list.hpp"

/**
 * @brief 새로운 연결리스트를 만들며, 새로운 해드를 가리키는 이중 포인터를 반환합니다.
 *
 * @param str
 * @return List*
 */
List *List::list(std::string str)
{
  List *new_list = new List(str);
  return new_list;
};

List::List(std::string str)
{
  this->head = new Node;
  (this->head)->next = nullptr;
  (this->head)->prev = nullptr;
  (this->head)->name = str;
};

List::~List()
{
  destroy();
};

/**
 * @brief 연결 리스트 마지막에 새로운 노드를 추가합니다.
 *
 * @param str
 */
void List::push_back(std::string str)
{
  Node *ptr = this->head;
  Node *new_node = new Node;
  new_node->next = nullptr;
  new_node->name = str;
  if (!ptr)
  {
    List *list = this;
    list->head = new_node;
    new_node->prev = nullptr;
    return;
  }
  while (ptr->next)
  {
    ptr = ptr->next;
  }
  ptr->next = new_node;
  new_node->prev = ptr;
};

/**
 * @brief 연결 리스트의 마지막 노드를 제거합니다.
 *
 * @return std::string
 */
std::string List::pop_back()
{
  Node *ptr = this->head;
  if (!ptr) // 헤드 노드가 없는 경우 (연결 리스트가 비어있는 경우입니다.)
  {
    return "";
  }
  Node *ptr_prev = ptr->prev;
  while (ptr->next)
  {
    ptr_prev = ptr;
    ptr = ptr->next;
  }
  if (ptr_prev)
  {
    ptr_prev->next = nullptr;
  }
  std::string result = ptr->name;
  delete ptr;
  return result;
};

/**
 * @brief 연결 리스트의 헤드 노드를 추가합니다.
 *
 * @param str
 */
void List::push_front(std::string str)
{
  Node *ptr = this->head;
  Node *new_node = new Node;
  new_node->prev = nullptr;
  new_node->name = str;
  if (!ptr)
  {
    new_node->next = nullptr;
    this->head = new_node;
    return;
  }
  new_node->next = ptr;
  ptr->prev = new_node;
  this->head = new_node;
};

/**
 * @brief 연결 리스트의 헤드 노드를 삭제합니다.
 *
 * @return std::string
 */
std::string List::pop_front()
{
  Node *ptr = this->head;
  if (!ptr)
  {
    return "";
  }
  this->head = ptr->next;
  std::string result = ptr->name;
  delete ptr;
  if (this->head)
  {
    (this->head)->prev = nullptr;
  }
  return result;
};

/**
 * @brief 연결 리스트의 중간에 노드를 추가합니다.
 *
 * @param node
 * @param str
 */
void List::insert(int node, std::string str)
{
  Node *ptr = this->head;
  if (!node)
  {
    return (this->push_front(str));
  }
  if (node > 0)
  {
    Node *p_prev;
    while (ptr)
    {
      if (!(node--))
      {
        Node *new_node = new Node;
        new_node->name = str;
        new_node->prev = p_prev;
        new_node->next = ptr;
        p_prev->next = new_node;
        ptr->prev = new_node;
        return;
      }
      p_prev = ptr;
      ptr = ptr->next;
    }
    std::cout << "index is bigger than the size of list." << '\n';
  }
  std::cout << "input number must be a positive number" << '\n';
};

/**
 * @brief 연결 리스트의 중간에 있는 노드를 삭제합니다.
 *
 * @return std
 */
std::string List::erase(int node)
{
  Node *ptr = this->head;
  if (!node)
  {
    return pop_front();
  }
  if (node > 0)
  {
    Node *p_prev;
    Node *p_next;
    while (ptr)
    {
      if (!(node--))
      {
        std::string result = ptr->name;
        delete ptr;
        p_prev->next = p_next;
        p_next->prev = p_prev;
        return result;
      }
      p_prev = ptr;
      ptr = ptr->next;
      p_next = ptr->next;
    }
    std::cout << "index is bigger than the size of list." << '\n';
    return "";
  }
  std::cout << "input number must be a positive number" << '\n';
  return "";
};

/**
 * @brief 연결 리스트의 노드의 총 개수를 반환합니다.
 *
 * @return int
 */
int List::size()
{
  Node *ptr = this->head;
  int count = 0;
  while (ptr)
  {
    ptr = ptr->next;
    count++;
  }
  return count;
};

/**
 * @brief 연결 리스트의 모든 노드를 제거합니다.
 *
 */
void List::clear()
{
  Node *ptr = this->head;
  Node *ptr_next;
  while (ptr)
  {
    ptr_next = ptr->next;
    delete ptr;
    ptr = ptr_next;
  }
}

/**
 * @brief 연결 리스트의 내부와 이중 포인터 모두 메모리 해재합니다.
 *
 */
void List::destroy()
{
  List *pp = this;
  this->clear();
  delete pp;
};