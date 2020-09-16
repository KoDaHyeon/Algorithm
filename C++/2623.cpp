#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 1001;
int indegree[MAX];
vector<int> list[MAX];
vector<int> result;

void arrange(int singer)
{
    queue<int> indegree_zero;
    //큐에 넣기
    for(int i=1; i<=singer; i++){
        if(indegree[i] == 0)
            indegree_zero.push(i);
    }

    //큐에서 하나씩 빼고, 그 뺀 번호의 list의 벡터에 딸려있는 번호들 indegree--;
    while(!indegree_zero.empty()){
        int now = indegree_zero.front();

        for(int j = 0; j < list[now].size(); j++){
            indegree[(list[now])[j]]--;
            if(indegree[(list[now])[j]] == 0)
                indegree_zero.push((list[now])[j]);
        }
        indegree_zero.pop();
        result.emplace_back(now);
    }

    if(result.size() == singer){
        for(int i=0; i<singer; i++){
            cout << result[i] << "\n";
        }
    }
    else cout << 0;
}

int main()
{
    int singer, PD;
    cin >> singer >> PD; //가수 수, 보조PD 수

    for(int i=0; i<PD; i++){

        int order, cnt;
        vector<int> orderByPD;

        do{
            cin >> order;
            orderByPD.emplace_back(order); //orderByPD에 PD픽 가수순서 저장
        }while(getc(stdin) == ' ');

        orderByPD.erase(orderByPD.begin()); //가수 수 지우기

        //각각 진입차수 +1
        //두개씩 list에 전후관계 추가
        for(int i=0; i<orderByPD.size(); i++){
            if(i > 0)
                indegree[orderByPD[i]]++;
            if(i < orderByPD.size()-1)
                list[orderByPD[i]].emplace_back(orderByPD[i+1]);
        }
    }

     arrange(singer);
}
