#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int workers, works, doubleAblers;
vector<bool> visited;// , secondVisited;
vector<int> match;
vector<vector<int>> adjBoard;
bool DFS(int index);
int main() {
	cin >> workers;
	cin >> works;
	cin >> doubleAblers;
	
	//secondVisited = vector<bool>(workers, false);
	adjBoard = vector<vector<int>>(workers);
	for (int i = 0; i < workers; i++) {
		int possibleWorks;
		cin >> possibleWorks;
		for (int j = 0; j < possibleWorks; j++) {
			int tempWork;
			cin >> tempWork;
			adjBoard[i].push_back(tempWork - 1);
		}
	}
	int result = 0;
	match = vector<int>(works, -1);
	for (int i = 0; i < workers; i++) {
		visited = vector<bool>(workers, false);
		if (DFS(i)) {
			result++;
		}
	}
	int secondResult = 0;
	for (int i = 0; i < workers; i++) {
		visited = vector<bool>(workers, false);
		if (DFS(i)) {
			secondResult++;
			if (secondResult >= doubleAblers) {
				break;
			}
		}
	}
	cout << result + secondResult << endl;
	return 0;
}
bool DFS(int index) {
	if (visited[index]) {
		return false;
	}
	visited[index] = true;
	for (int i = 0; i < adjBoard[index].size(); i++) {
		int currentMatch = adjBoard[index][i];
		if (match[currentMatch] == -1) {
			match[currentMatch] = index;
			return true;
		}
	}
	for (int i = 0; i < adjBoard[index].size(); i++) {
		int currentMatch = adjBoard[index][i];
		if (DFS(match[currentMatch])) {
			match[currentMatch] = index;
			return true;
		}
	}
	return false;
}
