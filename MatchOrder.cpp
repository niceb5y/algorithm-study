#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int peopleNum;
vector<int> korean, russian;
//탐욕적 알고리즘
//탐욕적 알고리즘은 잘 쓰이지 않지만 다음 두가지를 증명하면 쓰일수 있다
//1. 최적 부분구조: 부분해의 합이 최적해가 되는경우
//2. 탐욕적 선택 속성: 모든단계에서 항상 탐욕적으로 고른 최적해가 존재해야한다
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> peopleNum;
		korean = vector<int>(peopleNum);
		russian = vector<int>(peopleNum);
		for (int i = 0; i < peopleNum; i++) {
			cin >> russian[i];
		}
		for (int i = 0; i < peopleNum; i++) {
			cin >> korean[i];
		}
		sort(korean.begin(), korean.end());
		int win = 0;
		for (int i = 0; i < peopleNum; i++) {
			if (korean.back() < russian[i]) {
				korean.erase(korean.begin());
			}
			else {
				int temp = 0;
				for (vector<int>::iterator j = korean.begin(); j !=korean.end(); j++) {
					if (*j >= russian[i]) {
						korean.erase(j);
						win++;
						break;
					}
				}
			}
		}
		cout << win << endl;
	}
	return 0;
}