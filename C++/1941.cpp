#include <iostream>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;
char student_seat[5][5];
vector<pair<int, int>> som_seat; //S의 위치 (행, 열)
stack<pair<int, int>> moved; //이동해온 위치

bool canMove(int row, int col, int Y_count) //student_seat[row][col]위치로 이동할 수 있는지
{
  if(student_seat[row][col] == 'Y')
    Y_count++;
  if(row>=0 && row<5 && col>=0 && col<5 && Y_count<4)
    return true;
  else return false;
}

int main()
{

  for(int i=0; i<5; i++){
    string input;
    cin >> input;
    for(int j=0; j<5; j++){
      student_seat[i][j] = input[j];
      if(student_seat[i][j] == 'S'){
        som_seat.emplace_back(pair<int, int>(i, j));
      }
    }
  }

  int Y_count = 0;
  int case_count = 0; //경우의 수

  for(int i=0; i<som_seat.size(); i++){
    moved.push(som_seat[i]);

    while(true){
      if(canMove(moved.top().first, moved.top().second+1, Y_count) == true){ //오른쪽으로
        pair<int, int> next = make_pair(moved.top().first, moved.top().second+1); //이동할 위치
        if(student_seat[next.first][next.second] == 'Y')
          Y_count++;
        moved.push(next); //이동
        if(moved.size() == 7){
          case_count++;
          moved.pop();
        }
        continue;
      }

      else if(canMove(moved.top().first+1, moved.top().second, Y_count) == true){ //아래로
        pair<int, int> next = make_pair(moved.top().first+1, moved.top().second); //이동할 위치
          if(student_seat[next.first][next.second] == 'Y')
            Y_count++;
        moved.push(next); //이동
        if(moved.size() == 7){
          case_count++;
          moved.pop();
        }
      }

      else if(canMove(moved.top().first, moved.top().second, Y_count-1) == true){ //왼쪽으로
        pair<int, int> next = make_pair(moved.top().first, moved.top().second-1); //이동할 위치
        if(student_seat[next.first][next.second] == 'Y')
          Y_count++;
        moved.push(next); //이동
        if(moved.size() == 7){
          case_count++;
          moved.pop();
        }
      }

      else if(canMove(moved.top().first-1, moved.top().second, Y_count) == true){ //위로
        pair<int, int> next = make_pair(moved.top().first-1, moved.top().second); //이동할 위치
        if(student_seat[next.first][next.second] == 'Y')
         Y_count++;
        moved.push(next); //이동
        if(moved.size() == 7){
          case_count++;
          moved.pop();
        }
      }
    }
  }

}