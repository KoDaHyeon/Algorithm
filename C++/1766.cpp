#include <iostream>
#include <vector>
#include <queue>

using namespace std;
const int MAX = 32001;
int indegree[MAX];
vector<int> list[MAX];

void arrange(int problem)
{
    priority_queue< int, vector<int>, greater<int> > indegree_zero; //최소부터 반환하는 우선순위 큐

    //진입차선수가 0인 애들 큐에 넣기
    for(int i=1; i<= problem; i++){
        if(indegree[i] == 0)
            indegree_zero.push(i);
    }

    while(!indegree_zero.empty()){
        int now = indegree_zero.top(); //큐에서 최소인 문제번호
        indegree_zero.pop();

        //indegree_zero에서 pop한 문제를 선행해야 풀수있는 문제들의 indegree--; 
        for(int j=0; j<list[now].size(); j++){
            indegree[(list[now])[j]]--;
            if(indegree[(list[now])[j]] == 0)
                indegree_zero.push((list[now])[j]);
        }
        cout << now << " ";
    }

}

int main()
{
    int problem, order; //문제 수, 먼저푸는문제정보 수
    cin >> problem >> order;

    //선후관계 정보 받기
    for(int i=0; i<order; i++){
        int front, back;
        cin >> front >> back;
        indegree[back]++;
        list[front].emplace_back(back);
    }

    arrange(problem);
}