#include "GetInput.h"
//n입력받아서 정의하고, input도 정의해둬야 함
//perceptron이나 main에서 여기에 있는 n, input을 가져다가 사용

using namespace std;

int n;
extern std::vector<std::vector<int>> input;


void getInput()
{
  //n 입력받고 초기화
  cin >> n;

  //input 값 초기화
  //input[i][0]=x1, input[i][1]=x2, x0=-1
  input.assign(pow(2,n), vector<int>(n, 0));
  for(int i=0; i<pow(2,n); i++){
    for(int now=n-1, j=0; now>=0 && j<n; now--, j++){
      if(i & (1 << now)) //i의 now번째 비트가 1이라면
        input[i][j] = 1;
      else input[i][j] = 0;
    }
  }

}