#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stack>

/*
problem:
그래프의 정보(vertex 수, edge 정보)와 시작 정점의 번호가 주어질 때, 깊이우선탐색(DFS)으로 방문할 때 정점의 방문 순서를 출력하는 프로그램을 작성하시오.

input
입력의 첫째 줄에는 정점의 수와 시작정점의 번호가 입력되고, 다음 부터는 정점의 쌍으로 간선(edge)을 표현한다.

정점 수는 최대 10 개이고 , 1 부터 순차적으로 번호가 부여되어 있다.

입력의 끝은 EOF 이다.

output

시작정점에서 방문되는 정점번호를 출력한다. 답이 여러개 존재하는 경우 사전식 순으로 먼저 나오는 것을 출력한다.

*/
void recursion(int start);

using namespace std;

stack<int> s;
int array[11][11];
int num[11];
int main(void)
{
	int vertex,start;
	
	cin>>vertex>>start;
	for(int i = 0 ; i< 11 ; i++){
		for(int j = 0; j < 11 ; j++){
			array[i][j] = -1;
		}
	}
	num[0] = -1;
	for(int i = 1 ; i< 11 ; i++){
		num[i] = 1;
	}
	int i =  0;
	int j = 0;
	while(scanf("%d",&i) != EOF){
		scanf("%d",&j);
		array[i][j] = 1;
		array[j][i] = 1;
	}
	recursion(start);
}

void recursion(int start)
{
	cout<<start<< " ";
	num[start] = -1;
	for(int i = 1 ; i < 11 ; i++){
		if(array[start][i] == 1 && num[i] == 1){
			recursion(i);
		}
	}
}

/*
sol:
기본적인 dfs문제이다, dfs는 stack과 재귀 두 방법으로 풀 수 있는데 위 코드는 재귀로 풀었다.
그래프의 연결 상태를 배열로 표현 한 후 시작정점과 연결된 점들을 방문한다, 방문 후 방문한 표시를 배열을 통해 표시했다.
이렇게 하는 경우 깊이가 깊은 점들부터 모두 방문하게 된다.

*/
