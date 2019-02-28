#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode
{
	vector<TreeNode*> children;
};

vector<int> x,y,r;
int fortressNum,longest;
int sqr(int x);
int sqrDist(int a, int b);
bool enclose(int parent, int child);
bool isChild(int parent, int child);
TreeNode* getTree(int root);
int treeHeight(TreeNode* root);
//기하의 트리구현
int main() {
	int testCase;
	cin >> testCase;
	for (int trial = 0; trial < testCase; trial++) {
		cin >> fortressNum;
		x = vector<int>(fortressNum);
		y = vector<int>(fortressNum);
		r = vector<int>(fortressNum);
		longest = 0;
		for (int i = 0; i < fortressNum; i++) {
			cin >> x[i];
			cin >> y[i];
			cin >> r[i];
		}
		TreeNode* fortresses = getTree(0);
		int TreeHeight = treeHeight(fortresses);
		cout << max(TreeHeight, longest) << endl;
	}
	return 0;
}

int sqr(int x)
{
	return x*x;
}

int sqrDist(int a, int b)
{
	return sqr(x[a] - x[b]) + sqr(y[a] - y[b]);
}

bool enclose(int parent, int child)
{
	return r[parent] > r[child] && sqrDist(parent, child) < sqr(r[parent] - r[child]);
}
//자식인지 여부 판단
bool isChild(int parent, int child)
{
	//포함하지 않는다면 당연히 자식이 아니다
	if (!enclose(parent, child)) {
		return false;
	}
	//여기서부터 포함하는건 기정 사실이 된다
	//부모는 한개이므로 두개 이상의 부모를 가질수 없다
	for (int i = 0; i < fortressNum; i++) {
		//TreeNode에는 항상 직접적인 자식만이 들어간다
		//하나 끼고 포함하는건 벡터에 넣을 필요 없다
		if (i != parent && i != child && enclose(parent, i) && enclose(i, child)) {
			return false;
		}
	}
	return true;
}

TreeNode * getTree(int root)
{
	TreeNode* result = new TreeNode();
	for (int index = 0; index < fortressNum; index++) {
		if (isChild(root, index)) {
			result->children.push_back(getTree(index));
		}
	}
	return result;
}

int treeHeight(TreeNode* root)
{
	vector<int> height;
	for (int i = 0; i < root->children.size(); i++) {
		//모든 자식들의 깊이 저장
		height.push_back(treeHeight(root->children[i]));
	}

	if (height.empty()) {
		return 0;
	}
	//마지막 즉 제일 큰 값이 서브트리의 깊이이다
	sort(height.begin(), height.end());
	//여기서부턴 추가구현
	//자식이 2개 이상이라면 
	if (height.size() >= 2) {
		longest = max(longest, 2+height[height.size()-1]+height[height.size()-2]);
	}
	//root를 포함한 깊이를 리턴
	return height[height.size() - 1] + 1;
}
