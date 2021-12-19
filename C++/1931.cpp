#include <iostream>
#include <algorithm>

using namespace std;
typedef pair<int,int> P;
P meeting[100000]; //회의 끝시간, 시작시간

int main() {
  int N; //회의 수
  int maxCnt = 0; //최대 사용 회의 개수

  cin >> N;
  //회의시간 입력
  for(int i=0; i<N; i++) {
    P time;
    cin >> time.second >> time.first;
    meeting[i] = time;
  }
  
  sort(meeting, meeting+N); //끝시간 위주로 오름차순 정렬
  
  int end;
  for(int i=0; i<N; i++) {
    if(i==0) {
      end = meeting[i].first; //end=4
      maxCnt++;
    } else {
      if(meeting[i].second >= end) { //회의시작시간 >= 저번회의끝시간
        end = meeting[i].first;
        maxCnt++;
      }
    }
  }
  cout << maxCnt;
}