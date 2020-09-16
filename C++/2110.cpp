//2110번 공유기 설치
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long Long;
Long house[200000]; //집 좌표가 순서대로 저장된 배열
int my_house; // 집 개수
int my_wifi; // 공유기 개수

bool possibleD(Long d)
{
	int start = 0;
	int wifi_cnt = my_wifi - 1; //남은 공유기 개수

	for (int i = 1; i < my_house; i++)
	{
		if (house[i] - house[start] >= d)
		{
			start = i;
			wifi_cnt--;
		}
		if (wifi_cnt == 0)
			return true;
	}
	return false;
}

int main(void)
{
	scanf("%d %d", &my_house, &my_wifi);
	for (int i = 0; i < my_house; i++) {
		cin >> house[i];
	}

	sort(house, house + my_house); //sort(배열 시작주소, 시작주소+(정렬할 끝index+1));
	Long left = 1, right = house[my_house - 1];
	Long mid = (left + right) / 2;

	while (left + 1 < right)
	{
		if (possibleD(mid) == true) {
			left = mid;
			mid = (left + right) / 2;
		}
		else {
			right = mid;
			mid = (left + right) / 2;
		}
	}
	cout << left;
}