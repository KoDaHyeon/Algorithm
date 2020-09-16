#include <iostream>
#include <stack>

using namespace std;

int main()
{
  string input; //괄호표현 input
  cin >> input;
  stack<int> pieces;
  int input_size = input.size();
  int total_pieces = 0;

  for(int i=0; i<input_size; i++){
    if(input[i] == '(')
    {
      if(input[i+1] == ')') //레이저인 경우
      {
        total_pieces += pieces.size(); //스택에 있는 파이프에 각각 +1
        i++;
        continue;
      }
      else //쇠파이프의 시작인 경우
      {
        pieces.push(1);
      }
    }

    else if(input[i] == ')')
    {
      total_pieces += pieces.top();
      pieces.pop();
    }
  }

  cout << total_pieces;
}