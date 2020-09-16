#include <iostream>

using namespace std;
int cnt;

void move(int k, int from, int tmp, int to)
{
    if(k == 1){
        cout << from << ' ' << to << '\n'; //주의!! 반복문에서 endl쓰면 시간초과남
    }
    else{
        //n-1개를 from->tmp
        move(k-1, from, to, tmp);
        //1개를 from->to
        move(1, from, tmp, to);
        //n-1개를 tmp->to
        move(k-1, tmp, from, to);
    }
}

//k개를 from->to로 옮길때 총 횟수
int count(int k)
{
    if(k==1){
        return 1;
    }
    else if(k>=2){
        return 2*count(k-1)+1;
    }
}

int main()
{
    int N; //원판 개수
    cin >> N;
    cout << count(N) << '\n';
    move(N, 1, 2, 3);
}
