#include <iostream>
#include <string>

using namespace std;

int main()
{
  while (1)
  {
    string input;
    int count[4] = {0, }; //소문자, 대문자, 숫자, 공백의 개수
    getline(cin, input); 
    if(input == "") break;

    int input_size = input.size();
    for (int i = 0; i < input_size; i++)
    {
      if (0 <= input[i] - 'a' && input[i] - 'a' < 26)
        count[0]++;
      else if (0 <= input[i] - 'A' && input[i] - 'A' < 26)
        count[1]++;
      else if (0 <= input[i] - '0' && input[i] - '0' < 10)
        count[2]++;
      else if (input[i] == ' ')
        count[3]++;
      else continue;
    }

    for (const auto &element : count)
    {
      cout << element << ' ';
    }
    cout << '\n';
  }
}