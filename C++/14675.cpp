#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
  int N; //정점의 개수
  int q; //질의의 개수
  cin >> N;
  vector< vector<int> > tree(N+1, vector<int>());

  //간선에 대한 정보 입력받기
  for(int i=0; i<N-1; i++){
    int v1, v2;
    cin >> v1 >> v2;
    tree[v1].emplace_back(v2);
  }

  cin >> q;
  for(int i=0; i<q; i++){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int type, target;
    string answer = "yes";
    cin >> type >> target;
    switch(type)
    {
      case 1:
        //해당 정점이 루트노드 && 자식노드가 1개면
        if(target==1 && tree[target].size()==1){
          answer = "no";
        }
        //해당 정점이 leaf노드면
        else if(target!=1 && tree[target].size()==0){
          answer = "no";
        }
        break;
      case 2:
        break;
      default: break;
    }
    cout << answer << '\n';
  }
}