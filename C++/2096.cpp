#include <iostream>

using namespace std;

int main()
{
  int n;
  int max_route[3]; //첫번째, 두번째, 세번째 원소까지의 최대점수
  int min_route[3]; ////첫번째, 두번째, 세번째 원소까지의 최소점수
  cin >> n;
  for(int i=0; i<n; i++){
    int a, b, c;
    cin >> a >> b >> c;
    if(i==0){ //1층
      max_route[0] = a;
      max_route[1] = b;
      max_route[2] = c;

      min_route[0] = a;
      min_route[1] = b;
      min_route[2] = c;
    }
    else{ //2층이상
      int new_max[3];
      int new_min[3];
      int tmp;

      new_max[0] = a + (max_route[0]>max_route[1]? max_route[0] : max_route[1]); //해당 층의 첫번째원소까지의 최대 점수
      tmp = max_route[0]>max_route[1] ? max_route[0] : max_route[1];
      new_max[1] = b + (tmp>max_route[2]? tmp : max_route[2]);
      new_max[2] = c + (max_route[1]>max_route[2]? max_route[1] : max_route[2]);

      new_min[0] = a + (min_route[0]<min_route[1]? min_route[0] : min_route[1]);
      tmp = min_route[0]<min_route[1] ? min_route[0] : min_route[1];
      new_min[1] = b + (tmp<min_route[2]? tmp : min_route[2]);
      new_min[2] = c + (min_route[1]<min_route[2]? min_route[1] : min_route[2]);

      for(int j=0; j<3; j++){
        max_route[j] = new_max[j];
        min_route[j] = new_min[j];
      }
    }
  }

  int max = max_route[0];
  int min = min_route[0];
  for(int i=1; i<3; i++){
    if(max_route[i] > max){
      max = max_route[i];
    }
    if(min_route[i] < min){
      min = min_route[i];
    }
  }
  cout << max << ' ' << min;
}