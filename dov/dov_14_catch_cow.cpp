#include <iostream>
#include <queue>
#include <utility>
using namespace std;

/*
problem:
농부 존의 소 중에서 한 마리가 집이 싫어 도망갔다. 그는 이 소를 즉시 잡아들이고 싶어한다.

그는 1 에서 N ( 0 <= N <= 100,000 ) 지점중에서 시작하고 소는 K ( 0 <= K <= 100,000) 번째 지점에 위치한다.

존은 두가지의 능력을 가지고 있고 이를 하는데 1 분이 걸린다.

걷거나 ... 현재 지점-1 혹은 현재지점+ 1
순간이동 ... 현재지점 * 2 배 위치로 이동
소는 존이 잡으러 오는 것을 눈치채지 못해서 다른 장소로 이동하지 않는다고 가정한다.

input:
N , K 가 입력으로 주어진다.
output
소들을 잡는데 걸리는 최소 시간(분)을 출력한다.

*/




typedef pair<int,int> node;
bool isvisit[100001];
queue<node> q;

int main(void)
{
	int s,e;
	cin>>s>>e;
	if(e<s){
		cout<< s-e<<endl;
		return 0;
	}
	node start = make_pair(0,s);
	q.push(start);
	isvisit[s] = true;
	while(!q.empty())
	{
		node next = q.front();
		q.pop();
		if(next.second == e){
			cout<<next.first;
			break;
		}
		int n = next.first;
		int v = next.second;
		node temp = make_pair(n+1,v+1);
		if(v+1 < 100000&&isvisit[v+1] == false){
			q.push(temp);
			isvisit[v+1] = true;
		}
		if(v-1 > 0 &&isvisit[v-1] == false){
			temp = make_pair(n+1,v-1);
			q.push(temp);
			isvisit[v-1] = true;
		}
		if(v*2 < 100000&&isvisit[v*2] == false){
			temp = make_pair(n+1,v*2);
			q.push(temp);
			isvisit[v*2] = true;
		}
	}
}


/*
sol:
기본적인 bfs문제여서 queue를 이용하여 바로 풀었다.
제출하니 어느정도 되다가  여러가지에서 문제가 발생했다.
1. start가 end보다 큰경우
2.    큰 숫자가 들어오는 경우
최적화를 안해서 시작값과 끝값의 차이가 많이 나는 경우 중복된 숫자들도 계속 들어와서 시간초과가 발생하였다.
3.단축평가
처음에는 중복 검사만 하였더니 segmentaion fault가 발생하였다.
그래서 범위검사도 넣었다.
문제는 내가 isvisit[v*2] == false && v*2 < 100000 이런식으로 하였는데
v*2가 어떤값이든 isvisit을 검사하기떄문에 계속 segmentaion fault가 발생하였다. 순서만 바꿔주면 되는것을...


*/
