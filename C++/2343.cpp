#include <iostream>
#include <vector>

using namespace std;
typedef long long ll;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int N;                  //강의 수
  int M;                  //블루레이 개수
  int size;               //블루레이 최소 사이즈
  vector<int> classLen;   //강의 길이
  vector<ll> classLenSum; //강의 길이 합 벡터
  int sum = 0;            //강의 길이 합
  int max = 0;

  cin >> N >> M;
  classLen.resize(N);
  classLenSum.resize(N);

  for (int i = 0; i < N; i++)
  {
    int len;
    cin >> len;
    classLen[i] = len;
    sum += len;
    classLenSum[i] = sum;
    max = max < len ? len : max;
  }

  ll left = max;
  ll right = classLenSum[N - 1];
  ll mid;

  while (left < right)
  {
    int blurayCnt = 1;
    ll exSum = 0;

    mid = (left + right) / 2; //블루레이 크기 후보

    //조건 만족 체크
    for (int i = 0; i < N; i++)
    {
      if (classLenSum[i] > mid + exSum)
      {
        blurayCnt++;
        exSum = classLenSum[i - 1];
      }
    }

    if (blurayCnt <= M) //이 블루레이 크기 ok
    {
      right = mid;
    }
    else // not ok
    {
      left = mid + 1;
    }
  }
  cout << left;
}