#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int main()
{
  string n;
  long long count[10] = {0,}; //0~9의 개수
  cin >> n;
  int len = n.size(); //7
  for(int idx=0; idx<len; idx++){
    int first = n[idx]; //현재 자리의 숫자

    //1~999999
    for(int i=1; i<=len-1; i++){ //최대자리수가 1, 2, ..., 6
      for(int j=0; j<10; j++){ //j는 count의 인덱스(0~10)
        if(j==0){
          if(i!=1){
            count[j] += pow(10,i-2) * 9 * (len-1);
          }
        }
        else{
          if(i==1){
            count[j] += 1;
          }
          else{
            count[j] += pow(10,i-2) * 9 * (len-1) + pow(10,len-1);
          }
        }
      }
    }

    for(int j=0; j<10; j++){ //1000000~6999999
      count[j] += pow(10,len-2) * (first-1); //first-1은 제일 큰자리수에 가능한 숫자개수
      if(1<=j && j<=first-1){
        count[j] += pow(10,first-1);
      }
    }


  }
}