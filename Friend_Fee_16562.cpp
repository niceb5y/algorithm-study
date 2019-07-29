#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> unionFind, unionLevel, friendCost;
vector<bool> friendMaked;
int findRoot(int index);
void union_by_height(int a, int b);
int getCheapest(int rootNum);
int studentNum, friendNode, money;
int main() {
	cin >> studentNum;
	cin >> friendNode;
	cin >> money;
	unionFind = vector<int>(studentNum);
	unionLevel = vector<int>(studentNum, 0);
	friendCost = vector<int>(studentNum);
	for (int i = 0; i < studentNum; i++) {
		unionFind[i] = i;
	}
	for (int i = 0; i < studentNum; i++) {
		int temp;
		cin >> temp;
		friendCost[i] = temp;
	}
	int a, b;
	for (int i = 0; i < friendNode; i++) {
		cin >> a;
		cin >> b;
		union_by_height(a - 1, b - 1);
	}
	friendMaked = vector<bool>(studentNum, false);
	int totalCost = 0;
	for (int i = 0; i < studentNum; i++) {
		if (!friendMaked[i]) {
			totalCost += getCheapest(findRoot(i));
		}
	}
	if (money < totalCost) {
		cout << "Oh no" << endl;
	}
	else {
		cout << totalCost << endl;
	}
	return 0;
}
int findRoot(int index) {
	int root = unionFind[index];
	while (unionFind[root] != root) {
		root = unionFind[root];
	}
	return root;
}

void union_by_height(int a, int b) {
	int aRoot = findRoot(a);
	int bRoot = findRoot(b);
	if (aRoot == bRoot) {
		return;
	}
	if (unionLevel[aRoot] > unionLevel[bRoot]) {
		unionFind[bRoot] = aRoot;
	}
	else if (unionLevel[bRoot] > unionLevel[aRoot]) {
		unionFind[aRoot] = bRoot;
	}
	else {
		unionFind[bRoot] = aRoot;
		unionLevel[aRoot]++;
	}
	return;
}

int getCheapest(int rootNum) {
	int result = 76539;
	for (int i = 0; i < studentNum; i++) {
		if (findRoot(i) == rootNum) {
			result = min(result, friendCost[i]);
			friendMaked[i] = true;
		}
	}
	return result;
}