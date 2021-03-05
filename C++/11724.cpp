#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int MAX = 1000;
vector<int> adj[MAX+1]; //그래프 구현
bool visited[MAX+1];

int main()
{

  ios::sync_with_stdio(false); 
  cin.tie(NULL);
  
  int nodes;
  int edges;
  int count = 0;
  stack<int> s;
  cin >> nodes >> edges;
  for(int i=0; i<edges; i++){
    int n1, n2;
    cin >> n1 >> n2;
    adj[n1].emplace_back(n2);
    adj[n2].emplace_back(n1);
  }

  visited[1] = true;
  s.push(1);
  while(true){
    while(!s.empty()){
      int now = s.top();
      s.pop();
      for(const auto &element : adj[now]){
        if(visited[element] == false){
          s.push(element);
          visited[element] = true;
        }
      }
    } //하나의 연결요소 다 방문
    count++;
    bool isAllVisited = true;
    for(int i=1; i<=nodes; i++){
      if(visited[i] == false){
        s.push(i);
        visited[i] = true;
        isAllVisited = false;
        break;
      }
    }
    if(isAllVisited){
      break;
    }
  }

  cout << count;

}