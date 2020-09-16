#include <iostream>
#include <vector>
#include <string>

using namespace std;
vector<vector<int>> matrix;

void compress(int base_r, int base_c, int size)
{
    int start = matrix[base_r][base_c];
    bool isAllSame = true;
    for (int i = 0; i < size; i++)
    {
        if (isAllSame == false)
            break;
        for (int j = 0; j < size; j++)
        {
            if (matrix[base_r + i][base_c + j] != start)
            {
                isAllSame = false;
                break;
            }
        }
    }
    if (isAllSame == false)
    {
        cout << "(";
        size /= 2;
        compress(base_r, base_c, size);
        compress(base_r, base_c + size, size);
        compress(base_r + size, base_c, size);
        compress(base_r + size, base_c + size, size);
        cout << ")";
    }
    else //isAllSame == true
    {
        cout << start;
    }
}

int main()
{
    int N;
    cin >> N;
    matrix.assign(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    { //입력받은 데이터를 2차원 벡터에 넣기
        string tmp; //한줄의 문자열을 넣을 문자열
        cin >> tmp; //한줄을 문자열로 받음
        for(int j = 0; j<N; j++){
            int tmpint = tmp[j] - '0';
            matrix[i][j] = tmpint;
        }
    }

    compress(0, 0, N);
}
