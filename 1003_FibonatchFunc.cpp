#include <iostream>
#include<vector>
using namespace std;

vector<pair<int,int>> callVector;
int testcase;
int main() {
	callVector.push_back(make_pair(1,0));
	callVector.push_back(make_pair(0,1));
	for (int i = 2; i < 41; i++) {
		callVector.push_back(make_pair(callVector[i - 2].first + callVector[i - 1].first, callVector[i - 2].second + callVector[i - 1].second));
	}
	cin >> testcase;
	for (int trial = 0, index; trial < testcase; trial++) {
		cin >> index;
		cout << callVector[index].first << " " << callVector[index].second << endl;
	}
	return 0;
}