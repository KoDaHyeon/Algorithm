#include <iostream>
#include <string>
#include <vector>

using namespace std;

string solution(string new_id) {
    string answer = new_id;
    for(int i=0; i<answer.size(); i++){
      //대문자->소문자
      if('A'<=answer[i] && answer[i] <= 'Z'){
        answer[i] = tolower(answer[i]);
      }
      //특수문자 제거
      else if('a'<=answer[i] && answer[i] <='z'){
        continue; //소문자이면 pass
      }
      else if('0'<=answer[i] && answer[i] <='9'){
        continue; //숫자이면 pass
      }
      else if(answer[i]=='-' || answer[i]=='_' || answer[i]=='.'){
        continue; //가능한 특수문자이면 pass
      }
      else {
       answer.erase(i,1); //이외 특수문자 삭제
       i--;
      }
    }
    cout << "level 1,2: " << answer <<'\n';

    //연속 . 제거
    int dotCnt = 0;
    int dotStart;
    for(int i=0; i<answer.size(); i++){
      if(answer[i] == '.'){ //현재문자가 .임
        if(dotCnt==0){
          dotStart = i;
        }
        dotCnt++;

      }
      else{ //현재문자가 .가 아님
        if(dotCnt>=2){
          answer.erase(dotStart, i-1-dotStart); //연속 . 제거
          i = 2 + dotStart;
          //.가 처음/끝에 있다면 제거
          if(i == 1){
            
          }
        }
        dotCnt = 0;
      }
    }
    cout << "level 3: " << answer <<'\n';
    
    return answer;
}


int main()
{
  string input = "...!@BaT#*..y.abcdefghijklm";
  cout << solution(input);
}