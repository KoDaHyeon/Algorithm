#include <iostream>
#include <queue>
#include <vector>
#include <stack>

using namespace std;

const int MAXV = 7;
bool visited[MAXV+1]; //false
vector<int> adj[MAXV+1];
vector<bool> isInStack;

//bfs
void bfs(int start) {
  queue<int> willVisit;
  willVisit.push(start);
  visited[start] = true;

  while(!willVisit.empty()) {
    int now = willVisit.front();
    willVisit.pop();

    for(const auto &e : adj[now]) {
      if(!visited[e]) {
        willVisit.push(e);
        visited[now] = true;
      }
    }
  }
}


//stack으로 dfs
void dfsByStack(int start) {
  stack<int> willVisit;
  willVisit.push(start);
  visited[start] = true;

  while(!willVisit.empty()) {
    int now = willVisit.top();
    willVisit.pop();

    for(const auto &e : adj[now]) {
      if(!visited[e]) {
        willVisit.push(e);
        visited[e] = true;
      }
    }
  }
}


//재귀함수로 dfs
void dfsByFunc(int start) {
  if(visited[start] == true) return;
  visited[start] = true;

  for(const auto & next : adj[start]) {
    if(!visited[next]) {
      dfsByFunc(next);
    }
  }
}


//start에서 시작하는 그래프에 사이클이 있는지 확인 - 있으면 true 반환
bool cycleDfs(int start) {
  if(isInStack[start]) return true; //호출스택에 있는 정점(사이클)
  if(visited[start]) return false; //호출스택x, 아까 방문o - 이미 사이클 루트에서 벗어났으므로 사이클일 수 없음

  //새로 방문하는 정점
  isInStack[start] = true;
  visited[start] = true;

  for(const auto & next : adj[start]) {
    if(cycleDfs(next)) return true;
  }
  
  isInStack[start] = false;
  return false;
}


//lower bound(이진탐색) - target 이상인 값이 처음 나오는 위치 찾기
int lower_bound(int *arr, int target, int size) {
  int left, right, mid;
  left = 0;
  right = size-1;

  while(left<right) { //left<=right 로 하면, l=r=m이고 arr[m]>=target일때 무한반복 걸림
    mid = (left + right) / 2;
    if(arr[mid] >= target) {
      right = mid;
    } else { //arr[mid] < target
      left = mid + 1;
    }
  }
  return right; //return mid; x //return left; o
}

//upper bound(이진탐색) - target보다 큰 값이 처음으로 나타나는 위치 찾기
int upper_bound(int *arr, int target, int size) {
  int left, right, mid;
  left = 0;
  right = size - 1;

  while(left<right) {
    mid = (left + right) / 2;
    if(arr[mid] <= target) {
      left = mid + 1;
    } else { //arr[mid] > target
      right = mid;
    }
  }
  return left; //return right; o
}