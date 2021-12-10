#include <iostream>

using namespace std;

int cnt[1001];

int main() {
  int n;
  cin >> n;

  cnt[0] = 1;
  cnt[1] = 1;

  for(int i=2; i<=n; i++) {
    cnt[i] = (cnt[i-1] + cnt[i-2]) % 10007;
  }

  cout << cnt[n];
}