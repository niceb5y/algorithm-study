#include "pch.h"
#include <iostream>
#include <list>

using namespace std;
int people, jump;
list<int> army;
//링크드 리스트를 이용하여 풀기
//c++에서는 List가 링크드 리스트, vector가 동적배열을 제공해준다
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
			//사람이 죽음으로써 포인터는 이미 1칸 이동한 상태이다
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