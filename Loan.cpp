#include "pch.h"
#include <iostream>
#include<vector>
#include <algorithm>
#include <queue>

using namespace std;
int deadLine;
double interest,loaned;
double checkBalance(double monthPay);
double solve();
//�̺й����� �� ���ϱ�
int main() {
	cout << fixed;
	cout.precision(10);
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> loaned;
		cin >> deadLine;
		cin >> interest;
		cout << solve() << endl;
	}
	return 0;
}

double checkBalance(double monthPay)
{
	double balance = loaned;
	for (int month = 0; month < deadLine; month++) {
		balance *= (1.0 + (interest / 12.0) / 100.0);
		balance -= monthPay;
	}
	return balance;
}

double solve()
{
	double low = 0.0, high = loaned * (1.0 + (interest / 12.0) / 100.0);
	for (int i = 0; i < 100; i++) {
		double mid = (low + high) / 2;
		//���� ���´ٸ�
		if (checkBalance(mid) > 0) {
			//�� ���ð� �����Ѵ�
			low = mid;
		}
		else {
			//�� �� ���� �ȴ�
			high = mid;
		}
	}
	return high;
}

