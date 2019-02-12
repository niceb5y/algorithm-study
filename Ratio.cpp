#include "pch.h"
#include <iostream>

using namespace std;
long long Limit = 2000000000;
int winRate(long long games, long long wins);
int solve(long long games, long long wins);
//이분법으로 해 구하기
int main() {
	int testcase, games, wins;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> games;
		cin >> wins;
		cout << solve(games, wins) << endl;
	}
	return 0;
}

int winRate(long long games, long long wins)
{
	return wins*100/games;
}

int solve(long long games, long long wins)
{
	//기저사례: 20억 연승해도 무리라면 불가능하다
	if (winRate(games, wins) == winRate(games + Limit, wins + Limit)) {
		return -1;
	}
	long long low = 0, high = Limit;
	while (low+1<high)
	{
		long long mid = (low + high) / 2;
		//mid 만큼 연승했음에도 승률이 그대로라면 더 이겨야 한다
		if (winRate(games, wins) == winRate(games + mid, wins + mid)) {
			low = mid;
		}
		//그렇지 않다면 덜 이겨도 되는걸 고려해보자
		else {
			high = mid;
		}
	}
	//최소값 구하기에서는 최대반환
	return high;
}
