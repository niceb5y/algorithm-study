#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
vector<string> itemName;
vector<int> itemWeight;
vector<int> itemNeed;
vector<vector<int>> cache;
vector<string> packedList;
int capacity;
int packing(int leftWeight, int item);
void decode(int leftWeight, int item, vector<string>& List);
//�ظ� ���� ���ؾ� �ϴ� ���� ��ȹ��
int main() {
	int testcase, needItem;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> needItem;
		cin >> capacity;
		itemName = vector<string>(needItem);
		itemWeight = vector<int>(needItem);
		itemNeed = vector<int>(needItem);
		cache = vector<vector<int>>(capacity + 1, vector<int>(needItem + 1, -1));
		packedList = vector<string>();
		for (int i = 0; i < needItem; i++) {
			cin >> itemName[i];
			cin >> itemWeight[i];
			cin >> itemNeed[i];
		}
		cout << packing(0, 0)<<" ";
		decode(0, 0, packedList);
		cout << packedList.size() << endl;
		for (int i = 0; i < packedList.size(); i++) {
			cout << packedList[i] << endl;
		}
		
	}
	return 0;
}
//���� �ظ� ���ؾ� �ϴ°�� ���ο� �����θ� ���� �δ°� ����Ʈ�̴�
//leftWeight��ŭ�� ��Ȳ���� �ش� item�� �־�� �ϴ� ���θ� �Ǵ��Ѵ�
//���ڵ��� �ִ��� ��츦 ��ȯ
int packing(int currentWeight, int item)
{
	//�������: ��� ������ ���������
	if (item == itemNeed.size()) {
		return 0;
	}
	int& memo = cache[currentWeight][item];
	if (memo != -1) {
		return memo;
	}
	//�ش� ������ ���� ������
	memo = packing(currentWeight, item + 1);
	//�ش� ������ ������
	//���԰� ��� �ϴ���
	if (itemWeight[item] + currentWeight <= capacity) {
		memo = max(memo, packing(currentWeight + itemWeight[item], item + 1) + itemNeed[item]);
	}
	return memo;
}
//�ص���
void decode(int currentWeight, int item, vector<string>& List)
{
	if (item == itemNeed.size()) {
		return;
	}
	//�̹� �����̶� ���������� ���̰� ������ ���濡 ���� �ʾҴٴ°�
	if (packing(currentWeight, item) == packing(currentWeight, item + 1)) {
		decode(currentWeight, item + 1, List);
	}
	else {
		List.push_back(itemName[item]);
		decode(currentWeight + itemWeight[item], item + 1, List);
	}
}
 