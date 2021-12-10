#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  ios::sync_with_stdio(false); 
  cin.tie(NULL);

  int N, H; //가로, 높이
  int cnt = 0; //파괴하는 장애물 개수
  int minCnts = N; //최소 파괴수
  int minCntsLen = 0; //최소 파괴수인 구간의 수
  vector<int> length; //장애물 길이
  vector<int> cnts; //구간별 파괴하는 장애물 개수
  priority_queue< int, vector<int>, greater<int> > length_pq_even; //종유석 우선순위큐(내림차순)
  priority_queue< int, vector<int>, greater<int> > length_pq_odd; //석순 우선순위큐(내림차순)

  cin >> N >> H;
  cnts.resize(H+1);
  for(int i=1; i<=N; i++){
    int len;
    cin >> len;
    if(i % 2 == 0){
      length_pq_even.push(len);
    }
    else{
      length_pq_odd.push(len);
    }
  }

  while(!length_pq_even.empty()){ //종유석
    int len = length_pq_even.top();
    length_pq_even.pop();
    for(int i=1; i<=H; i++){ //구간별로 계산
      if(H - len < i){
        cnts[i]++;
        
      }
    }
  }







  for(int i=1; i<=H; i++){ //각 구간별. i는 구간높이

    for(int j=1; j<=N; j++){
      if(j % 2 == 0){ //종유석
        if(H - length[j] < i){ //전체높이 - 종유석높이 < 구간높이 이면 파괴
          cnts[i]++;
        }
      }
      else{ //석순
        if(length[j] >= i){
          cnts[i]++;
        }
      }
      //minCnts를 넘어가면 더이상 할 필요 없음
      if(cnts[i] > minCnts){
        break;
      }
    }
    if(minCnts == cnts[i]){
      minCntsLen++;
    }
    else if(minCnts > cnts[i]){
      minCnts = cnts[i];
      minCntsLen = 1;
    }
  }
  

  for(int i=1; i<=H; i++){
    cout << cnts[i] << ' ';
  }
  cout << '\n';

  cout << minCnts << ' ' << minCntsLen;
}