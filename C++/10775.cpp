#include <iostream>
#include <vector>
//값
//[a][b] a층 b번째 원소까지 선택한 값 벡터

using namespace std;

int main()
{
  int gates;
  int planes;
  int gateList[100001]; //gi 넣어두는 배열

  cin >> gates;
  cin >> planes;
  for(int i=1; i<=planes; i++){
    cin >> gateList[i]; //1~gi게이트 가능
  }
}