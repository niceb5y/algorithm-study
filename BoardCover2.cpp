#include "pch.h"
#include <iostream>
#include<vector>
#include<string>
#include <algorithm>
using namespace std;
int x, y, best;
int blockx, blocky;
vector<vector<bool>> board;
vector<vector<bool>> block;
vector<vector<pair<int, int>>> allBlockCase;
vector<vector<bool>> rotate(vector<vector<bool>>& block);
void generate();
void playBoard(int nowPutted,int voidArea);
bool blockSet(int x, int y, vector<pair<int, int>> inputBlock, bool mode);
//조합 탐색
//완전 탐색중 거쳐갈 필요가 없는 부분은 가지 않음으로써 시간을 절약하는 방법
//동적계획법의 메모이제이션이 공간상 어려울경우 시도
int main() {
	int testcase;
	cin >> testcase;
	for (int trial = 0; trial < testcase; trial++) {
		allBlockCase.clear();
		best = 0;
		cin >> x;
		cin >> y;
		board = vector<vector<bool>>(x, vector<bool>(y, 0));
		cin >> blockx;
		cin >> blocky;
		block = vector<vector<bool>>(blockx, vector<bool>(blocky, 0));
		string temp;
		int voidBlock = 0;
		for (int i = 0; i < x; i++) {
			cin >> temp;
			for (int j = 0; j < y; j++) {
				if (temp[j] == '#') {
					board[i][j] = 1;
				}
				else {
					board[i][j] = 0;
					voidBlock++;
				}
			}
		}
		for (int i = 0; i < blockx; i++) {
			cin >> temp;
			for (int j = 0; j < blocky; j++) {
				if (temp[j] == '#') {
					block[i][j] = 1;
				}
				else {
					block[i][j] = 0;
				}
			}
		}
		generate();
		playBoard(0, voidBlock);
		cout << best << endl;
	}
	return 0;
}
//블럭을 90도 돌린다
vector<vector<bool>> rotate(vector<vector<bool>>& block)
{
	vector<vector<bool>> temp = vector<vector<bool>>(block[0].size(), vector<bool>(block.size(), 0));
	for (int i = 0; i < block.size(); i++) {
		for (int j = 0; j < block[0].size(); j++) {
			temp[temp.size() - j - 1][i] = block[i][j];
		}
	}
	return temp;
}

//4방향 회전시 좌표값 생성
void generate()
{
	allBlockCase = vector<vector<pair<int, int>>>(4);
	for (int rot = 0; rot < 4; rot++) {
		int topX = -1; 
		int topY = -1;
		for (int i = 0; i < block.size(); i++) {
			for (int j = 0; j < block[0].size(); j++) {
				if (block[i][j] == true) {
					if (topY == -1) {
						topX = i;
						topY = j;
					}
					//상대좌표 넣기
					allBlockCase[rot].push_back(make_pair(i - topX, j - topY));
				}
			}
		}
		block = rotate(block);
	}
	//unique는 바로앞의 원소와 같다면 맨 끝으로 이동시키고 그 좌표를 반환한다.
	//중복된 원소가 바로 뒤에 이어지게 정렬시킨다
	sort(allBlockCase.begin(), allBlockCase.end());
	//unique필터로 걸러진 원소들부터 끝까지 지운다
	allBlockCase.erase(unique(allBlockCase.begin(), allBlockCase.end()), allBlockCase.end());

}
//일반적인 전체탐색 알고리즘으로 시작한다
void playBoard(int nowPutted, int voidArea)
{
	//휴리스틱기법
//특정 조건을 완화해서 현재상태에서의 최적해보다 훨씬 최적의 경우를 반환한다 이를 낙관적 휴리스틱이라한다
//훨씬 최적인 이 경우마저 조건에 부합하다면 탐색해볼 가치는 없다
//많은 경우를 반환하는 경우는 과대평가 휴리스틱 적은 경우를 반환하는 경우는 과소평가 휴리스틱이라한다
//여기선 블럭을 쪼개서 넣을수 있다고 가정한다. 기존보다 많은 경우의 수가 반환돼므로 과대평가 휴리스틱이다
	if (voidArea < allBlockCase[0].size()) {
		best = max(best, nowPutted);
		//쪼개서 넣어도 다 못넣을만큼의 빈칸이 있으면 반환
		return;
	}
	//쪼개서 넣어도 최대치보다 못하면 반환
	if (voidArea / allBlockCase[0].size() + nowPutted < best) {
		return;
	}
	//좌측상단 빈칸 찾기
	int topX = -1, topY = -1;
	for (int i = 0; i < board.size(); i++) {
		for (int j = 0; j < board[0].size(); j++) {
			if (!board[i][j]) {
				if (topY == -1) {
					topX = i;
					topY = j;
					break;
				}
			}
		}
		if (topY != -1) {
			break;
		}
	}
	//기저사례: 모든칸이 덮여있을때
	if (topY == -1) {
		best = max(best, nowPutted);
		return;
	}
	for (int _case = 0; _case < allBlockCase.size(); _case++) {
		if (blockSet(topX, topY, allBlockCase[_case], 1)) {
			playBoard(nowPutted + 1,voidArea - allBlockCase[_case].size());
			blockSet(topX, topY, allBlockCase[_case], 0);
		}
	}
	//모든 칸을 채울 필요 없다. 이 칸을 채우지 않기로 가정해보자
	board[topX][topY] = 1;
	playBoard(nowPutted, voidArea - 1);
	board[topX][topY] = 0;
}
bool blockSet(int x, int y, vector<pair<int, int>> inputBlock, bool mode)
{
	//덮으려 할때
	if (mode) {
		for (int block = 0; block < inputBlock.size(); block++) {
			//범위 미만일시
			if (x + inputBlock[block].first < 0 || y + inputBlock[block].second < 0) {
				return false;
			}
			//범위 초과일시
			if (x + inputBlock[block].first >= board.size() || y + inputBlock[block].second >= board[0].size()) {
				return false;
			}
			//덮혀있을시
			if (board[x + inputBlock[block].first][y + inputBlock[block].second]) {
				return false;
			}
		}
	}
	//뺄때의 증명은 위에서 완료
	for (int i = 0; i < inputBlock.size(); i++) {
		board[x + inputBlock[i].first][y + inputBlock[i].second] = !board[x + inputBlock[i].first][y + inputBlock[i].second];
	}
	return true;
}
