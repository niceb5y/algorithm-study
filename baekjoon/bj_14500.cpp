#include <iostream>
#include <algorithm>

using namespace std;

/*
problem:

폴리오미노란 크기가 1×1인 정사각형을 여러 개 이어서 붙인 도형이며, 다음과 같은 조건을 만족해야 한다.

정사각형은 서로 겹치면 안된다.
도형은 모두 연결되어 있어야 한다.
정사각형의 꼭짓점끼리 연결되어 있어야 한다. 즉, 변과 꼭짓점이 맞닿아있으면 안된다.
정사각형 4개를 이어 붙인 폴리오미노는 테트로미노라고 하며, 다음과 같은 5가지가 있다.

ㅡ   ,ㅁ    ,ㄴ     ,ㄴㄱ      ,ㅜ

아름이는 크기가 N×M인 종이 위에 테트로미노 하나를 놓으려고 한다. 종이는 1×1 크기의 칸으로 나누어져 있으며, 각각의 칸에는 정수가 하나 쓰여 있다.

테트로미노 하나를 적절히 놓아서 테트로미노가 놓인 칸에 쓰여 있는 수들의 합을 최대로 하는 프로그램을 작성하시오.

테트로미노는 반드시 한 정사각형이 정확히 하나의 칸을 포함하도록 놓아야 하며, 회전이나 대칭을 시켜도 된다.

input:
첫째 줄에 종이의 세로 크기 N과 가로 크기 M이 주어진다. (4 ≤ N, M ≤ 500)
둘째 줄부터 N개의 줄에 종이에 쓰여 있는 수가 주어진다. i번째 줄의 j번째 수는 위에서부터 i번째 칸, 왼쪽에서부터 j번째 칸에 쓰여 있는 수이다. 입력으로 주어지는 수는 1,000을 넘지 않는 자연수이다.

output
첫째 줄에 테트로미노가 놓인 칸에 쓰인 수들의 합의 최댓값을 출력한다.

*/



int field[501][501];

int N,M;
int before_move; // 0 : up , 1 : right, 2 : down, 3 : left
int exShape(int x, int y);
int move(int x,int y);
int temp;
int main(void)
{
	int mx = 0;
	cin>>N>>M;
	for(int i = 0 ; i < N ; i++)
		for(int j = 0 ; j < M ; j++)
			cin>>field[i][j];
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < M ; j++){
			int sum = field[i][j];
			int row = i;
			int col = j;
			before_move = -1;
			for(int k = 0 ; k < 3 ; k++){
				int value;
				int rs = move(row,col);
				if(rs == 0){ value = field[row-1][col];row--;}
				else if(rs == 1){ value = field[row][col+1];col++;}
				else if(rs == 2){ value = field[row+1][col];row++;}
				else if(rs == 3){ value = field[row][col-1];col--;}
				sum += value;
				before_move = rs;
			}
			sum = max(exShape(i, j),sum);
			if(mx < sum)	mx=sum;
		}
	}
	cout<<mx;
}


int move(int row, int col)
{
	int result;
	int max = 0;
	//case up:
	if(before_move != 2 && row - 1 >= 0 && max < field[row - 1][col]){ 
		result = 0;
		max = field[row - 1][col];
	}
	//case right:
	if(before_move != 3 && col + 1 < M && max < field[row][col + 1] ){ 
		result = 1;
		max = field[row][col + 1];
	}
	//case down
	if(before_move != 0 && row + 1 < N && max < field[row + 1][col]){ 
		result = 2;
		max = field[row + 1][col];
	}
	//case left
	if(before_move != 1 && col - 1 >= 0 && max < field[row ][col - 1] ){ 
		result = 3;
		max = field[row ][col - 1];
	}
	return result;
}

int exShape(int x, int y){
    int ans = 0;
    // ㅗ모양
    if(x>=1 && y>=1 && y<M-1)
        ans = max(ans, field[x][y]+field[x-1][y]+field[x][y-1]+field[x][y+1]);
    // ㅜ모양
    if(x<N-1 && y>=1 && y<M-1)
        ans = max(ans, field[x][y]+field[x+1][y]+field[x][y-1]+field[x][y+1]);
    // ㅏ모양
    if(x<N-1 && x>=1 && y<M-1)
        ans = max(ans, field[x][y]+field[x+1][y]+field[x-1][y]+field[x][y+1]);
    // ㅓ모양
    if(x<N-1 && x>=1 && y>=1)
        ans = max(ans, field[x][y]+field[x+1][y]+field[x-1][y]+field[x][y-1]);
    return ans;
}


/*
sol:
아 이 짜증나는 문제. 대부분의 사람들이 dfs로 풀었는데 나는 greedy로 풀었다.
5가지 모양중에서 ㅜ 모양 빼고는 30~40분 만에 짰다.
문제는 ㅜ 모양인데 어떻게든 얘도 greedy로 풀고 싶어서 2번째 전진했을때의 두번째 큰값과 3번째 전진했을때의 값과 비교하는 형식으로 했는데 시간 초과 오류가 나서 어떻게든 수정하려다가 포기했다.

좀 쉽게 생각했어야했는데
그냥 ㅜ를 예외처리 하면 쉽게 풀리는 문제였다.



*/
