#include <iostream>

using namespace std;

/* 규칙찾기
int main()
{
  int rocks; //돌 개수
  cin >> rocks;
  bool isWin[101];
  for(int i=1; i<101; i++){
    switch(i){
      case 1 : isWin[i] = true; break;
      case 2 : isWin[i] = false; break;
      case 3 : isWin[i] = true; break;
      case 4 : isWin[i] = true; break;
      default : isWin[i] = (!isWin[i-1] || !isWin[i-3] || !isWin[i-4]);
                if(isWin[i] == false){
                  cout << i << ":" << isWin[i] << '\n';
                }
                break;
    }
  }
}
*/

int main()
{
  long long rocks;
  cin >> rocks;
  if((rocks%7 == 0) || (rocks%7 == 2)){
    cout << "CY";
  }
  else cout << "SK";
}