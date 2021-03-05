#include <iostream>
#include <string>
using namespace std;

string inputSigns; //입력받은 부등호 문자열

int findMAX(int num, int signIdx)
{
  switch(inputSigns[signIdx]){
    case '>':
      for(int i=1; i<=num; i++){
        if(choosed[num-i] == false){
          choosed[num-i] = true;
          findMAX(num-i, signIdx+1);
          break;
        }
      }

    case '<':
      if(choosed[num+1] == false){
        choosed[num+1] = true;
        findMAX(num+1, signIdx+1);
      }
    default: 
  }
}


int main()
{
  int signs; //부등호 개수
  cin >> signs;
  for(int i=0; i<signs; i++){
    char c;
    cin >> c;
    inputSigns.push_back(c);
  }
  int idx=0; //부등호 인덱스
  for(int i=9; i>=0; i--){
    findMAX(i, idx); //반환한 int를 문자열로 바꿔야 함
  }
}