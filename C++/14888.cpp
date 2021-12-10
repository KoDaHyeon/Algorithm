#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int N; //수의 개수
  vector<int> list; //수열
  vector<int> opr(4); //연산자 + - x / 개수
  vector<int> tmp;
  
  cin >> N;
  list.resize(N);
  tmp.resize(N-1);

  for(int i=0; i<N; i++){
    cin >> list[i];
    if(i < N-1){
      tmp[i] = i;
    }
  }
  for(int i=0; i<3; i++){
    cin >> opr[i];
  }

  do{
    
  }while(next_permutation(tmp.begin(), tmp.end()))

}