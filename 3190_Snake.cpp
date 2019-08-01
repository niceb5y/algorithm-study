#include <iostream>
#include <vector>
using namespace std;

int boardSize, appleNum, dirNum;
vector<int> xMove = {1,0,-1,0};
vector<int> yMove = {0,1,0,-1};
vector<pair<int, int>> appleArray;
vector<pair<int, int>> dirArray;
struct snakeBlock{
	int x, y;
	int tempSecond;
	int way;
};
bool isGameOver();
void moveSnakeBlock(int block);
vector<snakeBlock> snake;
int main() {
	cin >> boardSize;
	cin >> appleNum;
	for (int i = 0,x,y; i < appleNum; i++) {
		cin >> x;
		cin >> y;
		appleArray.push_back(make_pair(y - 1, x - 1));
	}
	cin >> dirNum;
	char b;
	for (int i = 0, a; i < dirNum; i++) {
		cin >> a;
		cin >> b;
		if (b == 'L') {
			dirArray.push_back(make_pair(a, -1));
		}
		else {
			dirArray.push_back(make_pair(a, 1));
		}
	}
	snake.push_back(snakeBlock());
	snake[0].tempSecond = 0;
	snake[0].x = 0;
	snake[0].y = 0;
	snake[0].way = 0;
	while (true){
		snakeBlock endTemp = snake[snake.size() - 1];
		moveSnakeBlock(0);
		if (isGameOver()) {
			cout << snake[0].tempSecond;
			break;
		}
		for (int i = 1; i < snake.size(); i++) {
			moveSnakeBlock(i);
		}
		for (int i = 0; i < appleArray.size(); i++) {
			if (snake[0].x == appleArray[i].first && snake[0].y == appleArray[i].second) {
				snake.push_back(endTemp);
				appleArray.erase(appleArray.begin() + i);
			}
		}
	}
	return 0;
}

bool isGameOver(){
	if (snake[0].x < 0 || snake[0].x >= boardSize) {
		return true;
	}
	if (snake[0].y < 0 || snake[0].y >= boardSize) {
		return true;
	}
	for (int i = 1; i < snake.size(); i++) {
		if (snake[0].x == snake[i].x && snake[0].y == snake[i].y) {
			return true;
		}
	}
	return false;
}

void moveSnakeBlock(int block){
	snake[block].tempSecond++;
	snake[block].x += xMove[snake[block].way];
	snake[block].y += yMove[snake[block].way];
	for (int i = 0; i < dirArray.size(); i++) {
		if (snake[block].tempSecond == dirArray[i].first) {
			snake[block].way = (snake[block].way + 4 + dirArray[i].second) % 4;
			return;
		}
	}
}
