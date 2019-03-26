#include <iostream>


/*
정수 4를 1, 2, 3의 합으로 나타내는 방법은 총 7가지가 있다. 합을 나타낼 때는 수를 1개 이상 사용해야 한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1
정수 n이 주어졌을 때, n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하는 프로그램을 작성하시오.

input:
첫째 줄에 테스트 케이스의 개수 T가 주어진다. 각 테스트 케이스는 한 줄로 이루어져 있고, 정수 n이 주어진다. n은 양수이며 11보다 작다.

output:
각 테스트 케이스마다, n을 1, 2, 3의 합으로 나타내는 방법의 수를 출력한다.

*/
using namespace std;


int dfs(int num);

int main(void)
{
	int T;
	cin>>T;
	for(int i = 0 ; i < T ; i++){
		int temp;
		cin>>temp;
		cout<<dfs(temp)<<endl;
	}
	
}


int dfs(int num)
{
	int result = 0;
	if(num == 0)
		return 1;
	if(num < 0){
		return 0;
	}
	if(num - 1 >= 0){
		result += dfs(num - 1);
	}
	if(num - 2 >= 0){
		result += dfs(num-2);
	}
	if(num-3 >= 0){
		result += dfs(num-3);
	}
	return result;
}

/*
딱 1,2,3을 tree로 하여 dfs를 하면 풀릴거같았는데 딱 풀렸다 
오랜만에 깔끔하게 풀었다


*/

