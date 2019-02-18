#include <iostream>
#include <queue>
#include <algorithm>
/*
problem
4 자리 수 두 개가 입력으로 주어진다. 두 수는 모두 소수(prime number)이다.

처음 수는 출발수 이고 다음 수는 도착수 이다. 어떤 수에서 다음 수로는 이전 수에서 한 자리수 만을 변경해서 가능하다. 물론 각 단계별로 만들어 지는 수도 소수여야 한다.

출발 수에서 도착수로 가는 최단 거리를 구하는 게 문제이다.

예로 , 출발수로 1033 이 도착수로 8179 가 주어지는 경우

1033 에서

1.1733
2.3733
3.3739
4.3779
5.8779
6.8179

6 이 최단거리이다.

input:
4 자리 도착수 , 목적수가 주어진다.
1033 8179

output:
최단거리를 출력한다.
6

*/


using namespace std;

void bfs(int start);

int arr_to_int(int *arr)
{
	int num = arr[0];
	for(int i = 1; i < 4 ; i++){
		num =num*10 + arr[i];
	}
	return num;
}

void int_to_arr(int num,int* arr)
{
	for(int i = 3; i >=0 ; i--){
		arr[i] = num%10;
		num /= 10;
	}
}

bool prime[1000001];
int dist[1000001];
int main(void)
{
	int index = 0;
	int start,end;
	cin>>start>>end;
	for (int i = 2; i <= max(start,end) * 2; i++) {
		if (prime[i] == false) {
			for (int j = i*2; j <= max(start,end) * 2; j += i) {
				prime[j] = true;
			}
		}
	}
	for (int i = 0; i <= max(start,end) * 2; i++) {
		prime[i] = !prime[i];
	}
	bfs(start);
	if(dist[end] == -1){
		cout<<0<<endl;
	}
	else
		cout<<dist[end];
}
  
void bfs(int start)
{
	queue<int> q;
	fill(dist,dist+1000000,-1);
	dist[start] = 0;
	q.push(start);
	int arr[4];
	int num  = q.front();
	while(!q.empty()){
		for(int i = 3; i >= 0 ; i--){
			int_to_arr(num,arr);
			for(int j = 0 ; j <= 9 ; j++){
				arr[i] = j;
				int temp  = arr_to_int(arr);
				if(prime[temp] && dist[temp] == -1 && temp >= 1000)
				{
					dist[temp] = dist[num] + 1;
					//cout<<temp<<" "<<dist[temp]<<endl;
					q.push(temp);
				}
			}
		}
		num = q.front();
		q.pop();
	}
}

/*
일단 소수목록을 구하기위하여 에라토스테네스의 체를 이용한다.
에라토스테네스의 체는 2부터 N-1까지 2의 배수를 거르고 남아있는 숫자들에서 3의 배수를 거르고 이런식으로 제곱근 N까지 나누어서 남은 수들이 소수가 되는 방법이다.
이를 통해서 소소를 구하고  각 자리 숫자를 변경해서 소수인경우 queue에 넣고 다시 그 소수를 queue에서 꺼내서 다시 자리수를 바꿔가며 소수인지 판별하는 bfs문제이다.

처음에는 실수로 에라토스테네스의 체를 end값까지 하였다. 이럴경우 start가 end보다 큰 경우 문제가 발생한다.

*/
