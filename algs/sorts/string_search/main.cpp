// 문자열 내부의 문자 개수를 세는 함수입니다.
// 형식은 a1b2c3와 같이 알파벳 순으로 몇개씩 존재하는지를 같이 표시합니다.
// 입력된 문자열에 없는 알파벳은 표시하지 않습니다. (a1z0이 아니라 a1만 표시)
#include <iostream>
#include <string>

void print_result(std::string str)
{
  int table[26] = {0};
  for (int i = 0; i < str.size(); i++)
  {
    table[(char)str[i] - 'a']++;
  }
  for (int i = 0; i < 26; i++)
  {
    if (table[i])
    {
      std::cout << (char)(i + 'a') << table[i];
    }
  }
  std::cout << '\n';
}

int main()
{
  std::string str = "zaanvfpkncvxzdnbzdgpnsrgnp";
  print_result(str);
  return 0;
}