#include "pch.h"
#include <iostream>

using namespace std;
long long Limit = 2000000000;
int winRate(long long games, long long wins);
int solve(long long games, long long wins);
//�̺й����� �� ���ϱ�
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
	//�������: 20�� �����ص� ������� �Ұ����ϴ�
	if (winRate(games, wins) == winRate(games + Limit, wins + Limit)) {
		return -1;
	}
	long long low = 0, high = Limit;
	while (low+1<high)
	{
		long long mid = (low + high) / 2;
		//mid ��ŭ ������������ �·��� �״�ζ�� �� �̰ܾ� �Ѵ�
		if (winRate(games, wins) == winRate(games + mid, wins + mid)) {
			low = mid;
		}
		//�׷��� �ʴٸ� �� �̰ܵ� �Ǵ°� ����غ���
		else {
			high = mid;
		}
	}
	//�ּҰ� ���ϱ⿡���� �ִ��ȯ
	return high;
}
