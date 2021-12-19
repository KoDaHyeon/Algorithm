#include <iostream>
#include <vector>

using namespace std;
typedef pair<int,int> P;
vector< vector<int> > color;
int blueCnt = 0;
int whiteCnt = 0;

void cut(int x, int y, int size) { //시작점x, 시작점y, 크기
  //배열을 처음부터 조회
  int now = color[x][y]; //맨 처음 색
  bool isSame = true;

  for(int i=x; i<x+size; i++) {
    for(int j=y; j<y+size; j++) {
      if(color[i][j] != now) {
        //숫자가 하나라도 다르면
        isSame = false;
        break;
      }
    }
  }
  if(isSame) {
    if(now == 1) {
      blueCnt++;
    } else {
      whiteCnt++;
    }
  } else {
    cut(x, y, size/2);
    cut((2*x+size-1)/2+1, y, size/2);
    cut(x, (2*y+size-1)/2+1, size/2);
    cut((2*x+size-1)/2+1, (2*y+size-1)/2+1, size/2);
  }
}

int main() {
  int N; //전체 종이 변 길이

  cin >> N;
  color.resize(N, vector<int>(N,0));

  //배열 채우기
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
      cin >> color[i][j];
    }
  }

  cut(0, 0, N);
  cout << whiteCnt << '\n' << blueCnt;
}