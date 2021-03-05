#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int building; // 건물 종류 수
  vector<int> time; //각 건물 짓는데 걸리는 시간
  vector<int> must_build; //앞서 지어야 하는 건물 수
  vector<vector<int>> build_after; //뒤에 지어야 하는 건물 번호
  queue<int> can_build; //현재 지을 수 있는 건물 번호
  int total_time = 0;


  cin >> building;
  time.assign(building+1, 0);
  must_build.assign(building+1, 0);
  build_after.assign(building+1, vector<int>());
  for(int i=1; i<=building; i++){
    cin >> time[i];
    int input;
    do{
      cin >> input;
      if(input == -1) break;
      build_after[input].emplace_back(i);
      must_build[i]++;
    }while(getc(stdin) == ' ');
  }

  //큐에 넣기
  for(int i=1; i<=building; i++){
    if(must_build[i] == 0){
      can_build.push(i);
    }
  }

  while(!can_build.empty())
  {
    int now = can_build.front();
    total_time += time[now];
    for(int i=0; i<build_after[now].size(); i++){
      must_build[build_after[now][i]]--;
      if( must_build[build_after[now][i]] == 0){
        can_build.push(build_after[now][i]);
      }
    }
    can_build.pop();
  }

}

//위상정렬과 거의 비슷하되, 이전 시간중 minimum을 더해준 시간이 이 건물을 짓는데 걸리는 시간.