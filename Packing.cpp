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
//해를 직접 구해야 하는 동적 계획법
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
//직접 해를 구해야 하는경우 계산부와 구현부를 따로 두는게 포인트이다
//leftWeight만큼의 상황에서 해당 item을 넣어야 하는 여부를 판단한다
//절박도가 최대인 경우를 반환
int packing(int currentWeight, int item)
{
	//기저사례: 모든 물건을 고려했을때
	if (item == itemNeed.size()) {
		return 0;
	}
	int& memo = cache[currentWeight][item];
	if (memo != -1) {
		return memo;
	}
	//해당 물건을 담지 않을때
	memo = packing(currentWeight, item + 1);
	//해당 물건을 담을때
	//무게가 허락 하는한
	if (itemWeight[item] + currentWeight <= capacity) {
		memo = max(memo, packing(currentWeight + itemWeight[item], item + 1) + itemNeed[item]);
	}
	return memo;
}
//해독부
void decode(int currentWeight, int item, vector<string>& List)
{
	if (item == itemNeed.size()) {
		return;
	}
	//이번 물건이랑 다음물건의 차이가 없을시 가방에 넣지 않았다는것
	if (packing(currentWeight, item) == packing(currentWeight, item + 1)) {
		decode(currentWeight, item + 1, List);
	}
	else {
		List.push_back(itemName[item]);
		decode(currentWeight + itemWeight[item], item + 1, List);
	}
}
 