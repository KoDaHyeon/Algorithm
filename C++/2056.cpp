#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX = 10000 + 1;
vector<int> list[MAX]; //선행관계 담을 리스트(각 번호마다 후행해야할 작업번호가 달려있음)
int time[MAX];         //각 작업마다 걸리는 시간
int indegree[MAX];     //선행해야할 작업 개수

void get_total_time()
{
    vector<int> indegree_zero; //편의상 큐라고 지칭

    //선행작업수 0 인 작업번호를 벡터에 넣기
    for (int i = 1; i <= MAX - 1; i++)
    {
        if (indegree[i] == 0)
            indegree_zero.emplace_back(i);
    }

    int min_time;       //최소 작업시간
    int total_time = 0; //총 필요한 최소시간

    while (indegree_zero.size() != 0)
    {
        //min_time 조사
        for (int i = 0; i < indegree_zero.size(); i++)
        {
            if (i == 0)
            {
                min_time = time[indegree_zero[i]];
            }
            else if (min_time > time[indegree_zero[i]])
            {
                min_time = time[indegree_zero[i]];
            }
        }

        total_time += min_time; //total_time += 먼저끝나는 애의 시간
        vector<int> tmp; //후행관계 작업들 중 indegree==0인 애들(큐에 넣을 애들)

        for (int i = 0; i < indegree_zero.size(); i++) //큐에있는 다른 작업들 time을 각각 먼저끝나는애의 시간만큼 뺌(동시실행한다고 생각)
                                                       //size는 자동으로 업뎃됨
        {
            time[indegree_zero[i]] -= min_time;

            if (time[indegree_zero[i]] == 0)
            {
                for (int j = 0; j < list[indegree_zero[i]].size(); j++) //먼저끝난 작업, 그 후행관계 작업들 indegree--;
                {
                    indegree[(list[indegree_zero[i]])[j]]--;
                    if (indegree[(list[indegree_zero[i]])[j]] == 0) //먼저끝난 작업의 후행관계 작업들중 indegree==0인 애들 따로 보관
                        tmp.emplace_back((list[indegree_zero[i]])[j]);
                }
                indegree_zero.erase(indegree_zero.begin() + i); //먼저끝난 작업 큐에서 삭제
                i--; //erase하면 원소가 하나씩 앞으로 밀리기 때문에
            }
        }

        for(int i=0; i<tmp.size(); i++){
            indegree_zero.emplace_back(tmp[i]); //새롭게 indegree==0이 된 애들 큐에 추가
        }
        tmp.clear();

    //큐에 작업이 여러개면 각자 time조사후 먼저끝나는 애가 있으면 total_time += 먼저끝나는 애의 시간
    //큐에있는 다른 작업들 time을 각각 먼저끝나는애의 시간만큼 뺌(동시실행한다고 생각)
    //먼저끝난 작업, 그 후행관계 작업들 indegree--;
    //먼저끝난 작업을 큐에서 뺌
    //먼저끝난 작업의 후행관계 작업들중 indegree==0인 애들 큐에 넣음
    //위 작업 반복
    }

    cout << total_time;
}

int main()
{
    int N; //총 작업수

    //입력 받기
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        int info; //각 작업에 대해 받아온 정보를 담을 변수
        int cnt = 1;
        do
        {
            cin >> info;
            if (cnt == 1)
                time[i] = info; //걸리는 시간
            if (cnt == 2)
                indegree[i] = info; //선행해야할 작업 개수
            if (cnt >= 3)
                list[info].emplace_back(i); //선행관계 담은 리스트
            cnt++;
        } while (getc(stdin) == ' ');
    }
    //list 업뎃, indegree 업뎃, time 업뎃한 상태

    get_total_time();
}