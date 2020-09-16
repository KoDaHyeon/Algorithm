#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> paper;
int count[3]; //-1, 0, 1의 개수

void divide(int base_r, int base_c, int size)
{
    int start = paper[base_r][base_c]; //처음 수 보관
    bool isAllSame = true;

    //종이에 적힌 모든 수가 같은지 조사
    for (int i = 0; i < size; i++)
    {
        if (isAllSame == false)
            break;
        for (int j = 0; j < size; j++)
        {
            if (start != paper[base_r + i][base_c + j])
            {
                isAllSame = false;
                break;
            }
        }
    }

    if (isAllSame == false) //처음 수와 다른 수가 하나라도 있으면 9등분
    {
        size /= 3;
        divide(base_r, base_c, size);
        divide(base_r, base_c + size, size);
        divide(base_r, base_c + size * 2, size);
        divide(base_r + size, base_c, size);
        divide(base_r + size, base_c + size, size);
        divide(base_r + size, base_c + size * 2, size);
        divide(base_r + size * 2, base_c, size);
        divide(base_r + size * 2, base_c + size, size);
        divide(base_r + size * 2, base_c + size * 2, size);
    }
    else //모든 수가 같으면 그 수의 개수++;
    {
        switch(start){
            case -1: count[0]++; break;
            case 0: count[1]++; break;
            case 1: count[2]++; break;
            default: break;
        }
    }
}

int main()
{
    int N; // 종이 한변의 크기
    cin >> N;
    paper.assign(N, vector<int>(N, 0)); //N개행, N개열(값은 0)을 가진 2차원벡터 할당
    for (int i = 0; i < N; i++)
    {
        int tmp;
        int j = 0;
        do
        {
            cin >> tmp;
            paper[i][j] = tmp;
            j++;
        } while (getc(stdin) == ' ');
    }

    divide(0, 0, N);
    cout << count[0] << '\n' << count[1] << '\n' << count[2];
}