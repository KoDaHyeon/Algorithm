#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100000;
vector<int> adj[MAX+1];

int main()
{
  int stations; //역의 수
  int linked; //한 하이퍼튜브가 연결하는 역의 개수
  int tubes; //하이퍼튜브 수
  
  cin >> stations >> linked >> tubes;

  for(int i=0; i<tubes; i++){
    vector<int> linkedState;
    linkedState.resize(linked);
    for(int j=0; j<linked; j++){ //한 튜브
      cin >> linkedState[j];
    }
    for(int j=0; j<linked-1; j++){
      for(int k=j+1; k<linked; k++){
        adj[j].emplace_back(k);
        adj[k].emplace_back(j);
      }
    }
  }

}