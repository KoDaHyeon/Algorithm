#include <iostream>
#include <vector>

using namespace std;
vector<int> parent;
vector<int> rankk;

//node의 루트노드를 반환
int find(int node)
{
  if(parent[node] == node) return node;
  parent[node] = find(parent[node]); //경로 압축
  return parent[node];
}

//node1가 포함된 집합, node2가 포함된 집합을 합침
void merge(int node1, int node2)
{
  parent[find(node1)] = find(node2);
}


int main()
{
  ios::sync_with_stdio(false); 
  cin.tie(NULL);

  int n, m; //{0}~{n}집합, 개수
  int operation; //연산의 종류

  cin >> n >> m;
  parent.resize(n+1);
  rankk.resize(n+1);
  for(int i=0; i<n+1; i++){
    parent[i] = i;
    rankk[i] = 1;
  }

  for(int i=0; i<m; i++){
    int a, b;
    cin >> operation >> a >> b;
    switch(operation){
      case 0: //merge
        merge(a, b);
        break;
      case 1: //find->같은 집합에 속해있는지 확인
        if(find(a) == find(b)) cout << "YES" << '\n';
        else cout << "NO" << '\n';
        break;
      default:
        break;
    }
  }
}