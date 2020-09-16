#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int test_cnt; //테스트 케이스 개수
    cin >> test_cnt;
    vector<vector<int>> result; //최종 순위
    vector<int> result_ele;     //각 테스트케이스 별로 최종순위

    //테스트케이스 개수만큼 할당
    for (int i = 0; i < test_cnt; i++)
    {
        result.emplace_back(result_ele);
    }

    for (int i = 0; i < test_cnt; i++)
    {
        int team_cnt;     //팀의 수
        vector<int> rank; //순위대로 팀번호를 저장할 벡터
        cin >> team_cnt;
        vector<int> list[team_cnt + 1]; //해당 팀 뒤에 오는 팀들 리스트
        int indegree[team_cnt + 1];     //진입차선 수

        //rank에 순위대로 팀번호를 저장
        int tmp;
        do
        {
            cin >> tmp;
            rank.emplace_back(tmp);
        } while (getc(stdin) == ' ');

        //indegree에 진입차선수 저장
        for (int j = 0; j < rank.size(); j++)
        {
            indegree[rank[j]] = j;
        }

        //두개씩 상대적인 순위 모두 추출 -> list에 저장
        for (int j = 0; j < rank.size(); j++)
        {
            if (j == rank.size() - 1)
            {
                break;
            }
            else
            {
                for (int k = j + 1; k < rank.size(); k++)
                {
                    list[rank[j]].emplace_back(rank[k]);
                }
            }
        }

        int change_cnt; //상대적인 등수가 바뀐 쌍의 수
        cin >> change_cnt;
        for (int j = 0; j < change_cnt; j++)
        {
            int chg1, chg2; //상대적인 등수가 바뀐 팀번호
            cin >> chg1 >> chg2;
            bool isChg1toChg2 = false;                  //기존 등수가 chg1->chg2?
            for (int k = 0; k < list[chg1].size(); k++) //list[chg1]에서 chg2를 찾음
            {
                if ((list[chg1])[k] == chg2) //기존 등수가 chg1->ch2인 경우
                {
                    list[chg1].erase(list[chg1].begin() + k); //list[chg1]에서 chg2를 지움
                    indegree[chg2]--;
                    list[chg2].emplace_back(chg1); //list[chg2]에 chg1을 추가 (chg2->ch1)
                    indegree[chg1]++;
                    isChg1toChg2 = true;
                    break;
                }
            }

            if (isChg1toChg2 == false) //기존 둥수가 chg2->ch1인 경우
            {
                for (int k = 0; k < list[chg2].size(); k++) //list[chg2]에서 chg1를 찾음  (거노찡:list[chg2].size를 미리 따로 빼놓으면 시간단축(함수계속 호출x))
                {
                    if ((list[chg2])[k] == chg1)
                    {
                        list[chg2].erase(list[chg2].begin() + k); //list[chg2]에서 chg1를 지움
                        indegree[chg1]--;
                        list[chg1].emplace_back(chg2); //list[chg1]에 chg2을 추가 (chg1->ch2)
                        indegree[chg2]++;
                        break;
                    }
                }
            }
        }

        //indegree == 0인 애들 indegree_zero 큐에 넣음
        //while문 통해 큐가 빌때까지 1.큐에서 빼고 2.뺀 애, 뺀 애의 리스트에 달려있는 애들 indegree--; 3.뺀애를 최종순위로
        queue<int> indegree_zero; //indegree==0인 팀번호 넣을 큐

        //큐 초기 설정
        for (int j = 1; j < team_cnt + 1; j++)
        {
            if (indegree[j] == 0)
                indegree_zero.push(j);
        }

        while (!indegree_zero.empty())
        {
            //큐의 원소수가 2개이상일 경우 "?"
            if (indegree_zero.size() != 1)
            {
                result[i].emplace_back(-2);
                break;
            }

            int now = indegree_zero.front();
            indegree_zero.pop();
            result[i].emplace_back(now); //최종순위에 추가

            for (int j = 0; j < list[now].size(); j++)
            {
                indegree[(list[now])[j]]--;
                if (indegree[(list[now])[j]] == 0)
                    indegree_zero.push((list[now])[j]);
            }
        }

        //잘못된 정보로 순위를 추정할 수 없는 경우(순위 추정 못한 팀들이 남아있는데 진입차선수==0인 팀이 없음-큐가 빔): "IMPOSSIBLE"
        if (result[i].size() != team_cnt)
        {
            result[i].clear();
            result[i].emplace_back(-1);
        }
    }

    for (int i = 0; i < test_cnt; i++)
    {
        for (int j = 0; j < result[i].size(); j++)
        {
            if (result[i][j] == -1)
            {
                cout << "IMPOSSIBLE";
                break;
            }
            else if (result[i][j] == -2)
            {
                cout << "?";
                break;
            }
            cout << result[i][j] << " ";
        }
        cout << '\n';
    }
}