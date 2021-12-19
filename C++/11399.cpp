#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
  int N; //사람 수
  int need = 0; //필요한 시간
  vector<int> time;

  cin >> N;
  time.resize(N);

  //인출시간 입력받기
  for(int i=0; i<N; i++) {
    cin >> time[i];
  }

  //인출시간 오름차순 정렬
  sort(time.begin(), time.end());

  int now = N;
  for(int i=0; i<N; i++) {
    need += time[i] * now;
    now--;
  }

  cout << need;
}