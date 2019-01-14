#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> cache;
vector<int> board1, board2;
int jlis(int input1, int input2);
//동적 계획법(최적 부분 구조)
//부분 최적들이 모여 최대 최적을 구해낸다
//LIS를 2개의 집합 사이에서 구한다
int main() {
	int testcase, length1, length2, temp;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> length1;
		cin >> length2;
		//각각 첫배열의 첫수로 인한 건너뜀이 발생 할수 있다
		cache = vector<vector <int>>(length1+1, vector<int>(length2+1,-1));
		//배열의 크기를 1씩 늘린다
		board1 = vector<int>(length1+1);
		board2 = vector<int>(length2+1);
		for (int i = 1; i < length1+1; i++) {
			cin >> board1[i];
		}
		for (int i = 1; i < length2+1; i++) {
			cin >> board2[i];
		}
		//첫번째칸을 최소값으로 둔다
		board1[0] = INT32_MIN;
		board2[0] = INT32_MIN;
		int maxLength = 0;
		//맨앞이 최소값이기때문에 for문이 없어도 알아서 계산된다
		maxLength = max(maxLength, jlis(0, 0));
		//맨앞의 최소값크기 2개를 버린다
		cout << maxLength - 2 << endl;
	}
	return 0;
}
//합친 LIS
int jlis(int input1, int input2)
{
	int& temp = cache[input1][input2];
	if (temp != -1) {
		return temp;
	}
	//이번에는 두개의 행렬이 포함되므로 2를 더해준다.
	//초반의 최솟값 2개가 들어간 셈이므로 나중에 빼준다
	temp = 2;
	int maxNumber = max(board1[input1], board2[input2]);
	for (int i = input1 + 1; i < board1.size(); i++) {
		if (maxNumber < board1[i]) {
			temp = max(temp, 1 + jlis(i, input2));
		}
	}
	for (int j = input2 + 1; j < board2.size(); j++) {
		if (maxNumber < board2[j]) {
			temp = max(temp, 1 + jlis(input1, j));
		}
	}
	return temp;
}
