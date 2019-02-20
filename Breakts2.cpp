#include "pch.h"
#include <iostream>
#include <string>
#include <stack>

using namespace std;
//스택 이용한 간단한 괄호 유효성 검사
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		string bucketlist;
		cin >> bucketlist;
		bool fit = true;
		string open = "({[", close = ")}]";
		stack<char> openList;
		for (int i = 0; i < bucketlist.size(); i++) {
			if (open.find(bucketlist[i]) != -1) {
				openList.push(bucketlist[i]);
			}
			else if (close.find(bucketlist[i]) != -1) {
				if (openList.empty()) {
					fit = false;
					break;
				}
				if (open.find(openList.top()) != close.find(bucketlist[i])) {
					fit = false;
					break;
				}
				openList.pop();
			}
		}
		if (!openList.empty()) {
			fit = false;
		}
		if (fit) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}