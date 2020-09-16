#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int main()
{
  ios::sync_with_stdio(false); 
  cin.tie(NULL);

  string input; //초기에 입력한 문자열
  int cmd_cnt; //명령어 개수
  stack<char> cursor_left; //커서 왼쪽에 위치하는 문자들
  stack<char> cursor_right; //커서 오른쪽에 위치하는 문자들

  cin >> input;
  cin >> cmd_cnt;

  for(int i=0; i<input.size(); i++){
    cursor_left.push(input[i]);
  }

  cin.ignore(256, '\n');
  for(int i=0; i<cmd_cnt; i++){
    //명령어를 받고 수행
    string cmd; //명령어
    getline(cin, cmd);

    if(cmd == "L"){
      if(!cursor_left.empty()){
        cursor_right.push(cursor_left.top());
        cursor_left.pop();
      }
    }
    else if(cmd == "D"){
      if(!cursor_right.empty()){
        cursor_left.push(cursor_right.top());
        cursor_right.pop();
      }
    }
    else if(cmd == "B"){
      if(!cursor_left.empty()){
        cursor_left.pop();
      }
    }
    else if(cmd[0] == 'P'){
      cursor_left.push(cmd[2]);
    }
  }

  vector<char> tmp;
  while(!cursor_left.empty()){
    tmp.emplace_back(cursor_left.top());
    cursor_left.pop();
  }
  
  for(int i=tmp.size()-1; i>=0; i--){
    cout << tmp[i];
  }

  while(!cursor_right.empty()){
    cout << cursor_right.top();
    cursor_right.pop();
  }

}