#include <iostream>
#include <queue>

using namespace std;

int main()
{
  priority_queue< int, vector<int>, greater<int> > cake_pq; //길이가 10의 배수인 케이크들
  queue<int> cake_q; //길이가 10의 배수가 아닌 케이크들
  int cakes; //롤케이크 개수
  int cuts; //최대 자를 수 있는 횟수
  int now_cut = 0; //현재 자른 횟수
  int cnt = 0; //길이가 10인 롤케이크 개수
  
  cin >> cakes >> cuts;
  for(int i=0; i<cakes; i++){
    int length;
    cin >> length;
    if(length % 10 == 0){ //길이가 10의 배수이면
      cake_pq.push(length);
    }
    else{ //10의 배수가 아니면
      cake_q.push(length);
    }
  }

  while(!cake_pq.empty()){ //10의 배수인 케이크들 작은 길이부터 자르기
    int now = cake_pq.top();
    cake_pq.pop();
    while(now > 10){
      if(now_cut >= cuts){
        break;
      }
      cnt++;
      now_cut++;
      now = now - 10;
    }
    if(now == 10){
      cnt++;
    }
  }

  while(!cake_q.empty()){ //10의 배수가 아닌 케이크들 자르기
    int now = cake_q.front();
    cake_q.pop();
    if(now_cut >= cuts){
      break;
    }
    while(now > 10){
      if(now_cut >= cuts){
        break;
      }
      cnt++;
      now_cut++;
      now = now - 10;
    }
  }

  cout << cnt;
}