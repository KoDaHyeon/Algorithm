#include <iostream>
#include <stack>

using namespace std;

struct Pipe
{
  int fromR;
  int fromC;
  int toR;
  int toC;
};

bool isinHouse(int row, int col, int n)
{
  return (row <= n && col <= n);
}


int main()
{
  int N; //집의 크기
  int routeCnt = 0; //(N,N)에 도착할 수 있는 루트 수
  cin >> N;
  int house[N][N]; //집의 상태(빈칸/벽)
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cin >> house[i][j];
    }
  }

  stack<Pipe> route;
  Pipe now = {1-1, 1-1, 1-1, 2-1};
  while(true)
  {

    if(now.toR-now.fromR == 0){
      //가로
      //toR+0, toC+1 확인
      if(house[now.toR][now.toC+1] == 0 && now.toR < N && now.toC+1 < N){
        Pipe movedLoc = {now.toR, now.toC, now.toR, now.toC+1}; //이동할 수 있는 위치
        route.push(movedLoc);
      }
      //toR+1, toC+1 확인
      if(house[now.toR+1][now.toC+1] == 0 && house[now.toR][now.toC+1] == 0 && house[now.toR+1][now.toC] == 0
      && now.toR+1 < N && now.toC+1 < N && now.toR < N && now.toC+1 < N && now.toR+1 < N && now.toC < N){
        Pipe movedLoc = {now.toR, now.toC, now.toR+1, now.toC+1};
        route.push(movedLoc);
      }
    }

    else{ //now.toR-now.fromR == 1
      if(now.toC-now.fromC == 0){
        //세로
        //toR+1, toC+0 확인
        if(house[now.toR+1][now.toC] == 0 && now.toR+1 < N && now.toC < N){
          Pipe movedLoc = {now.toR, now.toC, now.toR+1, now.toC};
          route.push(movedLoc);
        }
        //toR+1, toC+1 확인
        if(house[now.toR+1][now.toC+1] == 0 && house[now.toR][now.toC+1] == 0 && house[now.toR+1][now.toC] == 0
        && now.toR+1 < N && now.toC+1 < N && now.toR < N && now.toC+1 < N && now.toR+1 < N && now.toC < N){
          Pipe movedLoc = {now.toR, now.toC, now.toR+1, now.toC+1};
          route.push(movedLoc);
        }
      }

      else{
        //대각선
        //toR, toC+1
        if(house[now.toR][now.toC+1] == 0 && now.toR < N && now.toC+1 < N){
          Pipe movedLoc = {now.toR, now.toC, now.toR, now.toC+1}; //이동할 수 있는 위치
          route.push(movedLoc);
        }
        //toR+1, toC
        if(house[now.toR+1][now.toC] == 0 && now.toR+1 < N && now.toC < N){
          Pipe movedLoc = {now.toR, now.toC, now.toR+1, now.toC};
          route.push(movedLoc);
        }
        //toR+1, toC+1
        if(house[now.toR+1][now.toC+1] == 0 && house[now.toR][now.toC+1] == 0 && house[now.toR+1][now.toC] == 0
        && now.toR+1 < N && now.toC+1 < N && now.toR < N && now.toC+1 < N && now.toR+1 < N && now.toC < N){
          Pipe movedLoc = {now.toR, now.toC, now.toR+1, now.toC+1};
          route.push(movedLoc);
        }
      }
    }

    if(route.empty()){
      break;
    }
    else{
      now = route.top();
      route.pop();
    }

    if(now.toR == N-1 && now.toC == N-1){ //도착
      routeCnt++;
      now = route.top();
      route.pop();
    }
  }
  cout << routeCnt;

}