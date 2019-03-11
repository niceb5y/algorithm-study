#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

/*
problem:
인터넷 방송 KOI(Korea Open Internet)의 음악 프로그램 PD 인 남일이는 자기가 맡은 프로그램 '뮤직 KOI' 에서 가수들의 출연 순서를 정하는 일이 골치 아프다. 순서를 정하기 위해서는 많은 조건을 따져야 한다.

그래서 오늘 출연 예정인 여섯 팀의 가수들에 대해서 남일이가 보조 PD 세 명에게 각자 담당한 가수들의 출연 순서를 정해오게 하였다. 보조 PD 들이 가져온 것은 아래와 같다.

1 4 3
6 2 5 4
2 3
첫 번째 보조 PD 는 1 번 가수가 먼저, 다음에 4 번 가수 , 다음에 3 번 가수가 출연하기로 순서를 정했다. 두 번째 보조 PD 는 6 번 , 2 번, 5 번, 4 번 순으로 자기 담당 가수들의 순서를 정해왔다. 마지막으로 세 번째 보조 PD 는 2 번 먼저, 다음에 3 번 순으로 정해 왔다.

남일이가 할 일은 이 순서들을 모아서 전체 가수들의 순서를 정하는 것이다. 남일이가 잠시 생각을 하더니 6 2 1 5 4 3 으로 순서를 정했다. 이렇게 가수 순서를 정하면 세 보조 PD 가 정해온 순서를 모두 만족한다. 물론 , 1 6 2 5 4 3 으로 전체 순서를 정해도 괜찮다.

경우에 따라서 남일이가 모두를 만족하는 순서를 정하는 것이 불가능 할 수도 있다. 예를 들어, 세 번째 보조 PD 가 2 3 대신에 3 2 로 순서를 정해오면 남일이가 전체 순서를 정하는 것이 불가능 하다.

이번에는 남일이가 우리 나라의 월드컵 4 강 진출 기념 음악제의 PD 를 맡게 되었는데 , 출연가수가 아주 많다. 이제 여러분이 해야 할 일은 보조 PD 들이 가져온 순서들을 보고 남일이가 가수 출연 순서를 정할 수 있도록 도와 주는 일이다.

보조 PD 들이 만든 순서들이 입력으로 주어질 때 , 전체 가수들의 순서를 정하는 프로그램을 작성하시오.

프로그램의 실행시간은 3 초를 초과할 수 없다.

input:
첫 째줄에는 가수들의 수 N 과 보조 PD 들의 수 M 이 주어진다. 가수들은 번호 1 , 2 , ... , N 으로 표시한다.
둘째 줄 부터 각 보조 PD 가 정한 순서들이 한 줄에 하나씩 나온다.
각 줄의 맨 앞에는 보조 PD 가 담당한 가수들의 수가 나오고
그 뒤로는 그 가수들의 순서가 나온다. N 은 1 이상 1,000 이하의 정수이고 , M 은 1 이상 100 이하의 정수이다.


output:
출력은 N 개의 줄로 이뤄지며 , 한 줄에 하나의 번호를 출력한다.
이들은 남일이가 정한 가수들의 출연 순서를 나타낸다. 답이 여럿일 경우에는 아무거나 하나를 출력한다. 만일 남일이가 정하는 것이 불가능할 경우에는 첫째 줄에 0 을 출력한다.

*/

using namespace std;

int array[1001][1001];
int indgree[1001];
int N,M;
vector<int> q;
void d_edge(int n);
void add_queue();
int main(void)
{
	indgree[0] = -1;
	cin>>N>>M;
	int num,temp,before;
	for(int i = 0 ; i < M ; i++){
		cin>>num;
		cin>>before;
		for(int j = 0 ; j < num - 1 ; j++){
			cin>>temp;
			if(before == temp){
				continue;
			}
			array[before][temp] = 1;
			before = temp;
		}
	}
	for(int i = 1 ; i < N+1 ; i++){
		int sum = 0;
		for(int j = 1; j < N + 1 ; j++){
			sum += array[j][i];
		}
		indgree[i] = sum;
	}
	
	for(int i = 0 ; i < N ; i++){
		add_queue();
		if(i  >= q.size())
			break;
		d_edge(q.at(i));
	}
	if(q.size() != N)
		cout<<"0"<<endl;
	else{
		for(int i = 0  ; i < q.size() ; i++)
			cout<<q.at(i)<<endl;
	}
		
}

void d_edge(int n){
	for(int i = 1 ; i <= N ; i++){
		if(array[n][i] != 0)
			indgree[i] -= array[n][i];
		array[n][i] = 0;
	}
}

void add_queue(){
	for(int i = 1 ; i <= N ; i++){
		if(indgree[i] == 0){
			q.push_back(i);
			indgree[i] = -1;
			break;
		}
	}
}


/*
sol:
위상정렬 문제이다. 위상정렬이란 일의 순서를 정하는 것이다.
위상정렬 문제를 푸는 방법은 2가지가 있다.
1. dfs를 한 후 거꾸로 출력하는 방법
2. indgree(입력차수)를 이용하는 방법

1번의 방법의 경우 끝나는 순서대로 스택에 넣어서 출력을 하면된다.(cycle 생기는 것도 읽어보기)
2번의 방법은  입력차수가 0인 점을 찾아서 그 점을 queue에 넣어서 푸는 방법이다.
https://jason9319.tistory.com/93
링크에 자세히 설명되어 있다. 스크랩 해놓자

위에 코드는 indgree로 풀었다. indgree를 매번 계산하면 시간이 오래걸릴거같아서 각 간선을 제거할때 indgree 배열을 변경하게 구현하였다.
queue보다는 index로 접근가능한 vector을 사용하였다.



*/

