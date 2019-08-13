#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<int> xMove = { 0,1,0,-1 };
vector<int> yMove = { -1,0,1,0 };
vector<vector<int>> board;
struct Robot{
	int y, x;
	int face;
} robot;
int cleanArea;
int main() {
	cin >> n;
	cin >> m;
	cin >> robot.y;
	cin >> robot.x;
	cin >> robot.face;
	board = vector<vector<int>>(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
	cleanArea = 0;
	bool moved = false;
	while (true){
		moved = false;
		if (board[robot.y][robot.x] == 0) {
			cleanArea++;
		}
		board[robot.y][robot.x] = 2;
		for (int i = 0; i < 4; i++) {
			robot.face = (robot.face + 3) % 4;
			if (robot.y + yMove[robot.face] >= 0 && robot.y + yMove[robot.face] < n) {
				if (robot.x + xMove[robot.face] >= 0 && robot.x + xMove[robot.face] < m) {
					if (board[robot.y + yMove[robot.face]][robot.x + xMove[robot.face]] == 0) {
						robot.x += xMove[robot.face];
						robot.y += yMove[robot.face];
						moved = true;
						break;
					}
				}
			}
		}
		if (!moved) {
			int backX = 0 - xMove[robot.face], backY = 0 - yMove[robot.face];
			if (robot.x + backX < 0 || robot.x + backX >= m) {
				break;
			}
			if (robot.y + backY < 0 || robot.y + backY >= n) {
				break;
			}
			if (board[robot.y + backY][robot.x + backX] == 1) {
				break;
			}
			robot.x += backX;
			robot.y += backY;
		}
	}
	cout << cleanArea;
	return 0;
}