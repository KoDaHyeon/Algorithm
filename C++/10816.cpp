#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
  //입출력 많아서 이거 안넣으면 시간초과 나더라...
  ios::sync_with_stdio(false); 
  cin.tie(NULL);

  int cardCnt; //가지고 있는 숫자카드 개수
  int targetCnt; //찾는 숫자카드 종류수
  
  vector<int> card; //가지고 있는 숫자 카드

  cin >> cardCnt;
  card.resize(cardCnt);

  //카드 입력받기
  for(int i=0; i<cardCnt; i++) {
    cin >> card[i];
  }

  //카드 오름차순 정렬
  sort(card.begin(), card.end());

  //이진탐색
  cin >> targetCnt;
  for(int i=0; i<targetCnt; i++) {
    int target;
    int leftL, rightL, midL, leftU, rightU, midU;
    leftL = 0;
    rightL = cardCnt - 1;
    leftU = 0;
    rightU = cardCnt - 1;

    cin >> target;

    //lower_bound: target 이상값이 처음 나오는 위치
    while(leftL < rightL) {
      midL = (leftL + rightL) / 2;
      if(card[midL] >= target) {
        rightL = midL;
      } else {
        leftL = midL + 1;
      }
    }

    //upper_bound: target보다 큰 값이 처음 나오는 위치
    //맨 마지막 카드(제일 큰 카드)의 경우 더 큰 값을 찾지 못하고 마지막 카드의 위치가 rightU가 됨
    while(leftU < rightU) {
      midU = (leftU + rightU) / 2;
      if(card[midU] > target) {
        rightU = midU;
      } else {
        leftU = midU + 1;
      }
    }
    
    //{3} 에서 3 찾기
    //{3, 10, 10} 에서 10 찾기
    if(card[cardCnt-1] == target) {
      rightU++;
    }

    cout << rightU - rightL << ' ';

  } 
}