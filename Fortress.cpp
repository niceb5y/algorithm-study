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
//������ Ʈ������
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
//�ڽ����� ���� �Ǵ�
bool isChild(int parent, int child)
{
	//�������� �ʴ´ٸ� �翬�� �ڽ��� �ƴϴ�
	if (!enclose(parent, child)) {
		return false;
	}
	//���⼭���� �����ϴ°� ���� ����� �ȴ�
	//�θ�� �Ѱ��̹Ƿ� �ΰ� �̻��� �θ� ������ ����
	for (int i = 0; i < fortressNum; i++) {
		//TreeNode���� �׻� �������� �ڽĸ��� ����
		//�ϳ� ���� �����ϴ°� ���Ϳ� ���� �ʿ� ����
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
		//��� �ڽĵ��� ���� ����
		height.push_back(treeHeight(root->children[i]));
	}

	if (height.empty()) {
		return 0;
	}
	//������ �� ���� ū ���� ����Ʈ���� �����̴�
	sort(height.begin(), height.end());
	//���⼭���� �߰�����
	//�ڽ��� 2�� �̻��̶�� 
	if (height.size() >= 2) {
		longest = max(longest, 2+height[height.size()-1]+height[height.size()-2]);
	}
	//root�� ������ ���̸� ����
	return height[height.size() - 1] + 1;
}
