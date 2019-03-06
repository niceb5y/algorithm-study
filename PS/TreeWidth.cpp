#include "pch.h"
#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

vector<pair<int, int>> Tree;
vector<vector<int>> TreeMap;
int nodeNum, nodeDepth, nodeIndex;
int findDepth(int node);
void makeTree(int node,int depth);
int main()
{
	cin >> nodeNum;
	Tree = vector<pair<int, int>>(nodeNum);
	for (int i = 0; i < nodeNum; i++) {
		int index;
		cin >> index;
		int left, right;
		cin >> left;
		cin >> right;
		Tree[index - 1] = make_pair(left - 1, right - 1);
	}
	int rootIndex = 0;
	nodeDepth = 0;
	for (int i = 0; i < nodeNum; i++) {
		if (nodeDepth < findDepth(i) + 1) {
			rootIndex = i;
			nodeDepth = findDepth(i) + 1;
		}
	}
	TreeMap = vector<vector<int>>(nodeDepth, vector<int>(nodeNum, -2));
	nodeIndex = 0;
	makeTree(rootIndex, 0);
	int nodeWidth = 0, maxLevel = 0;
	for (int i = 0; i < nodeDepth; i++) {
		int first = -1, second = -1;
		for (int j = 0; j < nodeNum; j++) {
			if (TreeMap[i][j] != -2) {
				if (first == -1) {
					first = j;
				}
				second = max(second, j);
			}
		}
		if (second - first > nodeWidth) {
			nodeWidth = second - first;
			maxLevel = i;
		}
	}
	cout << maxLevel + 1 << " " << nodeWidth + 1 << endl;
}

int findDepth(int node)
{
	int depth = 0;
	if (Tree[node].first != -2) {
		depth = max(depth, findDepth(Tree[node].first) + 1);
	}
	if (Tree[node].second != -2) {
		depth = max(depth, findDepth(Tree[node].second) + 1);
	}
	return depth;
}

void makeTree(int node,int depth)
{
	if (Tree[node].first != -2) {
		makeTree(Tree[node].first, depth + 1);
	}
	TreeMap[depth][nodeIndex] = node;
	nodeIndex++;
	if (Tree[node].second != -2) {
		makeTree(Tree[node].second, depth + 1);
	}
}
