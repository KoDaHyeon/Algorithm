#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  string input;
  vector<string> arr;
  cin >> input;

  int total_len = input.size(); //input 문자열의 길이
  arr.resize(total_len);
  
  //문자열을 잘라 arr에 넣기
  for(int i=0; i<total_len; i++)
  {
    arr[i] = input.substr(i);
  }

  sort(arr.begin(), arr.begin()+total_len); //사전순으로 정렬

  for(int i=0; i<total_len; i++)
  {
    cout << arr[i] << '\n';
  }

}