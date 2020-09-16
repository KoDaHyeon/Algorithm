#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
  string word; //입력받은 단어
  int alp_idx[26]; //각 알파벳 첫 등장 위치
  fill(alp_idx, alp_idx+sizeof(alp_idx)/sizeof(int), -1);
  cin >> word;

  for(int i=0; i<word.size(); i++)
  {
    if(alp_idx[word[i] - 'a'] == -1)
      alp_idx[word[i] - 'a'] = i;
    else continue;
  }

  for(const auto& element: alp_idx)
    cout << element << ' ';
}