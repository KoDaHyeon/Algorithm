#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
  string input; //문자열
  vector<int> alp_cnt(26, 0); //각 알파벳 개수
  cin >> input;

  for(int i=0; i<input.size(); i++){
    char now = input[i];
    alp_cnt[now-'a']++;
  }

  for(int i=0; i<26; i++){
    cout << alp_cnt[i] << " ";
  }
}