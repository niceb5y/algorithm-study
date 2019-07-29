#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Edge
{
	int start;
	int end;
	int cost;
	Edge(int a, int b, int c) {
		start = a;
		end = b;
		cost = c;
	}
};
bool EdgeSort(Edge first, Edge Second);
bool AllComplete();
int findroot(int index);
void union_by_height(int a, int b);
int VertexNumber, EdgeNumber;
vector<int> find_union, edgeDepth;
vector<Edge> EdgeList, spanningTree;
int main() {
	cin >> VertexNumber;
	cin >> EdgeNumber;
	find_union = vector<int>(VertexNumber);
	edgeDepth = vector<int>(VertexNumber, 0);
	for (int i = 0; i < VertexNumber; i++) {
		find_union[i] = i;
	}
	int a, b, c;
	for (int i = 0; i < EdgeNumber; i++) {
		cin >> a;
		cin >> b;
		cin >> c;
		EdgeList.push_back(Edge(a - 1, b - 1, c));
	}
	sort(EdgeList.begin(), EdgeList.end(), EdgeSort);
	for (int i = 0; i < EdgeNumber; i++) {
		if (findroot(EdgeList[i].start) != findroot(EdgeList[i].end)) {
			union_by_height(EdgeList[i].start, EdgeList[i].end);
			spanningTree.push_back(EdgeList[i]);
			if (spanningTree.size() == VertexNumber - 1) {
				break;
			}
		}
	}
	int totalCost = 0;
	for (int i = 0; i < spanningTree.size(); i++) {
		totalCost += spanningTree[i].cost;
	}
	cout << totalCost << endl;
	return 0;
}
bool EdgeSort(Edge first, Edge Second) {
	return first.cost < Second.cost;
}
bool AllComplete(){
	for (int i = 0; i < VertexNumber; i++) {
		if (find_union[i] != 0) {
			return false;
		}
	}
	return true;
}
int findroot(int index) {
	int root = find_union[index];
	while (find_union[root] != root) {
		root = find_union[root];
	}
	return root;
}

int findRoot(int index)
{
	return 0;
}

void union_by_height(int a, int b){
	int aRoot = findroot(a);
	int bRoot = findroot(b);
	if (edgeDepth[a] > edgeDepth[b]) {
		find_union[bRoot] = aRoot;
	}
	else if (edgeDepth[a] < edgeDepth[b]) {
		find_union[aRoot] = bRoot;
	}
	else {
		find_union[bRoot] = aRoot;
		edgeDepth[aRoot]++;
	}
}
