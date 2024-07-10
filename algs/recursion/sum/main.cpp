// 재귀 합 : 재귀를 통해 1 ~ 10을 전부 합하여 값을 구합니다.
#include <iostream>

int rec_sum(int n)
{
  if (n == 1)
  {
    return n;
  }
  return n + rec_sum(n - 1);
}

int main()
{
  std::cout << rec_sum(10) << '\n';
  return 0;
}