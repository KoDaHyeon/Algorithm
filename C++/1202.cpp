#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

int main()
{
  int jewelries; //보석 개수
  int bags; //가방 개수
  priority_queue< pair<int,int>, vector< pair<int,int> >, less< pair<int,int> > > canSteal; //각 보석 가격, 무게
  vector<int> bag_weight; //각 가방 허용 최대무게
  vector< pair<int,int> > jewel; //각 보석 무게, 가격
  long long total = 0; //훔칠 수 있는 최대 가격

  ios::sync_with_stdio(false); 
  cin.tie(NULL);

  cin >> jewelries >> bags;
  bag_weight.resize(bags);
  jewel.assign(jewelries, make_pair(0,0));

  for(int i=0; i<jewelries; i++){
    int cost;
    int weight;
    cin >> weight >> cost;
    jewel[i] = make_pair(weight, cost);
  }

  for(int i=0; i<bags; i++){
    cin >> bag_weight[i];
  }

  sort(bag_weight.begin(), bag_weight.end()); //가방 무게 오름차순 정렬
  sort(jewel.begin(), jewel.end()); //보석 무게 오름차순 정렬

  int idx = 0;

  for(int i=0; i<bags; i++){
    while(jewel[idx].first <= bag_weight[i] && idx < jewelries){
      int weight = jewel[idx].first;
      int cost = jewel[idx].second;
        
      canSteal.push(make_pair(cost, weight));
      idx++;
    }
    if(!canSteal.empty()){
      int max_cost = canSteal.top().first;
      canSteal.pop();
      total += max_cost;
    }
  }

  cout << total;

}