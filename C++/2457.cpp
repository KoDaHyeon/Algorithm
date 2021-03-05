#include <iostream>
#include <vector>

using namespace std;

struct Flower
{
  pair<int,int> blossom; //(피는 시작날, 피는 마지막날) 
};

int flowers; //꽃 종류 수
vector<Flower> info; //꽃 피는, 지는 날짜


int getDay(int month, int date)
{
  int day = 0;
  for(int i=1; i<month; i++){
    switch(i){
      case 1: case 3: case 5: case 7: case 8: case 10: case 12:
        day += 31;
        break;
      case 4: case 6: case 9: case 11:
        day += 30;
        break;
      case 2:
        day += 28;
        break;
      default: break;
    }
  }
  day += date;

  return day;
}


int match(int start, int end) //커버해야하는(피어있어야 하는) 시작날, 마지막날
{
  vector<Flower> cover_start;
  vector<Flower> cover_end;
  Flower tmp = {make_pair(0,0)};
  cover_start.emplace_back(tmp); //하나의 꽃이 모든 범위를 커버할때 매칭할 것
  cover_end.emplace_back(tmp);

  for(int i=0; i<info.size(); i++){
    if(info[i].blossom.first <= start && info[i].blossom.second >= start){
      cover_start.emplace_back(info[i]);
    }
    else if(info[i].blossom.first <= end && info[i].blossom.second >=end){
      cover_end.emplace_back(info[i]);
    }
  }

  int min_flowers = flowers; //최소 꽃 개수

  for(int i=0; i<cover_start.size(); i++){
    for(int j=0; j<cover_end.size(); j++){
      int new_start, new_end, need_flowers = 0;

      if(cover_start[i].blossom.first == 0 && cover_end[j].blossom.first == 0){
        continue;
      }
      else if(cover_start[i].blossom.first == 0){
        new_start = start;
        new_end = cover_end[j].blossom.first-1;
        need_flowers++;
      }
      else if(cover_end[j].blossom.first == 0){
        new_start = cover_start[i].blossom.second+1;
        new_end = end;
        need_flowers++;
      }
      else{
        new_start = cover_start[i].blossom.second+1;
        new_end = cover_end[j].blossom.first-1;
        need_flowers += 2;
      }

      if(new_start == start && new_end == end){
        continue;
      }

      if (new_start > new_end){
        //다 커버한것!
      }
      else{
        need_flowers += match(new_start, new_end);
      }

      if(need_flowers < min_flowers){
        min_flowers = need_flowers;
      }

    }
  }
  return min_flowers;
}

int main()
{

  ios::sync_with_stdio(false); 
  cin.tie(NULL);
  cin >> flowers;
  info.resize(flowers);

  for(int i=0; i<flowers; i++){
    int start_m, start_d, end_m, end_d; //꽃 피는 월/일, 지는 월/일
    cin >> start_m >> start_d >> end_m >> end_d;
    info[i].blossom.first = getDay(start_m, start_d); //꽃피는 시작날
    info[i].blossom.second = getDay(end_m, end_d)-1; //꽃피는 마지막날
  }

  cout << match(getDay(3,1), getDay(11,29));

}