#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 50;


int main()
{
  ios::sync_with_stdio(false); 
  cin.tie(NULL);

  int testCases; //테케 개수
  vector<int> bugsCount;

  cin >> testCases;

  for(int idx=0; idx<testCases; idx++){
    int width; //밭 가로길이
    int height; //밭 세로길이
    int cabbages; //배추 개수
    vector< pair<int,int> > vertexes; //그래프의 정점들(visited==false)
    vector< pair<int,int> > graph[MAX][MAX];
    bool visited[MAX][MAX]; //배추가 없을경우/배추가있는데 방문했을 경우 true, 배추가 있는데 아직방문안했을경우 false
    int bugs = 0; //필요한 지렁이 수 

    //visited 배열을 true로 세팅
    for(int i=0; i<MAX; i++){
      for(int j=0; j<MAX; j++){
        visited[i][j] = true;
      }
    }

    cin >> width >> height >> cabbages;
    
    for(int i=0; i<cabbages; i++){
      int x, y;
      cin >> x >> y;
      visited[x][y] = false;
      vertexes.emplace_back(make_pair(x,y));
      
      if(x+1<MAX){
        if(!visited[x+1][y] ){
          graph[x][y].emplace_back(make_pair(x+1,y));
          graph[x+1][y].emplace_back(make_pair(x,y));
        }
      }
      if(x-1>=0){
        if(!visited[x-1][y]){
          graph[x][y].emplace_back(make_pair(x-1,y));
          graph[x-1][y].emplace_back(make_pair(x,y));
        }
      }
      if(y+1<MAX){
        if(!visited[x][y+1]){
          graph[x][y].emplace_back(make_pair(x,y+1));
          graph[x][y+1].emplace_back(make_pair(x,y));
        
        }
      }
      if(y-1>=0){
        if(!visited[x][y-1]){
          graph[x][y].emplace_back(make_pair(x,y-1));
          graph[x][y-1].emplace_back(make_pair(x,y));
        }
      }
    }

    //bfs통해 모든 정점 방문(start : )
    //맨처음 visited가 false인 점만 그래프의 정점으로서 존재
    //vertexes에 있는 pair들만 그래프의 정점으로서 존재
    //graph[그래프의정점][]의 값은 아무것도 없을수도, 벡터가 있을수도 있음

    while(!vertexes.empty()){
      queue< pair<int,int> > q;
      q.push(vertexes[0]);
      visited[vertexes[0].first][vertexes[0].second] = true;
      vertexes.erase(vertexes.begin());

      while(!q.empty()){
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        for(const auto &element : graph[x][y]){
          if(visited[element.first][element.second] == false){
            q.push(make_pair(element.first,element.second));
            visited[element.first][element.second] = true;
          }
        }
      }
      //vertexes중에서 visited==true인 애들 제거
      for(int i=0; i<vertexes.size(); i++){
        if(visited[vertexes[i].first][vertexes[i].second] == true){
          vertexes.erase(vertexes.begin()+i);
          i--;
        }
      }
      bugs++;
    }

    //bugsCount.emplace_back(bugs);
    cout << bugs << '\n';
  }
 
 /*
  for(const auto &element : bugsCount){
    cout << element << '\n';
  }
  */
}
