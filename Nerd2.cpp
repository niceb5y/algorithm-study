#include "pch.h"
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
//<Ű,��>�� ����
map<int, int> coords;
bool isDominated(int x, int y);
void deleteDominated(int x, int y);
int hereComesNewChallenger(int x, int y);
//����Ʈ�� Map
int main() {
	int testCase, challengerNum, question, ramen, total;
	cin >> testCase;
	for (int trial = 0; trial < testCase; trial++) {
		coords.clear();
		cin >> challengerNum;
		total = 0;
		for (int i = 0; i < challengerNum; i++) {
			cin >> question;
			cin >> ramen;
			total += hereComesNewChallenger(question, ramen);
		}
		cout << total << endl;
	}
	return 0;
}

bool isDominated(int x, int y)
{
	//x��ǥ �̻��� ���� ������ ��ȯ���ش�
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.end()) {
		//�� ���� ���� ���ʿ� �����Ƿ� ��������� ��������� �ʴ´�
		return false;
	}
	//x������ �������κ��ʹ� �����ο쳪 �� ���ķδ� �������� ���ϴ�
	//y�� ���� ������ �������Ƿ� �ٷ� ���� y������ �����Ӵٸ� ������ y�� ���ؼ��� �����Ӵ�
	return y < it->second;
}

void deleteDominated(int x, int y)
{
	//x��ǥ �̻��� ���� ������ ��ȯ���ش�
	map<int, int>::iterator it = coords.lower_bound(x);
	if (it == coords.begin()) {
		//x��ǥ�� x�� ���� ���ʿ� �ִ�
		return;
	}
	//�������ʹ� x�̸��� ��ǥ���̴�
	it--;
	while (true)
	{
		//�� �������ʹ� x�����κ��� ������ �����Ӵ�
		if (it->second > y) {
			break;
		}
		//���� ���������� �� ���� ������Ѵٸ�
		if (it == coords.begin()) {
			//����� ������
			coords.erase(it);
			break;
		}
		else {
			//����� �ٿ�������
			map<int, int>::iterator temp = it;
			temp--;
			coords.erase(it);
			it = temp;
		}
	}
}

int hereComesNewChallenger(int x, int y)
{
	if (isDominated(x, y)) {
		return coords.size();
	}
	else {
		deleteDominated(x, y);
	}
	//map ���� �߰� ���[Ű]=��
	coords[x] = y;
	return coords.size();
}
