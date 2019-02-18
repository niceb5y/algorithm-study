#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int Limit = 987654321;
int classNum, needClass, semesterNum, semesterLim;
vector<int> preRequired_bit;
vector<int> classinSemester_bit;
vector<vector<int>> cache;
int bitSize(int bit);
int graduate(int semester, int taken);
//비트마스크는 연산 속도를 빠르게 해준다
//계획법은 동적계획법을 떠올리자
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> classNum;
		cin >> needClass;
		cin >> semesterNum;
		cin >> semesterLim;
		preRequired_bit = vector<int>(classNum);
		classinSemester_bit = vector<int>(semesterNum);
		cache = vector<vector<int>>(semesterNum, vector<int>(1 << classNum, -1));
		//선행과목 생성
		for (int i = 0; i < classNum; i++) {
			int preList = 0;
			int preNum;
			cin >> preNum;
			for (int j = 0; j < preNum; j++) {
				int pre;
				cin >> pre;
				preList |= (1 << pre);
			}
			preRequired_bit[i] = preList;
		}
		//학기별 과목 생성
		for (int i = 0; i < semesterNum; i++) {
			int classList = 0;
			int classNum;
			cin >> classNum;
			for (int j = 0; j < classNum; j++) {
				int class_;
				cin >> class_;
				classList |= (1 << class_);
			}
			classinSemester_bit[i] = classList;
		}
		int result = graduate(0, 0);
		if (result == Limit) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << result << endl;
		}
	}
	return 0;
}

int bitSize(int bit)
{
	if (bit == 0) {
		return 0;
	}
	//2의0승부터 세면서 크기를 줄여나간다
	return bit % 2 + bitSize(bit / 2);
}
//semester학기일때 taken을 들었다면 몇학기를 더 들어야 하나
int graduate(int semester, int taken)
{
	//기저사례: 이미 알맞게 들었을경우
	if (bitSize(taken) >= needClass) {
		return 0;
	}
	//기저사례2: 듣지않았지만 이미 목표학기 이상일때
	if (semester == semesterNum) {
		return Limit;
	}
	int& result = cache[semester][taken];
	if (result != -1) {
		return result;
	}
	result = Limit;
	//이번학기 수업중 들은걸 뺀다
	int canTake = (classinSemester_bit[semester] & ~taken);
	for (int i = 0; i < classNum; i++) {
		//들을수 있으나 선행과목이 아직 진행되지 않았다면
		if ((canTake &(1 << i))&&((taken&preRequired_bit[i])!=preRequired_bit[i])) {
			canTake &= ~(1 << i);
		}
	}
	//모든 부분집합 순회
	//최하위 bit가 0이고 하위 bit가 1일때 1을 빼면서 하위 bit는 0이되고
	//최하위 bit는 1이된다 결국 맨 아래것부터 넣고 빼는방식으로 진행된다
	for (int take = canTake; take > 0; take = ((take - 1)&canTake)) {
		if (bitSize(take) > semesterLim) {
			continue;
		}
		result = min(result, graduate(semester + 1, taken | take) + 1);
	}
	//아무 수업도 안듣는다면
	result = min(result, graduate(semester + 1, taken));
	return result;
}
