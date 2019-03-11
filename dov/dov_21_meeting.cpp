#include <iostream>


/*

problem:
하나의 회의실이 있고, 여러 회의들이 예약되어 있다.

회의실에서는 같은 시간에 하나의 회의만 가능하다. 예약된 회의들이 서로 시간이 겹치는 경우가 많기 때문에 서로 겹치지 않으면서 가능한 많은 회의들을 배정하고 싶다.

각 회의들의 시작시간과 종료 시간이 주어질 때 , 가장 많은 회의를 배정하는 프로그램을 작성하라. 회의실에 배정된 회의의 종료시간과 다른 회의 시간이 같아도 겹치지 않는 것으로 한다.

단, 시간은 0 이상 24 이하이다. 데이터는 종료시간을 기준으로 오름차순 정렬되어 입력된다.

input:
예약된 회의의 수 N(1000 이하의 정수)이 첫 줄에 주어진다.
둘째 줄부터는 N 개의 회의들에 대한 시작 시간과 종료 시간이 주어진다.
output:
회의실에 배정한 회의의 최대 수를 출력한다.


*/

using namespace std;

int main(void)
{
	int N;
	int array[25];
	fill(array,array+25,0);
	cin>>N;
	int s,e,p;
	p = 0;
	for(int i = 0 ; i < N ; i++){
		cin>>s>>e;
		if(p == e){
			array[e] = max(max(array[e - 1],array[s] + 1),array[e]);
			continue;
		}
		for(int j = p + 1 ; j < e ; j++ ){
				array[j] = array[j-1];
		}
		array[e] = max(array[e - 1],array[s] + 1);
		p = e;
	for(int i = 0 ; i < 25 ; i++)
	cout<<i<<" ";
	cout<<endl;
	for(int i = 0 ; i < 25 ; i++)
	cout<<array[i]<< " ";
	cout<<endl;
	}
	cout<<array[e];
}

/*
sol
회의가 포함되는 경우, 안되는 경우로 나누어서 풀었다.
end time순으로 정렬하여 풀었다.
*/
