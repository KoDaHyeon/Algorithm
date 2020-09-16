#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 32001;
int indegree[MAX]; //진입차선의 수
vector<int> list[MAX]; //순서관계
vector<int> result; //정렬한 결과


void arrange(int students)
{
  queue<int> indegree_zero; //진입차선 수가 0인 학생들

  for(int i=1; i<=students; i++){
    if(indegree[i] == 0)
      indegree_zero.push(i);
  }

  while(!indegree_zero.empty()){
    int now = indegree_zero.front(); //pop한걸 바로 now로 받아올 순 없음ㅠㅠ

    //큐에서 뺀 학생, 그 학생 뒤에 서야하는 학생들의 진입차수를 각각 1씩 감소
    for(int j=0; j<list[now].size(); j++){
      indegree[(list[now])[j]]--;
      if(indegree[(list[now])[j]] == 0) //진입차수==0이면 큐에 넣기
        indegree_zero.push((list[now])[j]);
    }
    indegree_zero.pop();
    result.emplace_back(now); //push_back보단 emplace_back쓰기
  }

  //정렬해둔 학생들 출력
  for(int i=0; i<students; i++){
    cout << result[i] << " ";
  }

}

int main()
{
  int students, M; //학생수, 비교횟수
  cin >> students >> M;

  for(int i=0; i<M; i++){
    int front, back;
    cin >> front >> back;
    list[front].emplace_back(back);
    indegree[back]++;
  }
  arrange(students);
}