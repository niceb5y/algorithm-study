#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
int friendNum, foodNum,bestCase;
vector<vector<int>> canEat,canEaten;
void party(vector<int>& myFood, int choosen);
//���Ŀ� �Լ���
bool compare(const vector<int> &a, const vector<int> &b) {
	return a.size() < b.size();
}
bool revcompare(const vector<int> &a, const vector<int> &b) {
	return a.size() > b.size();
}
//���� Ž��
//���� Ž���� ���İ� �ʿ䰡 ���� �κ��� ���� �������ν� �ð��� �����ϴ� ���
//������ȹ���� �޸������̼��� ������ ������� �õ�
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> friendNum;
		cin >> foodNum;
		//��� ������ �� �����찡 �ִ�
		bestCase = foodNum;
		//i�� ������ �ִ� ���ĵ�
		canEat = vector<vector<int>>(friendNum);
		//i�� ������ �ִ� ģ���� ���
		canEaten = vector<vector<int>>(foodNum);
		vector<string> friendName = vector<string>(friendNum);
		for (int i = 0; i < friendNum; i++) {
			cin >> friendName[i];
		}
		for (int food = 0; food < foodNum; food++) {
			int size;
			cin >> size;
			canEaten[food] = vector<int>(size);
			for (int i = 0; i < size; i++) {
				string eater;
				cin >> eater;
				for (int j = 0; j < friendNum; j++) {
					if (friendName[j] == eater) {
						canEaten[food][i] = j;
						canEat[j].push_back(food);
						break;
					}
				}
			}
		}
		//���� ������ �ִ� ������ ���� ����ϴ°� �̵�
		//���� ������ ���� ���� ���̺��� ����ϴ°� �̵�
		//sort(canEaten.begin(), canEaten.end(),revcompare);
		//sort(canEat.begin(), canEat.end(),compare);
		vector<int> itemList = vector<int>(friendNum, 0);
		party(itemList, 0);
		cout << bestCase << endl;
	}
	return 0;
}
//i��° ���̰� ������ �ִ� ������ ��
void party(vector<int>& myFood, int choosen)
{
	//������ �ʹ� ������ ����
	if (choosen >= bestCase) {
		return;
	}
	//�ƹ��͵� ���Դ� ����� ã�Ƴ���
	int firstPity = 0;
	for (firstPity = 0; firstPity < friendNum; firstPity++) {
		if (myFood[firstPity] == 0) {
			break;
		}
	}
	//�� ���� �Ÿ����� ���� choosen�� �׻� bestcase���� �۴�
	if (firstPity >= friendNum) {
		bestCase = choosen;
		return;
	}
	//ù��°�� ������ ���̸� ���� ������ ����Ѵ�
	for (int food = 0; food < canEat[firstPity].size(); food++) {
		int thisfood = canEat[firstPity][food];
		for (int feed = 0; feed < canEaten[thisfood].size(); feed++) {
			myFood[canEaten[thisfood][feed]]++;
		}
		party(myFood, choosen + 1);
		for (int feed = 0; feed < canEaten[thisfood].size(); feed++) {
			myFood[canEaten[thisfood][feed]]--;
		}
	}
}
