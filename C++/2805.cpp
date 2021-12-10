/**
 * 나무 자르기
**/

#include <iostream>
#include <vector>

using namespace std;

int main() {
  int trees; //나무의 수
  int needs; //가져가려는 나무 총 길이
  vector<int> len; //각 나무의 높이
  int left, right, mid; //left, right, mid(절단높이)
  int maxLen = 0; //최대 나무 높이
  int H; //절단 높이

  cin >> trees >> needs;
  len.resize(trees);

  for(int i=0; i<trees; i++) {
    cin >> len[i];
    if(len[i] > maxLen) {
      maxLen = len[i];
    }
  }

  left = 0;
  right = maxLen;

  while(left<=right) {
    long long take = 0; //수확
    mid = (left + right) / 2;

    //수확
    for(const auto &e : len) {
      if(e > mid) {
        take += (e - mid);
      }
    }

    if(take < needs) {
      right = mid - 1;
    } else if(take == needs) {
      H = mid;
      break;
    } else { //take > needs
      H = mid;
      left = mid + 1;
    }

  }
  cout << H;
}