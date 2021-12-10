#include <iostream>
#include <algorithm>

using namespace std;

int minCnt[1000001];

int main() {
  int input;
  cin >> input;
  
  for(int i=2; i<=input; i++) {
    minCnt[i] = minCnt[i-1] + 1;
    if(i%3 == 0) {
      minCnt[i] = min(minCnt[i], minCnt[i/3] + 1);
    }
    if(i%2 == 0) {
      minCnt[i] = min(minCnt[i], minCnt[i/2] + 1);
    }
  }
  cout << minCnt[input];
}


/* 문제점 : 메모리 초과 - 각 수당 배열칸이 3개씩 생겨서 수가 엄청 크면 메모리 초과
#include <iostream>

using namespace std;

int minCnt;

void dp(int n, int cnt) {
  int arr[3] = {n,n,n};

  if(arr[0] % 3 == 0) { 
    arr[0] /= 3; //10
  }
  if(arr[1] % 2 == 0) {
    arr[1] /= 2; //5
  }
  arr[2] -= 1; //9

  for(int i=0; i<3; i++) {
    if(arr[i] == 1) {
      //1 도달하고 반환하고 끝남
      cout << i << ':' << cnt << '\n';
      if(cnt < minCnt) {
        minCnt = cnt;
      }
      cout << "minCnt: " << minCnt << '\n';
      return;
    }
    if(arr[i] != n) { //값이 바뀌었고 1이 아니면
      if(minCnt == cnt) { //더이상 실행할 가치가 x
        break;
      }
      dp(arr[i], cnt+1); //dp(5,2)
    }
  }

}



int main() {
  int input;

  cin >> input;
  minCnt =  input-1; //최대값
  dp(input, 1);
  cout << minCnt;
}
*/