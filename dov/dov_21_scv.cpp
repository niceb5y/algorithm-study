#include <iostream>
#include <algorithm>

using namespace std;

/*
problem:
N * N 크기의 맵이 있다. 이 맵에는 미네랄이 군데군데 매장되어 있어서 당신은 SCV 를 이용해 이 미네랄을 채취하려고 한다.

SCV 는 (1,1) 의 위치에서 출발하여 (N,N)까지 이동하는데, 이 SCV 는 고물이라 오른쪽 또는 아래쪽으로 밖에 움직이지 못한다. 이 SCV 는 무한한 양의 미네랄을 가지고 있을 수 있다고 가정하자. 이 SCV 를 이용해서 최대한 많이 미네랄을 얻도록 하는 프로그램을 작성하시오.


input:
첫 줄에는 맵의 크기 N ( 3 <= N <= 100)이 주어진다.
둘째줄부터는 주어진 지도가 N 줄 만큼 입력된다. (단, 0 은 미네랄 없음, 1 은 미네랄 있음을 의미한다.)
output:
SCV 가 채취할 수 있는 최대 미네랄 양을 출력한다.

*/


int sol(int x,int y);
int array[102][102]; 
int map[102][102];
int N;

int main(void)
{
	cin>>N;
	for(int i = 1 ; i <= N ; i++){
		for(int j = 1 ; j <= N ; j++){
			cin>>map[i][j];
		}
	}
	
	cout<<sol(N,N);
}
	

int sol(int x,int y)
{
	if(x == 0 || y == 0)
		return 0;
	if(x == 1 && y == 1)
		return map[1][1];
	else if(x == 1 && y == 2)
		return map[1][1] + map[2][1];
	else if(x==2 && y == 1)
		return map[1][1] + map[1][2];
		
	if(array[y][x] != 0){
		return array[y][x];
	}
	array[y][x] =max(sol(x-1,y), sol(x,y-1)) + map[y][x];
	return array[y][x];
}

/*
dp에 기본 문제이다.
그 전에 올 수 있는 좌표에서 최대값을 구한 후 그 값을 이용하여 문제를 푼다.

*/
