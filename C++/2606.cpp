#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 100;
bool visited[MAX+1];

int main()
{
  int computers;
  int edges;
  int count = 0;
  vector<int> adj[MAX+1]; //그래프 구현
  cin >> computers;
  cin >> edges;
  for(int i=0; i<edges; i++){
    int a, b;
    cin >> a >> b;
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
  }
  
  queue<int> q;
  q.push(1);
  visited[1] = true;
  while(!q.empty()){
    int now = q.front();
    q.pop();
    for(const auto &element : adj[now]){
      if(visited[element] == false){
        q.push(element);
        count++;
        visited[element] = true;
      }
    }
  }
  cout << count;
}