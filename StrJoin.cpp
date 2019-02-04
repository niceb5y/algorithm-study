#include "pch.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int strNum;
vector<int> strLen;
//탐욕적 알고리즘
//허프만 코드문제 최소 길이를 트리의 맨 아래에 둔다 문자열 압축이 빨라진다
int main() {
	int testcase;
	cin >> testcase;
	//탐욕적 알고리즘 증명하기
	//최적해와 다른해가 있다고 가정한다
	//이 해를 탐욕적 해로 적절히 변형할때 다른해 보다 비용이 좋거나 같을때 탐욕적 방법이 가능하다
	//변형전이랑 후가 영향을 미치지 않는곳은 고려하지 않고 계산한다
	for (int trial = 0; trial < testcase; trial++) {
		cin >> strNum;
		strLen = vector<int>(strNum);
		for(int i = 0; i< strNum;i++){
			cin >> strLen[i];
		}
		//가장 단어가 짧은것들을 우선으로 계산하면 된다
		//방법이야 많지만 Priority Queue를 사용해보자
		priority_queue<int, vector<int>, greater<int>> ordered;
		int result = 0;
		for (int i = 0; i < strLen.size(); i++) {
			ordered.push(strLen[i]);
		}
		while (ordered.size() > 1) {
			int firstmin = ordered.top();
			ordered.pop();
			int secondmin = ordered.top();
			ordered.pop();
			result += firstmin + secondmin;
			//합쳐진 단어는 마지막까지 합쳐져야 한다
			ordered.push(firstmin + secondmin);
		}
		cout << result << endl;
	}
	return 0;
}