#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define INF LONG_MAX-1

using namespace std;

int main()
{
  int vertices; //정점 수
  int edges; //간선 수
  int ncs1, ncs2; //반드시 거쳐야할 정점 2개
  vector< vector< pair<int,int> > > adj; //인접 리스트
  vector<long> dist; //정점까지의 최소거리
  priority_queue< pair<long,int>, vector< pair<long,int> >, greater< pair<long,int> > > dist_queue;
  vector< pair<bool,bool> > visited;
  int ex_node; //전 노드
  pair<long, int> wasNcs = make_pair(0, 0); //전에 탐색한 노드가 ncs였는지(dist, 노드번호)

  cin >> vertices >> edges;
  adj.assign(vertices+1, vector< pair<int,int> >());
  dist.assign(vertices+1, INF);
  visited.assign(vertices+1, make_pair(false,false));

  for(int i=0; i<edges; i++){
    int v1, v2, cost; //정점1, 정점2, cost
    cin >> v1 >> v2 >> cost;
    adj[v1].emplace_back(make_pair(cost,v2));
    adj[v2].emplace_back(make_pair(cost,v1));
  }
  cin >> ncs1 >> ncs2;

  dist_queue.push(make_pair(0,1));
  dist[1] = 0;
  ex_node = 1;

  while(!dist_queue.empty()){
    int now;
    int cost;
    if(wasNcs.second != 0){
      now = wasNcs.second;
      cost = wasNcs.first;
    }
    else{
      now = dist_queue.top().second; //현재 방문중인 노드
      cost = dist_queue.top().first; //출발지~현재 방문중인 노드까지의 거리
      dist_queue.pop();
    }

    for(int i=0; i<adj[now].size(); i++){
      int newNode = adj[now][i].second;
      long newCost = dist[now] + adj[now][i].first;

      if(newNode == ex_node){
        if(ex_node == ncs1 || ex_node == ncs2){}
        else continue;
      }

      if((newNode == ncs1 || newNode == ncs2) && !(visited[newNode].first && visited[newNode].second)){
        wasNcs.first = ;
        wasNcs.second = newNode;
      }

      
      if((now == ncs1 || now == ncs2) && !(visited[newNode].first && visited[newNode].second)){ //현재방문중인노드가 v1/v2인 경우
        dist[newNode] = newCost;
        if
        dist_queue.push(adj[now][i]);
        if(now == ncs1){
          visited[newNode].first = true;
        }
        else{
          visited[newNode].second = true;
        }
      }
      else{
        if(newCost < dist[newNode]){
          dist[newNode] = newCost;
          dist_queue.push(adj[now][i]);
        }
      }
    }
    ex_node = now;
  }

  cout << dist[vertices];

}