#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
int len; //암호 길이
int cand; //후보 알파벳 개수
vector<char> arr; //후보 알파벳들
vector<char> cArr; //암호문
int cntM[15]; //자리별 총 모음 개수
int cntJ[15]; //자리별 총 자음 개수

void combination(int depth, int next) {

  if(depth == len && cntM[depth-1] >= 1 && cntJ[depth-1] >= 2) {
    for(const auto &e : cArr) {
      cout << e;
    }
    cout << '\n';
    return;
  }

  for(int i=next-1; i<cand; i++) {
    if(depth == 0) {
      cntM[0] = 0; //cnt배열 벡터로 두면 메모리초과남(이유는 모름..)
      cntJ[0] = 0;
    } else { //depth>0
        cntM[depth] = cntM[depth-1];
        cntJ[depth] = cntJ[depth-1];
    }

    switch(arr[i]) {
      case 'a': case 'e': case 'i':  case 'o': case 'u':
        cntM[depth]++;
        break;
      default: 
        cntJ[depth]++;
        break;
    }
    cArr[depth] = arr[i];
    combination(depth+1, i+2);
  } 
}

int main() {

  cin >> len >> cand;
  cArr.resize(len);
  arr.resize(cand);

  for(int i=0; i<cand; i++) {
    cin >> arr[i];
  }

  //후보 문자들 오름차순 정렬
  sort(arr.begin(), arr.end());

  combination(0,1);

}