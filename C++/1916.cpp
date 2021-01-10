#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#define INF LONG_MAX-1

using namespace std;

int main()
{
  int cities; //도시 개수
  int buses; //버스 개수
  vector <vector <pair<int,int> > > adj; //인접리스트
  priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > dist_queue;
  vector<long> dist; //노드까지의 최소비용
  int start_node, end_node;

  cin >> cities;
  cin >> buses;
  adj.assign(cities+1, vector< pair<int,int> >());
  dist.resize(cities+1, INF);

  for(int i=0; i<buses; i++){
    int start, end, cost;
    cin >> start >> end >> cost;
    adj[start].emplace_back(make_pair(cost, end));
  }

  cin >> start_node >> end_node;
  dist_queue.push(make_pair(0, start_node));
  dist[start_node] = 0;

  while(!dist_queue.empty()){
    int now = dist_queue.top().second;
    int cost = dist_queue.top().first;
    dist_queue.pop();

    for(int i=0; i<adj[now].size(); i++){
      int newNode = adj[now][i].second;
      long newCost = dist[now] + adj[now][i].first;

      if(dist[newNode] > newCost){
        dist[newNode] = newCost; //dist배열 업데이트
        dist_queue.push(adj[now][i]);
      }
    }
  }

  cout << dist[end_node];

}