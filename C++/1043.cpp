#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int people; //사람 수
  int parties; //파티 수
  int truths; //진실아는 사람 수
  vector<int> truth_v; //진실 아는 사람 번호
  vector<int> adj[51]; //그래프
  vector<int> par
  cin >> people >> parties;
  cin >> truths;
  truth_v.resize(truths);
  for(int i=0; i<truths; i++){
    cin >> truth_v[i];
  }
  for(int i=0; i<parties; i++){
    int party_people;
    cin >> party_people;
    for(int i=0; i<party_people; i++){
      int num;
      cin >> num;
      adj[num]
    }
  }

}