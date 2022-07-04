#include <iostream>
#include <vector>
#include <queue>
#include <string>

using namespace std;

const int MAXN = 100;
const int MAXM = 100;
int maze[MAXN + 1][MAXM + 1];
vector<pair<int, int>> adj[MAXN + 1][MAXM + 1];
int level[MAXN + 1][MAXM + 1];
bool visited[MAXN + 1][MAXM + 1];

int main()
{
  int N, M;
  cin >> N >> M;

  for (int i = 1; i <= N; i++)
  {
    string input;
    cin >> input;
    // input 자르기 -> maze배열에 넣기
    for (int j = 1; j <= M; j++)
    {
      maze[i][j] = input[j - 1] - '0';
    }
  }

  // adj 구성
  for (int i = 1; i <= N; i++)
  {
    for (int j = 1; j <= M; j++)
    {
      visited[i][j] = false;

      if (maze[i][j] == 1)
      {
        //상하좌우 1이면 인접리스트에 추가
        //배열에서 실제로 쓰는 크기 + 1로 크기를 잡아두면, i-1, j-1해서 배열의 범위값을 벗어나는 경우가 없으므로 직접 처리하지 않아도 됨
        //한겹씩 껍질을 감싼다고 생각!
        if (maze[i - 1][j] == 1)
        { //상
          adj[i][j].emplace_back(make_pair(i - 1, j));
        }
        if (maze[i + 1][j] == 1)
        { //하
          adj[i][j].emplace_back(make_pair(i + 1, j));
        }
        if (maze[i][j - 1] == 1)
        { //좌
          adj[i][j].emplace_back(make_pair(i, j - 1));
        }
        if (maze[i][j + 1] == 1)
        { //우
          adj[i][j].emplace_back(make_pair(i, j + 1));
        }
      }
    }
  }

  // bfs
  queue<pair<int, int>> q;
  visited[1][1] = true;
  level[1][1] = 1;
  q.push(make_pair(1, 1));
  while (!q.empty())
  {
    int x = q.front().first;
    int y = q.front().second;

    if (x == N && y == M)
    {
      cout << level[x][y];
      break;
    }
    q.pop();
    for (const auto &element : adj[x][y])
    {
      if (visited[element.first][element.second] == false)
      {
        q.push(element);
        level[element.first][element.second] = level[x][y] + 1;
        visited[element.first][element.second] = true;
      }
    }
  }
}