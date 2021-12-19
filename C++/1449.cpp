#include <iostream>
#include <algorithm>

using namespace std;
float loc[1000]; //물이 새는 곳 위치

int main() {
  int N; //물이 새는 곳 개수
  int L; //테이프 길이
  int tapeCnt = 0; //필요한 테이프 개수
  int now = 0; //현재 인덱스
  float start; //테이프 시작 지점
  bool isNewStart = true;

  cin >> N >> L;
  for(int i=0; i<N; i++) {
    cin >> loc[i];
  }
  
  sort(loc, loc+N); //오름차순 정렬

  while(true) {
    if(now >= N) {
      break;
    }
    if(isNewStart) {
      start = loc[now] - 0.5;
      tapeCnt++;
    }
    
    if(start + L >= loc[now+1] + 0.5) { //테이프 안에 다음 지점이 들어가면
      now++;
      isNewStart = false;
    } else {
      now++;
      isNewStart = true;
    }
  }
  cout << tapeCnt;
}