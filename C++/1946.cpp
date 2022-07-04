#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

//그리디는 최대한 계산수를 줄이도록 - 특히 for문으로 배열 여러번 탐색했는데 시간초과 나온다? 풀이 자체를 뒤엎어야 할 확률이 큼! 배열을 한번만 탐색하도록
//현재 단계에서 가장 좋은 해를 선택하다보면 전체에서 가장 좋은 해가 나옴(최적해) - 최적해가 보장되는 경우에만
//대부분의 경우 그리디 알고리즘으로 최적해를 구하지 못한다. 따라서 감으로..
// 1. 관찰을 통해 탐색 범위를 줄이는 방법!!!!을 고안한다(특히 배열의 경우 여러번 탐색 대신 한 번만 탐색할 수 있지 않을까)
// 2. 탐색 범위를 줄여도 ㄱㅊ을것같으면 해본다.
//알려진 그리디 알고리즘을 잘 이해하고 사용
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int test; //테스트 케이스 수
  cin >> test;
  //각 테스트 케이스
  for (int i = 0; i < test; i++)
  {
    int people;    //지원자 수
    int count = 1; //합격자 수

    cin >> people;
    vector<pair<int, int>> rankList(people); //(서류등수, 면접등수) 형 벡터

    for (int j = 0; j < people; j++)
    {
      cin >> rankList[j].first >> rankList[j].second; //등수 입력받기
    }

    // first 기준 오름차순 정렬
    sort(rankList.begin(), rankList.end());

    int temp = rankList[0].second; //기준 면접순위

    for (int p = 1; p < rankList.size(); p++)
    {
      if (rankList[p].second < temp)
      {
        // first는 당연히 열등함. second만 비교하는데 second가 우등하면 p는 선발
        temp = rankList[p].second;
        count++;
      }
    }
    cout << count << "\n";
  }
}
