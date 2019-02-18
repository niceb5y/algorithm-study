#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int Limit = 987654321;
int classNum, needClass, semesterNum, semesterLim;
vector<int> preRequired_bit;
vector<int> classinSemester_bit;
vector<vector<int>> cache;
int bitSize(int bit);
int graduate(int semester, int taken);
//��Ʈ����ũ�� ���� �ӵ��� ������ ���ش�
//��ȹ���� ������ȹ���� ���ø���
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> classNum;
		cin >> needClass;
		cin >> semesterNum;
		cin >> semesterLim;
		preRequired_bit = vector<int>(classNum);
		classinSemester_bit = vector<int>(semesterNum);
		cache = vector<vector<int>>(semesterNum, vector<int>(1 << classNum, -1));
		//������� ����
		for (int i = 0; i < classNum; i++) {
			int preList = 0;
			int preNum;
			cin >> preNum;
			for (int j = 0; j < preNum; j++) {
				int pre;
				cin >> pre;
				preList |= (1 << pre);
			}
			preRequired_bit[i] = preList;
		}
		//�б⺰ ���� ����
		for (int i = 0; i < semesterNum; i++) {
			int classList = 0;
			int classNum;
			cin >> classNum;
			for (int j = 0; j < classNum; j++) {
				int class_;
				cin >> class_;
				classList |= (1 << class_);
			}
			classinSemester_bit[i] = classList;
		}
		int result = graduate(0, 0);
		if (result == Limit) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << result << endl;
		}
	}
	return 0;
}

int bitSize(int bit)
{
	if (bit == 0) {
		return 0;
	}
	//2��0�º��� ���鼭 ũ�⸦ �ٿ�������
	return bit % 2 + bitSize(bit / 2);
}
//semester�б��϶� taken�� ����ٸ� ���б⸦ �� ���� �ϳ�
int graduate(int semester, int taken)
{
	//�������: �̹� �˸°� ��������
	if (bitSize(taken) >= needClass) {
		return 0;
	}
	//�������2: �����ʾ����� �̹� ��ǥ�б� �̻��϶�
	if (semester == semesterNum) {
		return Limit;
	}
	int& result = cache[semester][taken];
	if (result != -1) {
		return result;
	}
	result = Limit;
	//�̹��б� ������ ������ ����
	int canTake = (classinSemester_bit[semester] & ~taken);
	for (int i = 0; i < classNum; i++) {
		//������ ������ ��������� ���� ������� �ʾҴٸ�
		if ((canTake &(1 << i))&&((taken&preRequired_bit[i])!=preRequired_bit[i])) {
			canTake &= ~(1 << i);
		}
	}
	//��� �κ����� ��ȸ
	//������ bit�� 0�̰� ���� bit�� 1�϶� 1�� ���鼭 ���� bit�� 0�̵ǰ�
	//������ bit�� 1�̵ȴ� �ᱹ �� �Ʒ��ͺ��� �ְ� ���¹������ ����ȴ�
	for (int take = canTake; take > 0; take = ((take - 1)&canTake)) {
		if (bitSize(take) > semesterLim) {
			continue;
		}
		result = min(result, graduate(semester + 1, taken | take) + 1);
	}
	//�ƹ� ������ �ȵ�´ٸ�
	result = min(result, graduate(semester + 1, taken));
	return result;
}
