#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 1000;
vector<int> graph[MAX + 1];
bool visited[MAX + 1];

void bfs(int start)
{
  queue<int> q;
  visited[start] = true;
  q.push(start);
  while (!q.empty())
  {
    int now = q.front();
    q.pop();
    cout << now << ' ';
    priority_queue<int, vector<int>, greater<int>> pq;
    for (const auto &element : graph[now])
    {
      pq.push(element); //오름차순정렬돼서 나옴
    }
    while (!pq.empty())
    {
      int v = pq.top();
      pq.pop();
      if (visited[v] == false)
      {
        q.push(v);
        visited[v] = true;
      }
    }
  }
}

void dfs(int start)
{
  if (visited[start])
    return;
  visited[start] = true;
  cout << start << ' ';
  priority_queue<int, vector<int>, greater<int>> pq;
  for (const auto &element : graph[start])
  {
    pq.push(element);
  }
  while (!pq.empty())
  {
    int v = pq.top();
    pq.pop();
    if (visited[v] == false)
    {
      dfs(v);
    }
  }
}

int main()
{
  int vertexes; //정점개수
  int edges;    //간선개수
  int startV;   //탐색시작할 정점번호

  cin >> vertexes >> edges >> startV;
  for (int i = 0; i < edges; i++)
  {
    int v1, v2;
    cin >> v1 >> v2;
    graph[v1].emplace_back(v2);
    graph[v2].emplace_back(v1);
  }

  dfs(startV);
  cout << '\n';
  //visited 초기화
  for (int i = 1; i < MAX + 1; i++)
  {
    visited[i] = false;
  }
  bfs(startV);
}