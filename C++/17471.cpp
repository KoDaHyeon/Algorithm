#include <iostream>
#include <vector>

using namespace std;

void combination(int idx, int n, int r, int N)
{
    if (n == r){
        for (int i = 1; i <= N; i++){
	        if (Check[i] == true)
	        {
	            cout << Arr[i] << " ";
	        }
	    }
	    cout << endl;
        return;
    }
 
    for (int i = idx; i < MAX; i++)
    {
        if (Check[i] == true) continue;
        Check[i] = true;

        combination(i,n+1,r);
        Check[i] = false;
    }
}


int main()
{
  int N; //구역 개수
  cin >> N;
  int population[N+1]; //구역별 인구수
  vector<int> adjArea[N+1]; //각 구역과 인접한 구역 번호들
  for(int i=1; i<=N; i++){
    cin >> population[i];
  }
  for(int i=1; i<=N; i++){
    int adj; //그 구역과 인접한 구역수
    cin >> adj;
    for(int j=0; j<adj; j++){
      int area; //인접한 구역 번호
      cin >> area;
      adjArea[i].emplace_back(area);
    }
  }

  for(int i=1; i<=N/2; i++){
    /*NCi
    int denominator = 1; //분모
    int numerator = N; //분자
    for(int j=i; j>1; j--){
      denominator *= j;
    }
    for(int j=1; j<i; j++){
      numerator *= (N-j);
    }
    for(int j=1; j<=numerator/denominator; j++){
    }
    */
    
  }
}