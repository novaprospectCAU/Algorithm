// 버블 정렬 : 인접한 두 값을 계속 비교하는 정렬
#include <iostream>

// 편의상 signed int범위 내의 값만을 받는다고 가정합니다.
void bubble_sort(int arr[], int size)
{
  for (int y = 0; y < size - 1; y++)
  {
    for (int x = y + 1; x < size; x++)
    {
      if (arr[y] > arr[x])
      {
        arr[y] += arr[x];
        arr[x] = arr[y] - arr[x];
        arr[y] -= arr[x];
      }
    }
  }
}

int main()
{
  int size = 10;
  int arr[] = {8, 5, 2, 6, 9, 3, 0, 4, 1, 7};
  bubble_sort(arr, sizeof(arr) / sizeof(int));
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}