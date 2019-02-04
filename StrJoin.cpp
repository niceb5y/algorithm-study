#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int strNum;
vector<int> strLen;
//Ž���� �˰���
//������ �ڵ幮�� �ּ� ���̸� Ʈ���� �� �Ʒ��� �д� ���ڿ� ������ ��������
int main() {
	int testcase;
	cin >> testcase;
	//Ž���� �˰��� �����ϱ�
	//�����ؿ� �ٸ��ذ� �ִٰ� �����Ѵ�
	//�� �ظ� Ž���� �ط� ������ �����Ҷ� �ٸ��� ���� ����� ���ų� ������ Ž���� ����� �����ϴ�
	//�������̶� �İ� ������ ��ġ�� �ʴ°��� ������� �ʰ� ����Ѵ�
	for (int trial = 0; trial < testcase; trial++) {
		cin >> strNum;
		strLen = vector<int>(strNum);
		for(int i = 0; i< strNum;i++){
			cin >> strLen[i];
		}
		//���� �ܾ ª���͵��� �켱���� ����ϸ� �ȴ�
		//����̾� ������ Priority Queue�� ����غ���
		priority_queue<int, vector<int>, greater<int>> ordered;
		int result = 0;
		for (int i = 0; i < strLen.size(); i++) {
			ordered.push(strLen[i]);
		}
		while (ordered.size() > 1) {
			int firstmin = ordered.top();
			ordered.pop();
			int secondmin = ordered.top();
			ordered.pop();
			result += firstmin + secondmin;
			//������ �ܾ�� ���������� �������� �Ѵ�
			ordered.push(firstmin + secondmin);
		}
		cout << result << endl;
	}
	return 0;
}