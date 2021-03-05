#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int buildings; //빌딩 수
  vector<int> height; //빌딩별 높이
  vector<int> can_see; //볼 수 있는 빌딩 수

  cin >> buildings;
  height.assign(buildings, 0);
  can_see.assign(buildings, 0);
  for(int i=0; i<buildings; i++){
    cin >> height[i];
  }

  for(int base=0; base<buildings-1; base++){

    pair<int, int> lastest = make_pair(base,height[base]);

    for(int target=base+1; target<buildings; target++){
      if (target == base + 1){
        lastest.first = target;
        lastest.second = height[target];
        can_see[target]++;
        can_see[base]++;
        continue;
      }

      double x1 = lastest.first - base;
      double x2 = target - base;
      double y1 = lastest.second - height[base];
      double y2 = height[target] - height[base];

      if (y1/x1 < y2/x2){ //볼수있는 빌딩
        lastest.first = target;
        lastest.second = height[target];
        can_see[target]++;
        can_see[base]++;
      }
    }
  }

  int max = can_see[0];
  for(const auto &element : can_see){
    if(element > max){
      max = element;
    }
  }
  cout << max;
  
}