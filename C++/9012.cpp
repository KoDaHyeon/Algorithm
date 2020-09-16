#include <iostream>
#include <string>

using namespace std;

int main()
{
  int case_cnt; //테스트 케이스 개수
  cin >> case_cnt;
  for(int i=0; i<case_cnt; i++)
  {
    string input;
    int cnt=0;
    cin >> input;
    
    for(int j=0; j<input.size(); j++)
    {
      if (input[j] == '(')
        cnt++;
      else if (input[j] == ')')
        cnt--;
      if (cnt < 0)
      {
        cout << "NO" << '\n';
        break;
      }

      if (j == input.size() - 1)
      {
        if (cnt == 0)
          cout << "YES" << '\n';
        else
          cout << "NO" << '\n';
        break;
      }
    }
  }
}