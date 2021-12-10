#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;
typedef pair<int,int> P; //(int,int)
const int MAXN = 25;

bool visited[MAXN+2][MAXN+2]; //방문 여부(false로 초기화)
vector<P> adj[MAXN+2][MAXN+2]; //그래프 인접
int town[MAXN+2][MAXN+2]; //1 or 0 (0으로 초기화)

int bfs(P start) {
  queue<P> q; //BFS 큐
  int cnt=0; //단지 내 집 수

  q.push(start);
  visited[start.first][start.second] = true;

  while(!q.empty()) {
    P now = q.front();
    q.pop();
    cnt++;

    for(const auto &e : adj[now.first][now.second]) {
      if(!visited[e.first][e.second]) {
        q.push(e);
        visited[e.first][e.second] = true;
      }
    }
  }
  return cnt;
}


int main() {
  int N, towns; //지도의 크기, 총 단지 수
  priority_queue<int, vector<int>, greater<int>> lessQ; //단지 내 집 수를 오름차순으로 반환

  cin >> N;

  //input
  for(int i=1; i<=N; i++) {
    string input;
    cin >> input;
    for(int j=0; j<N; j++) {
      town[i][j+1] = input[j]-'0'; //char to int
    }
  }

  //인접리스트 완성
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      if(town[i][j] == 1) {
        if(town[i-1][j] == 1) { //위
          adj[i][j].emplace_back(P(i-1,j));
        }
        if(town[i][j+1] == 1) { //오른쪽
          adj[i][j].emplace_back(P(i,j+1));
        }
        if(town[i][j-1] == 1) { //왼쪽
          adj[i][j].emplace_back(P(i,j-1));
        }
        if(town[i+1][j] == 1) { //아래
          adj[i][j].emplace_back(P(i+1,j));
        }
      }
    }
  }

  //BFS
  for(int i=1; i<=N; i++) {
    for(int j=1; j<=N; j++) {
      if(town[i][j] == 1 && visited[i][j] == false) {
        lessQ.push(bfs(P(i,j)));
      }
    }
  }
  
  //총 단지수, 오름차순으로 출력
  cout << lessQ.size() << '\n';
  while(!lessQ.empty()) {
    cout << lessQ.top() << '\n';
    lessQ.pop();
  }
}