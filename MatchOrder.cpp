#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int peopleNum;
vector<int> korean, russian;
//Ž���� �˰���
//Ž���� �˰����� �� ������ ������ ���� �ΰ����� �����ϸ� ���ϼ� �ִ�
//1. ���� �κб���: �κ����� ���� �����ذ� �Ǵ°��
//2. Ž���� ���� �Ӽ�: ���ܰ迡�� �׻� Ž�������� �� �����ذ� �����ؾ��Ѵ�
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