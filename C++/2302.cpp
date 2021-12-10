#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int seats; //좌석 개수
  int fixed; //고정석 개수
  queue<int> fixedNum; //고정석 번호
  vector<int> count(3,0); //+1, 0, -1 가짓수 저장
  vector<int> answer;
  int tmpCnt = 0;
  int realAns = 1; //진짜 답!
  int exFixed = 0; //이전 고정석

  cin >> seats >> fixed;
  for(int i=0; i<fixed; i++){
    int number;
    cin >> number;
    fixedNum.push(number);
  }

  for(int i=1; i<=seats+1; i++){
    if(i == fixedNum.front()){ //현재 좌석이 고정석이면
      exFixed = fixedNum.front();
      fixedNum.pop();
      for(int j=0; j<3; j++){
        tmpCnt += count[j];
        count[j] = 0;
      }
      answer.emplace_back(tmpCnt);
      tmpCnt = 0;
    }
    else if(i == seats+1){ //현재 좌석이 맨 오른쪽 좌석 +1이면
      for(int j=0; j<3; j++){
        tmpCnt += count[j];
      }
      answer.emplace_back(tmpCnt);
    }
    else{
      if(i==1 || i-1==exFixed){
        count[0]++; //+1
        count[1]++; //0
      }
      else{
        int c0 = count[0];
        int c1 = count[1];
        int c2 = count[2];
        
        if(i+1!=fixedNum.front() && i!=seats){ //i>1이고, 고정석 바로 왼쪽 자리가 아니고, 맨 오른쪽끝 자리가 아닐때
          count[0] = c1 + c2; //+1은 앞에 0, -1 나왔을때만
        }
        count[1] = c1 + c2; //0은 앞에 0, -1 나왔을때만
        count[2] = c0; //-1은 앞에 +1 나왔을때만
      }
    }
  }
  
  for(int i=0; i<answer.size(); i++){
    realAns *= answer[i]-1;
    //cout << answer[i] << '\n';

  }
  cout << realAns;
  
}