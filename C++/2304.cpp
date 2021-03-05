#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
  int pillars; //기둥 수
  vector< pair<int,int> > sorted; //왼쪽좌표 오름차순 정렬된 벡터
  int area = 0; //면적
  int max_height = 0; //최고 기둥 높이
  vector<int> max_left; //최고 기둥 높이의 왼쪽좌표

  cin >> pillars;
  sorted.resize(pillars);

  for(int i=0; i<pillars; i++){
    int loc; //왼쪽면 위치
    int h; //높이
    cin >> loc >> h;
    if(h > max_height){
      max_height = h;
    }
    pair<int,int> pillar = make_pair(loc, h);
    sorted[i] = pillar;
  }

  cout << "max_height: " << max_height <<'\n';

  for(int i=0; i<pillars; i++){
    if(sorted[i].second == max_height){
      max_left.emplace_back(sorted[i].first);
      cout << sorted[i].first << '\n';
    }
  }

  sort(sorted.begin(), sorted.end()); //오름차순 정렬
  sort(max_left.begin(), max_left.end());

  int tmp_left = sorted[0].first; //현재까지 최고높이 왼쪽좌표
  int tmp_height = sorted[0].second; //현재까지 최고높이
  area += sorted[0].second;

  for(int i=1; sorted[i].second <= max_height; i++){
    if(sorted[i].second > tmp_height){
      area += (sorted[i].first - tmp_left - 1) * tmp_height;
      cout << "area1: " << area << '\n';
      tmp_height = sorted[i].second;
      tmp_left = sorted[i].first;
      area += tmp_height;
      cout << "area2: " << area <<'\n';
    }
    if(sorted[i].second == max_height){
      area -= max_height;
      break;
    }
  } //max_height 전까지 area 계산


  tmp_left = sorted.back().first;
  tmp_height = sorted.back().second;
  area += sorted.back().second;
  cout << area << '\n';

  cout << sorted[(sorted[pillars-2].first)].second << '\n';

  for(int i=sorted[pillars-2].first; sorted[i].second <= max_height; i--){
    
    if(sorted[i].second > tmp_height){
      area += (tmp_left - sorted[i].first - 1) * tmp_height;
      cout << "area1 : "<< area << '\n';
      tmp_left = sorted[i].first;
      tmp_height = sorted[i].second;
      area += tmp_height;
      cout << "area2 : " << area << '\n'; 
    }
    if(sorted[i].second == max_height){
      area -= tmp_height;
      break;
    }
  }

  cout << "max:" << max_height;
  area += (max_left.back() - max_left.front() + 1 ) * max_height;

  cout << area;
  
}