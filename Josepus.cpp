#include "pch.h"
#include <iostream>
#include <list>

using namespace std;
int people, jump;
list<int> army;
//��ũ�� ����Ʈ�� �̿��Ͽ� Ǯ��
//c++������ List�� ��ũ�� ����Ʈ, vector�� �����迭�� �������ش�
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> people;
		cin >> jump;
		army = list<int>();
		for (int i = 1; i <= people; i++) {
			army.push_back(i);
		}
		list<int>::iterator suiside = army.begin();
		while (army.size() > 2)
		{
			suiside = army.erase(suiside);
			if (suiside == army.end()) {
				suiside = army.begin();
			}
			//����� �������ν� �����ʹ� �̹� 1ĭ �̵��� �����̴�
			for (int i = 0; i < jump-1; i++) {
				suiside++;
				if (suiside == army.end()) {
					suiside = army.begin();
				}
			}
		}
		cout << army.front() << " " << army.back() << endl;

	}
	return 0;
}