#include <iostream>
#include <vector>

using namespace std;

int main()
{
  int allPeople; //사람 수
  int allParty; //파티 수
  int knowTruth; //진실 아는 사람 수
  vector<int> hearTruth; //진실을 아는 사람 번호
  int lieParty = 0; //과장된 이야기 할 수 있는 파티 수

  cin >> allPeople >> allParty;
  vector<vector<int>> numList(allParty, vector<int>());

  cin >> knowTruth;
  for(int i=0; i<knowTruth; i++){
    int num;
    cin >> num;
    hearTruth.emplace_back(num);
  }


  for(int i=0; i<allParty; i++){
    int partyPeople;
    cin >> partyPeople;
    for(int j=0; j<partyPeople; j++){
      int num;
      cin >> num;
      numList[i].emplace_back(num);
    }
  }


  for(int i=0; i<allParty; i++){
    int partyPeople; //해당 파티 오는 사람 수
    //bool areTheyKnow = false; //파티의 한 사람이라도 진실을 아는지

    cin >> partyPeople;
    for(int j=0; j<partyPeople; j++){
      int num;
      cin >> num;
      numList.emplace_back(num);
      for(const auto &element : hearTruth){ //진실을 아는 경우 areTheyKnow=true
        if(num == element){
          areTheyKnow = true;
          break;
      }
    }

    if(areTheyKnow == true){ //한명이라도 진실을 알면 모두에게 진실을 말함
      for(const auto &element : numList){
        hearTruth.emplace_back(element);
      }
    }
    else{ //모두가 진실을 모르면 이 파티에서 과장된이야기 할 수 o
      lieParty++;
    } 
  }

  cout << lieParty;
}