#include <iostream>
#include <vector>

using namespace std;

// dp의 포인트는 최대한 중복되는 부분을 구해서 이전에 계산한 값(저장해둠)을 사용한다는것!
// 매번 값을 계산하는게 아니라 이전에 계산한 값을 사용해서 계산을 최소화함
//중복을 찾고 - 관계식을 세우고 - 메모이제이션(중복값을 저장해둬서 다시 계산하지 않고 사용)

int main()
{
  int count = 0; //오르막 수 개수
  int n;
  vector<vector<int>> dp;

  cin >> n;
  dp.resize(n + 1, vector<int>(10, 0));

  for (int i = 0; i <= 9; i++)
  {
    dp[1][i] = 1;
  }

  for (int i = 2; i <= n; i++)
  {
    dp[i][9] = 1;
    for (int j = 8; j >= 0; j--)
    {
      //저장할때마다 나머지 연산 해주는게 포인트!!! 안그러면 수가 너무 커져서 저장이 제대로 안됨
      //나는 저장은 그대로 하고 밑에 count 덧셈할 때만 나머지 연산 해줬는데 그러면 틀림
      dp[i][j] = (dp[i][j + 1] + dp[i - 1][j]) % 10007;
    }
  }

  for (int j = 0; j <= 9; j++)
  {
    count = count + dp[n][j];
  }

  //덧셈 결과로 다시 10007의 배수가 될 수도 있으니 10007로 다시 한번 나머지 연산
  cout << count % 10007;
}