// 선택 정렬 : 가장 작은 값을 계속 앞으로 보내는 정렬
#include <iostream>

// 편의상 양수 signed int범위 내의 값만을 받는다고 가정합니다.
int main()
{
  int size = 10;
  int arr[] = {8, 5, 2, 6, 9, 3, 0, 4, 1, 7};
  int min = arr[0];
  int index = 0;
  for (int y = 0; y < size; y++)
  {
    min = arr[y];
    index = y;
    for (int x = y + 1; x < size; x++)
    {
      if (arr[x] < min)
      {
        min = arr[x];
        index = x;
      }
    }
    int temp = arr[y];
    arr[y] = arr[index];
    arr[index] = temp;
  }
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}