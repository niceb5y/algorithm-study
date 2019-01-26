#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
int restore(int last, int used);
string decode(int last, int used);
int wordNum;
vector<string> wordList;
vector<vector<int>> overlapList;
vector<vector<int>> cache;
//해를 직접 구해야 하는 동적 계획법
int main() {
	int testcase, boardSize;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		cin >> wordNum;
		bool finded;
		vector<string> wordList2 = vector<string>(wordNum);
		//한 단어가 다른 단어의 부분일때 지워버린다
		for (int i = 0; i < wordNum; i++) {
			cin >> wordList2[i];
		}
		vector<int> comboed = vector<int>();
		for (int i = 0; i < wordNum; i++) {
			for (int j = 0; j < wordNum; j++) {
				if (i == j) {
					continue;
				}
				if (wordList2[j].find(wordList2[i]) != string::npos) {
					comboed.push_back(i);
					break;
				}
			}
		}
		wordList = vector<string>();
		for (int i = 0; i < wordNum; i++) {
			if (find(comboed.begin(), comboed.end(), i) != comboed.end()) {
				continue;
			}
			wordList.push_back(wordList2[i]);
		}
		wordNum = wordList.size();
		overlapList = vector<vector<int>>(wordNum, vector<int>(wordNum, -1));
		//i번째 단어 뒤에 j번째 단어가 나올때 겹치는 부분의 최대를 구한다.
		for (int i = 0; i < wordNum; i++) {
			for (int j = 0; j < wordNum; j++) {
				if (i == j) {
					overlapList[i][j] = -1;
					continue;
				}
				int overlap = 0;
				string a = wordList[i];
				string b = wordList[j];
				int count;
				for (count = min(a.length(), b.length()); count > 0; count--) {
					if (a.substr(a.length() - count) == b.substr(0, count)) {
						break;
					}
				}
				overlapList[i][j] = count;
			}
		}
		cache = vector<vector<int>>(wordNum, vector<int>(1<<wordNum,-1));
		int Bestlast = 0;
		int BestScore = 0;
		//첫 Last는 정해줘야한다
		for (int i = 0; i < wordNum; i++) {
			int temp = restore(i, (1 << i));
			if (BestScore < temp) {
				BestScore = temp;
				Bestlast = i;
			}
		}
		if (Bestlast == -1) {
			cout << "Wrong" << endl;
		}
		cout << wordList[Bestlast]+decode(Bestlast, 1 << Bestlast) << endl;
	}
	return 0;
}
//여행하는 외판원 문제랑 비슷하다
//배열을 정수화 시켜서 저장하는게 포인트이다
//단어의 겹치는 부분을 최대화해서 출력
//last를 맨 마지막으로 이용했고, used의 리스트대로 단어를 이용했을때
//조합중 겹치는부분이 제일 클때의 겹치는 수를 출력
int restore(int last, int used)
{
	//기저사례: 모든 단어를 합해봤을때
	//비트마스크: 1뒤에 wordNum만큼 0 을 붙이고 1을 빼면 wordNum-1만큼 1로 이루어진 숫자가 된다
	if (used == (1 << wordNum)-1) {
		return 0;
	}
	int& memo = cache[last][used];
	if (memo != -1) {
		return memo;
	}
	memo = 0;
	for (int next = 0; next < wordNum; next++) {
		//next의 자리부분에 의해서 전체가 0인지 1인지 판단된다
		//어짜피 다른부분은 다 0이 되므로
		if ((used & (1 << next)) == 0) {
			int tempMax = overlapList[last][next] + restore(next, used + (1 << next));
			memo = max(memo, tempMax);
		}
	}
	return memo;
}

//데이터 복구부
string decode(int last, int used)
{
	//기저사례: 모든 단어를 합해봤을때
//비트마스크: 1뒤에 wordNum만큼 0 을 붙이고 1을 빼면 wordNum-1만큼 1로 이루어진 숫자가 된다
	if (used == (1 << wordNum) - 1) {
		return "";
	}
	for (int next = 0; next < wordNum; next++) {
		//저번과 반대로 사용된 여부를 판단한다
		//0의외엔 다 1이 섞인것이므로 단어가 포함된것이다
		if (used&(1 << next)) {
			continue;
		}
		else {
			//이번 단어를 넣을시의 최적값 저장
			int ifUsed = restore(next, used + (1 << next)) +overlapList[last][next];
			//이 단어가 진짜 최적값으로 가는 길일때 단어가 포함된것
			if (ifUsed == restore(last, used)) {
				//문자가 겹치는게 끝나는 부분부터 끝까지 처리한다
				//debugContent: overlap이 next길이와 같다면?
				return (wordList[next].substr(overlapList[last][next]) + decode(next, used + (1 << next)));
			}
		}
	}
	return "SomeThing Worng";
}