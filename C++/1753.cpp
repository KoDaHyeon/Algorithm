#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;
typedef pair<int, int> P;

int main()
{
  vector<int> distance; //시작점~정점까지의 최단 거리
  priority_queue< P, vector<P>, greater<P> > Q; //최단거리를 확인한 정점
  vector< pair<int, int> > adj[20001]; //(인접한 정점, 가중치)

  int V, E, K; //정점수, 간선수, 시작정점번호
  cin >> V >> E;
  distance.resize(V+1, INT_MAX); //V+1로 resize, 모든 원소를 INT_MAX로

  cin >> K;
  distance[K] = 0;

  for(int i=0; i<E; i++){
    int from, to, cost;
    cin >> from >> to >> cost;
    adj[from].emplace_back(make_pair(to,cost)); //(정점, 간선거리)
  }

  Q.push(P(0,K)); //Q.push(make_pair(0,K));
  while(!Q.empty())
  {
    int cost = Q.top().first;
    int vertex = Q.top().second;
    Q.pop();

    int tmp_adjSize = adj[vertex].size();
    for(int i=0; i<tmp_adjSize; i++)
    {
      int nextVtx = adj[vertex][i].first;
      if(distance[vertex] + adj[vertex][i].second < distance[nextVtx])
      {
        distance[nextVtx] = distance[vertex] + adj[vertex][i].second;
        Q.push(P(distance[nextVtx],nextVtx));
      }

    }
  }

  for(int i=1; i<=V; i++)
  {
    if(distance[i] == INT_MAX){
      cout << "INF" << '\n';
    }
    else{
      cout << distance[i] << '\n';
    }
  }
}


/*
큐에 시작점~시작점 (거리, 정점) 넣음

큐가 빌때까지
1. 큐에서 pop
2. pop한 애와 인접한 정점(next)들 모두에 대해 
지금까지 알려진 시작점~next까지의 거리가
시작점~pop한 정점까지거리+pop한정점~next까지 거리보다
크면, 시작점~next까지의 거리 업뎃,
거리를 업뎃한 경우 (시작점~next까지 거리, 정점next)를 큐에 넣음
*/