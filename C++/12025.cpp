#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
  string changed; //바뀐 비밀번호
  vector<int> changed_index; //1,2,6,7의 인덱스
  long long k; //k
  cin >> changed;
  cin >> k;
  string start = changed;

  for(long long i=0; i<changed.size(); i++){
    if(changed[i] == '1' || changed[i] == '6'){
      changed_index.emplace_back(i);
      start[i] = '1';
    }
    else if(changed[i] == '2' || changed[i] == '7'){
      changed_index.emplace_back(i);
      start[i] = '2';
    }
  }


  //이진수 자릿수:changed_index.size()
  //k번째 = 이진수에서 k-1

  if(k > pow(2,changed_index.size())){
    cout <<-1;
    return 0;
  }

  //k를 2진수로 변환
  k = k-1;
  long long binary[changed_index.size()] = {0,};
  long long binary_now = changed_index.size()-1;
  while(1){
    binary[binary_now] = k%2;
    k /= 2;
    binary_now--;
    if(k == 0){ break; }
  }


  for(long long i=0; i<changed_index.size(); i++){
    if(binary[i] == 1){
      if(start[changed_index[i]] == '1'){
        start[changed_index[i]] = '6';
      }
      else if(start[changed_index[i]] == '2'){
        start[changed_index[i]] = '7';
      }
    }
  }

  cout << start;


}