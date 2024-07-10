#include <iostream>

// 재귀를 사용한 방법
int rec_fibo(int n)
{
  if (n == 0 || n == 1)
  {
    return n;
  }
  return (rec_fibo(n - 2) + rec_fibo(n - 1));
}

// 반복문을 사용한 방법
int loop_fibo(int n)
{
  int a = 0;
  int b = 1;
  n--;
  while (n)
  {
    b = a + b;
    a = b - a;
    n--;
  }
  return b;
}

int main()
{
  // 0번째부터 이므로 10번째 수는 실제로는 11번째 수를 의미합니다.
  std::cout << "recursion : " << rec_fibo(10) << '\n';
  std::cout << "loop : " << loop_fibo(10) << '\n';
  return 0;
}