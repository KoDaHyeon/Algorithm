#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
 int N, K; //총 사람수, k번째 사람 제거
 cin >> N >> K;

 queue<int> round; //원형탁자에 앉아있는 사람
 for(int i=1; i<=N; i++){
   round.push(i);
 }

 cout << "<";
 while (!round.empty())
 {
   if(round.size() == 1){
     cout << round.front() << ">";
     break;
   }
   for(int i=1; i<K; i++){
     round.push(round.front());
     round.pop();
   }
   cout << round.front() << ", ";
   round.pop();
 }
 
}