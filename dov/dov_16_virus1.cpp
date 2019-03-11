#include <iostream>
#include <vector>
#include <stack>


/*

problem:

신종 바이러스인 윔 바이러스는 네트워크를 통해 전파된다. 한 컴퓨터가 윔 바이러스에 걸리면 그 컴퓨터와 네트워크 상에서 연결되어 있는 모든 컴퓨터는 윔 바이러스에 걸리게 된다. 
예를 들어 7대의 컴퓨터가 < 그림 1 > 과 같이 네트워크 상에서 연결되어 있다고 하자. 1번 컴퓨터가 윔 바이러스에 걸리면 윔 바이러스는 2번과 5번 컴퓨터를 거쳐 3번과 6번 컴퓨터까지 전파되어 2, 3, 5, 6 네 대의 컴퓨터는 윔 바이러스에 걸리게 된다. 하지만 4번과 7번 컴퓨터는 1번 컴퓨터와 네트워크 상에서 연결되어 있지 않기 때문에 영향을 받지 않는다.

어느 날 1번 컴퓨터가 윔 바이러스에 걸렸다. 컴퓨터의 수와 네트워크 상에서 서로 연결되어 있는 정보가 주어질 때, 1번 컴퓨터를 통해 윔 바이러스에 걸리게 되는 컴퓨터의 수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에는 컴퓨터의 수가 주어진다. 컴퓨터의 수는 100 이하이고 각 컴퓨터에는 1번부터 차례대로 번호가 매겨진다.
둘째 줄에는 네트워크 상에서 직접 연결되어 있는 컴퓨터 쌍의 수가 주어진다.
이어서 그 수만큼 한 줄에 한 쌍씩 네트워크 상에서 직접 연결되어 있는 컴퓨터의 번호 쌍이 주어진다.
출력
1번 컴퓨터가 윔 바이러스에 걸렸을 때, 1번 컴퓨터를 통해 윔 바이러스에 걸리게 되는 컴퓨터의 수를 첫째 줄에 출력한다.


*/
using namespace std;

vector<int> graph[101];
stack<int> st;
int isvisit[101];
int result = 0;
int main(void)
{
	int num,N;
	cin>>num>>N;
	for(int i = 0 ; i < N ; i++){
		int s,e;
		cin>>s>>e;
		graph[s].push_back(e);
		graph[e].push_back(s);
	}
	st.push(1);
	isvisit[1] = true;
	while(!st.empty()){
		int front = st.top();
		st.pop();
			for(int i = 0 ; i < graph[front].size() ; i++){
				int next = graph[front].at(i);
				if(isvisit[next] == false){
					isvisit[next] = true;
					st.push(front);
					st.push(next);
					result++;
					break;
				}
			}	
	}
	cout<<result<<endl;
}

/*
sol:
가장 기초적인 dfs문제였다.
나는 stack이로 풀었는데
재귀로 푼 답도 있다.
void dfs(int start, int size){
	counter++;
	visit[start] = 1;
	for (int i = 1; i <= size; i++){

		if (visit[i] == 0 && graph[start][i] == 1){
			dfs(i, size);
		}
		
	}
}
*/
