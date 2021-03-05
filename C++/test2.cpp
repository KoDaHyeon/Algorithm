#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



/*
 * Complete the 'funWithAnagrams' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY text as parameter.
 */

vector<string> funWithAnagrams(vector<string> text) { //text: string들의 배열(벡터)

  //anagram들을 지운 남은 string들의 벡터 반환
  vector<string> result;
  vector< vector<int> > compare; //result배열에 있는 string의 알파벳 개수

  for(int i=0; i<text.size(); i++){
    string now = text[i]; //현재 검사 대상 string
    vector<int> compare_ele(26); //0으로 초기화된 각 알파벳별 개수
    for(int j=0; j<now.size(); j++){
      int idx = now[j]-'a'; //알파벳의 인덱스
      compare_ele[idx]++;
    } //now 문자열에 대해 알파벳수 배열 채움

    if(i == 0){
      result.emplace_back(now);
      compare.emplace_back(compare_ele);
    }
    else if(i > 0){
      bool isDifferent = true;
      for(int k=0; k<compare.size(); k++){ //compare배열과 비교해봄
        bool isAnagram = true;
        if(now.size() != result[k].size()){
          isAnagram = false;
        }
        else{
          for(int s=0; s<now.size(); s++){
            int idx = now[s] - 'a';
            if(compare[k][idx] != compare_ele[idx]){ //하나라도 다르면 break
              isAnagram = false;
              break;
            }
          }
        }
        if(isAnagram){
          isDifferent = false;
        } //Anagram이 나타나면 얘는 추가 못함
      }

      if(isDifferent){ //isDifferent가 true면 추가
        result.emplace_back(now);
        compare.emplace_back(compare_ele);
      }
    }
  }

  sort(result.begin(), result.end());

  return result;
  
}

int main()
{
  vector<string> s;
  vector<string> result;
  int n;
  cin >> n;
  for(int i=0; i<n; i++){
    string str;
    cin >> str;
    s.emplace_back(str);
  }

  result = funWithAnagrams(s);

  for(const auto &element : result){
    cout << element << '\n';
  }

  return 0;
}
