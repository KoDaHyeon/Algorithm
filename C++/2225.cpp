#include <iostream>

using namespace std;
const int MAX = 200;
int cnt[MAX+1][MAX+1]; //[K][N] : K개의 정수로 합이 N인 경우의 수 //0~200


int main() {
  int N; //0~N, 합이N
  int K; //K개의 정수
  int result;

  cin >> N >> K;

  for(int k=1; k<=MAX; k++) {
    cnt[k][0] = 1;
  }

  for(int k=1; k<=K; k++) {
    for(int n=1; n<=N; n++) {
      cnt[k][n] = (cnt[k][n-1] + cnt[k-1][n]) % 1000000000;
      //(a+b)%c = (a%c + b%c)%c
    }
  }

  cout << cnt[K][N];

}