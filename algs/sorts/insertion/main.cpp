// 삽입 정렬 : 가장 적절한 위치에 값을 집어넣고 다 한 칸씩 미는 정렬
#include <iostream>

void insertion_sort(int arr[], int size)
{
  for (int y = 1; y < size; y++)
  {
    if (arr[y] < arr[y - 1])
    {
      int index = y - 1;
      // 삽입할 위치를 찾습니다.
      for (int x = y - 2; x > -1; x--)
      {
        if (arr[x] < arr[y]) // 자신보다 바로 아래 값을 발견하면 그 값 다음 값부터 정렬
        {
          index = x + 1;
          break;
        }
        if (x == 0) // 앞의 모든 값들이 자신보다 클 경우
        {
          index = 0;
          break;
        }
      }

      int temp = arr[y]; // 삽입 대상을 임시 저장합니다.

      // 뒤로 한칸씩 밀어줍니다.
      for (int x = y; x > index - 1; x--)
      {
        arr[x] = arr[x - 1];
      }

      // 삽입을 해줍니다.
      arr[index] = temp;
    }
  }
}

// 편의상 signed int범위 내의 값만을 받는다고 가정합니다.
int main()
{
  int size = 10;
  int arr[] = {8, 5, 2, 6, 9, 3, 0, 4, 1, 7};
  insertion_sort(arr, sizeof(arr) / sizeof(int));
  for (int i = 0; i < size; i++)
  {
    std::cout << arr[i] << ' ';
  }
  std::cout << '\n';
  return 0;
}