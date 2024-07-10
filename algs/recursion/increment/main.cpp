// 1씩 증가하며 10까지 출력하는 함수입니다.
#include <iostream>

void recursion(int n)
{
  if (n == 11)
  {
    return;
  }
  std::cout << n << '\n';
  recursion(n + 1);
}

int main()
{
  recursion(1);
  return 0;
}