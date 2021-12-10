#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
vector<int> included[10]; //이전에 존재한 수인지 확인
vector<int> arr;

int check(string now, int P, int n) { //현재수, 제곱수, 수열번호
  int next = 0; //다음 수
  vector<int> exIncluded; //현재 수의 숫자가 과거 몇 번째 수열번호에 출현했는지

  for(int i=0; i<now.size(); i++) {
    int num = now[i]-'0'; //5, 7(현재 수의 각 숫자)

    //중복 수인지 included에서 확인
    if(i == 0) {
      exIncluded = included[num]; //0,2,5
    } else {
      for(int j=0; j<exIncluded.size(); j++) {
        bool isExist = false;
        for(const auto & e : included[num]) {
          if(exIncluded[j] == e) { 
            isExist = true;
            break;
          }
        }
        if(!isExist) { 
          exIncluded.erase(exIncluded.begin()+j);
          j--;
        }
      }
    }

    //included에 저장
    included[num].emplace_back(n); //5, 7을 저장
    next += pow(num, P); //5^2+7^2
  }

  //현재 수가 중복수임
  if(!exIncluded.empty()) {
    return -exIncluded[0]; //-(중복수의 첫 출현 수열번호)
  }

  arr.emplace_back(next); //1에 74를 저장
  return next;
}

int main() {
  string A; //맨 처음 수
  int P; //제곱수
  int n = 0; //수열번호
  int result; //현재 수열 수 or 중복수의 첫 출현 수열번호
  
  cin >> A >> P;

  arr.emplace_back(A); //0에 57저장
  result = check(A, P, n); //74

  while(true) {
    n++;
    result = check(to_string(result), P, n);

    //반환값이 중복수의 첫 출현 수열번호이면
    if(result<0) {
      break;
    }
  }
  
  cout << -result + 1;
}