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
//���� Ž��
//���� Ž���� ���İ� �ʿ䰡 ���� �κ��� ���� �������ν� �ð��� �����ϴ� ���
//������ȹ���� �޸������̼��� ������ ������� �õ�
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
//���� 90�� ������
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

//4���� ȸ���� ��ǥ�� ����
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
					//�����ǥ �ֱ�
					allBlockCase[rot].push_back(make_pair(i - topX, j - topY));
				}
			}
		}
		block = rotate(block);
	}
	//unique�� �ٷξ��� ���ҿ� ���ٸ� �� ������ �̵���Ű�� �� ��ǥ�� ��ȯ�Ѵ�.
	//�ߺ��� ���Ұ� �ٷ� �ڿ� �̾����� ���Ľ�Ų��
	sort(allBlockCase.begin(), allBlockCase.end());
	//unique���ͷ� �ɷ��� ���ҵ���� ������ �����
	allBlockCase.erase(unique(allBlockCase.begin(), allBlockCase.end()), allBlockCase.end());

}
//�Ϲ����� ��üŽ�� �˰������� �����Ѵ�
void playBoard(int nowPutted, int voidArea)
{
	//�޸���ƽ���
//Ư�� ������ ��ȭ�ؼ� ������¿����� �����غ��� �ξ� ������ ��츦 ��ȯ�Ѵ� �̸� ������ �޸���ƽ�̶��Ѵ�
//�ξ� ������ �� ��츶�� ���ǿ� �����ϴٸ� Ž���غ� ��ġ�� ����
//���� ��츦 ��ȯ�ϴ� ���� ������ �޸���ƽ ���� ��츦 ��ȯ�ϴ� ���� ������ �޸���ƽ�̶��Ѵ�
//���⼱ ���� �ɰ��� ������ �ִٰ� �����Ѵ�. �������� ���� ����� ���� ��ȯ�ŹǷ� ������ �޸���ƽ�̴�
	if (voidArea < allBlockCase[0].size()) {
		best = max(best, nowPutted);
		//�ɰ��� �־ �� ��������ŭ�� ��ĭ�� ������ ��ȯ
		return;
	}
	//�ɰ��� �־ �ִ�ġ���� ���ϸ� ��ȯ
	if (voidArea / allBlockCase[0].size() + nowPutted < best) {
		return;
	}
	//������� ��ĭ ã��
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
	//�������: ���ĭ�� ����������
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
	//��� ĭ�� ä�� �ʿ� ����. �� ĭ�� ä���� �ʱ�� �����غ���
	board[topX][topY] = 1;
	playBoard(nowPutted, voidArea - 1);
	board[topX][topY] = 0;
}
bool blockSet(int x, int y, vector<pair<int, int>> inputBlock, bool mode)
{
	//������ �Ҷ�
	if (mode) {
		for (int block = 0; block < inputBlock.size(); block++) {
			//���� �̸��Ͻ�
			if (x + inputBlock[block].first < 0 || y + inputBlock[block].second < 0) {
				return false;
			}
			//���� �ʰ��Ͻ�
			if (x + inputBlock[block].first >= board.size() || y + inputBlock[block].second >= board[0].size()) {
				return false;
			}
			//����������
			if (board[x + inputBlock[block].first][y + inputBlock[block].second]) {
				return false;
			}
		}
	}
	//������ ������ ������ �Ϸ�
	for (int i = 0; i < inputBlock.size(); i++) {
		board[x + inputBlock[i].first][y + inputBlock[i].second] = !board[x + inputBlock[i].first][y + inputBlock[i].second];
	}
	return true;
}
