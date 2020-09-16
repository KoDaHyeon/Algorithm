#include <iostream>
#include <cmath>

using namespace std;
int cnt;
int r, c; //(r,c)

int visit(int base_r, int base_c, int halfSize)
{
    if (halfSize == 1)
    {
        if (r == 1)
            cnt += 2;
        if (c == 1)
            cnt += 1;
    }
    else
    {
        if (r >= halfSize)
        {
            cnt += (2 * halfSize * halfSize);
            if (c >= halfSize)
            {
                cnt += (halfSize * halfSize);
                //이 네모안에서 같은 작업을 반복(4)
                //1. 왼쪽상단좌표 업뎃
                base_r = halfSize;
                base_c = halfSize;
            }
            else
            {
                //이 네모안에서 같은 작업을 반복(3)
                base_r = halfSize;
                base_c = 0;
            }
        }
        else
        {
            if (c >= halfSize)
            {
                //이 네모안에서 같은 작업을 반복(2)
                cnt += (halfSize * halfSize);
                base_r = 0;
                base_c = halfSize;
            }
            else
            {
                //이 네모안에서 같은 작업을 반복(1)
                base_r = 0;
                base_c = 0;
            }
        }

        //2. 이 네모를 기준으로 (r,c)를 다시 업뎃해야함 (왼쪽상단칸과의 차이를 이용)
        r = r - base_r;
        c = c - base_c;
        //3. 같은 함수 호출(인자:왼쪽상단좌표, 변크기(2등분한상태))
        visit(base_r, base_c, halfSize / 2);
    }
    return cnt;
}

int main()
{
    int N;
    cin >> N >> r >> c;

    int size = pow(2, N) / 2; //행렬을 4등분한 네모의 변크기
    cout << visit(0, 0, size);
}