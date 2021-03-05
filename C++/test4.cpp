#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int perfectSubstring(string s, int k) {
  vector<vector<int>> count(s.size(), vector<int>(10,0));
  //vector<vector<int>> notZero(s.size(), vector<int>()); //지금까지 출몰한 숫자들
  int result = 0; //perfect substring 개수

  count[0][s[0]-'0']++;

  for(int i=1; i<s.size(); i++){
    int num = s[i] - '0';
    //cout << "num: " << num << '\n';
    count[i] = count[i-1];
    count[i][num] += 1; //i번째에서 입력string의 i번째숫자 개수
    //cout << "count[" << i << "][" << num << "]: " << count[i][num] << '\n';
  }


//i번째에 출몰한 총 숫자개수 = i+1개
  for(int i=0; i<s.size()-(k-1); i++){ //시작
    for(int j=i+(k-1); j<s.size(); j++){ //끝
      if((j-i+1)%k != 0){ //개수가 안맞으면 애초에 불가능
        continue;
      }

      bool isPerfect = true;
      for(int p=0; p<10; p++){
        int nowCnt;
        if(i==0){
          nowCnt = count[j][p];
        }
        else{
          nowCnt = count[j][p] - count[i-1][p];
        }
        if(nowCnt == 0) continue;
        //cout << i << ":start " << j << ":end " << p << ":num " << " nowCnt : " << nowCnt << '\n';
        //cout << "nowCnt: " << nowCnt << "  k: " << k <<'\n';
        if(nowCnt != k){//수정
          isPerfect = false;
          //cout << "not Perfect\n";
          break;
        }
      }
      if(isPerfect){
        result++;
      }
    }
  }

  return result;
}

int main()
{
  string s;
  int k;
  cin >> s;
  cin >> k;
  int result = perfectSubstring(s, k);
  cout << result;

}
