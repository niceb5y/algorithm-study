#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int board;
vector<short> cache;
vector<int> tilingTypes;
int cellBinaring(int x, int y);
void makeCase();
short gaming(int board);
//게임의 필승법을 찾는 동적 계획법
int main() {
	int testcase;
	cin >> testcase;
	//타일을 덮는 모든 경우의 수 만들어 놓기
	makeCase();
	cache = vector<short>(1 << 25 ,-1);
	for (int trial = 0; trial < testcase; trial++) {
		board = 0;
		string inputStream;
		//25개의칸이 모두 덮혀있거나 않을경우의 수 2의 25승만큼 경우의 수가 있다
		for (int i = 0; i < 5; i++) {
			cin >> inputStream;
			for (int j = 0; j < inputStream.size(); j++) {
				if (inputStream[j] == '#') {
					board = board | (1 << (i * 5 + j));
				}
			}
		}
		if (gaming(board)) {
			cout << "WINNING" << endl;
		}
		else{
			cout << "LOSING" << endl;
		}
	}
	return 0;
}

int cellBinaring(int x, int y)
{
	return 1<<(5*x+y);
}

void makeCase()
{
	//3칸짜리 타일 경우
	//x,y 좌표
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			vector<int> squareCells;
			int square = 0;
			//좌표별 사각형에서 한곳만 뺀다
			for (int x = 0; x < 2; x++) {
				for (int y = 0; y < 2; y++) {
					squareCells.push_back(cellBinaring(i + x, j + y));
					square += cellBinaring(i + x, j + y);
				}
			}
			for (int i = 0; i < 4; i++) {
				tilingTypes.push_back(square - squareCells[i]);
			}
		}
	}
	//2칸짜리 타일일경우
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 4; j++) {
			tilingTypes.push_back(cellBinaring(i, j) + cellBinaring(i, j + 1));
			tilingTypes.push_back(cellBinaring(j, i) + cellBinaring(j + 1, i));
		}
	}
}
//판이 주어질때 내가 막타칠수 있는지 여부
short gaming(int board)
{
	short& memo = cache[board];
	if (memo != -1) {
		return memo;
	}
	memo = 0;
	for (int i = 0; i < tilingTypes.size(); i++) {
		//겹치는게 하나도 없을시
		if (!(board & tilingTypes[i])) {
			//상대가 이길수 없다면
			if (!gaming(board | tilingTypes[i])) {
				//내가 이긴다
				memo = 1;
				break;
			}
		}
	}
	return memo;
}
