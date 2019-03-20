#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
problem:
왕비를 피해 일곱 난쟁이들과 함께 평화롭게 생활하고 있던 백설공주에게 위기가 찾아왔다. 일과를 마치고 돌아온 난쟁이가 일곱 명이 아닌 아홉 명이었던 것이다.

아홉 명의 난쟁이는 모두 자신이 "백설 공주와 일곱 난쟁이"의 주인공이라고 주장했다. 뛰어난 수학적 직관력을 가지고 있던 백설공주는, 다행스럽게도 일곱 난쟁이의 키의 합이 100이 됨을 기억해 냈다.

아홉 난쟁이의 키가 주어졌을 때, 백설공주를 도와 일곱 난쟁이를 찾는 프로그램을 작성하시오.

input
아홉 개의 줄에 걸쳐 난쟁이들의 키가 주어진다. 주어지는 키는 100을 넘지 않는 자연수이며, 아홉 난쟁이의 키는 모두 다르며, 가능한 정답이 여러 가지인 경우에는 아무거나 출력한다.

output:
일곱 난쟁이의 키를 오름차순으로 출력한다. 일곱 난쟁이를 찾을 수 없는 경우는 없다.
 
 */


int array[9];
bool isvisit[9];
int sum = 0;
vector<int> ans;

void resolve(int n)
{
	int num = 0;
	if(n > 8 || ans.size() >= 7){
		return;
	}
	for(int i = n ; i < 9 ; i++){
		if(isvisit[i] == false){
			num++;
			isvisit[i] = true;
			sum = sum + array[i];
			ans.push_back(array[i]);
			resolve(i+1);
			if(sum == 100 && ans.size() == 7){
				return;
			}
			sum = sum - array[i];
			ans.pop_back();
		}
	}
	for(int i = n ; i < 9 ; i++)
		isvisit[i] = false;
}

int main(void)
{
	for(int i = 0 ; i < 9 ; i++){
		cin>>array[i];
	}
	resolve(0);
	sort(ans.begin(),ans.end());
	for(int i = 0 ; i < ans.size() ; i++){
		cout<<ans[i]<<endl;
	}
	return 0;
}

/*
sol:

처음에 문제를 보고 더블릿의 체스팀 구성과 비슷해서 dp로도 풀수 있을줄 알았는데 생각해보니깐 그 문제는 최고값을 구하는 문제이고
이 문제는 특정값을 추출하는거라서 dp로 풀수는 없었다.
방법은 완전 탐색인데....
나는 일일이 9개 중 7개를 뽑는 모든 경우에 수를 구해서 풀었는데 
머리가 나쁘면 몸이 고생한다고
다른사람들의 풀이법을 보면
총합에서 2명을 뽑아서 뺀게 100인 조합을 찾게 풀었다.

*/
