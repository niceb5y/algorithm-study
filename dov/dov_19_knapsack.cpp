#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>


/*
problem:
도둑이 보석상에 침입하여 보석을 훔쳐가려고 한다. 그런데 도둑이 가져 갈수 있는 보석의 무게(n)은 한정되어 있다.

각각의 보석의 무게(weight)와 값(value)을 가지고 있다. 무게 n 으로 어떤 보석을 가져 가는게 가장 많은 이윤(?)을 취할 수 있는 가를 구하는게 문제이다.

단, 보석은 쪼갤 수 있고 종류당 하나씩 있다고 하자.

input:
입력의 첫 줄에는 도둑이 가져갈 수 있는 무게를, 다음 줄에는 보석의 개수, 다음 줄 부터는 각 보석의 무게와 값이 한 줄에 하나씩 입력된다.

output:
첫 줄에는 최대 이윤을 출력한다. 보석의 개수는 최대 1000 개 까지이고 무게와 가치는 모두 정수값이다.
출력은 소수 3 번째 자리에서 반올림하여 2 자리까지 출력한다.

*/
using namespace std;

typedef struct _stone
{
	int weight;
	int value;
	double priority;
}stone;
bool compare(stone a,stone b);

int main(void)
{
	int max,num;
	double result = 0;
	cin >>max;
	cin>>num;
	vector<stone> jewelry;
	for(int i = 0 ; i < num ; i++){
		stone temp;
		cin>>temp.weight;
		cin>>temp.value;
		temp.priority = (double)temp.value / temp.weight;
		jewelry.push_back(temp);
	}
	sort(jewelry.begin(),jewelry.end(), compare);
	int i = 0;
	while(max != 0 && i < jewelry.size()){
		if(max - jewelry.at(i).weight >= 0){
			result += jewelry.at(i).value;
			max -= jewelry.at(i).weight;
		}
		else{
			result += max * jewelry.at(i).priority;
			max = 0;
		}
		i++;
	}
	printf("%.2f",result);
}

bool compare(stone a,stone b){
	return a.priority > b.priority;
}

/*
sol
쪼갤 수 있는 0/1 kanpsack 문제이다.
무게 당 가치가 높은 순으로 정렬하여 풀면 금방 풀린다.

*/
