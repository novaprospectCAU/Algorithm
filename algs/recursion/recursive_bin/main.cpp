// 이진 탐색 : 중심값을 기준으로 비교하며 값을 찾습니다.
// 탐색은 이미 정렬이 되었다는 가정하에 진행합니다.
// 이미 구현한 이진 탐색을 재귀방식으로 다시 구현합니다.
#include <iostream>

// 선택 정렬을 사용합니다.
void selection_sort(int arr[], int size)
{
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
}

int binary_search(int arr[], int size, int n, int l, int r)
{
  if (arr[size - 1] == n)
  {
    return size - 1;
  }
  while (r != l)
  {
    int mid = (l + r) / 2;
    if (arr[mid] == n)
    {
      return mid;
    }
    if (arr[mid] < n)
    {
      if (l == mid)
      {
        return -1;
      }
      return binary_search(arr, size, n, mid, r);
    }
    else
    {
      if (r == mid)
      {
        return -1;
      }
      return binary_search(arr, size, n, l, mid);
    }
  }
  return -1; // 값이 존재하지 않는 경우
}

int main()
{
  int size = 10;
  int arr[] = {8, 5, 2, 6, 9, 3, 0, 4, 1, 7};
  selection_sort(arr, sizeof(arr) / sizeof(int));
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
  std::cout << "index of " << 13 << ": " << binary_search(arr, sizeof(arr) / sizeof(int), 13, 0, sizeof(arr) / sizeof(int)) << '\n';
  std::cout << "index of " << 0 << ": " << binary_search(arr, sizeof(arr) / sizeof(int), 0, 0, sizeof(arr) / sizeof(int)) << '\n';
  std::cout << "index of " << 1 << ": " << binary_search(arr, sizeof(arr) / sizeof(int), 1, 0, sizeof(arr) / sizeof(int)) << '\n';
  std::cout << "index of " << 2 << ": " << binary_search(arr, sizeof(arr) / sizeof(int), 2, 0, sizeof(arr) / sizeof(int)) << '\n';
  std::cout << "index of " << 3 << ": " << binary_search(arr, sizeof(arr) / sizeof(int), 3, 0, sizeof(arr) / sizeof(int)) << '\n';
  std::cout << "index of " << 4 << ": " << binary_search(arr, sizeof(arr) / sizeof(int), 4, 0, sizeof(arr) / sizeof(int)) << '\n';
  std::cout << "index of " << 5 << ": " << binary_search(arr, sizeof(arr) / sizeof(int), 5, 0, sizeof(arr) / sizeof(int)) << '\n';
  std::cout << "index of " << 6 << ": " << binary_search(arr, sizeof(arr) / sizeof(int), 6, 0, sizeof(arr) / sizeof(int)) << '\n';
  std::cout << "index of " << 7 << ": " << binary_search(arr, sizeof(arr) / sizeof(int), 7, 0, sizeof(arr) / sizeof(int)) << '\n';
  std::cout << "index of " << 8 << ": " << binary_search(arr, sizeof(arr) / sizeof(int), 8, 0, sizeof(arr) / sizeof(int)) << '\n';
  std::cout << "index of " << 9 << ": " << binary_search(arr, sizeof(arr) / sizeof(int), 9, 0, sizeof(arr) / sizeof(int)) << '\n';
  return 0;
}