#include <iostream>
#include <algorithm>

/*
problem:
정수 X에 사용할 수 있는 연산은 다음과 같이 세 가지 이다.

X가 3으로 나누어 떨어지면, 3으로 나눈다.
X가 2로 나누어 떨어지면, 2로 나눈다.
1을 뺀다.
정수 N이 주어졌을 때, 위와 같은 연산 세 개를 적절히 사용해서 1을 만들려고 한다. 연산을 사용하는 횟수의 최솟값을 출력하시오.

input
첫째 줄에 1보다 크거나 같고, 106보다 작거나 같은 정수 N이 주어진다.

output
첫째 줄에 연산을 하는 횟수의 최솟값을 출력한다.


*/


using namespace std;

int sol(int n);
int array[1000000];

int main(void)
{
	int T;
	cin>>T;
	cout<<sol(T) <<endl;
	}


int sol(int n){
	if(n == 1){
		return 0;
	}
	else if( n == 2){
		return 1;
	}
	if(array[n] > 0)
		return array[n];
	if(n % 3 == 0 && n%2 == 0){
		int temp;
		temp = min(sol(n/3) + 1, sol(n/2) + 1) ;
		array[n] = min(temp, sol(n - 1) + 1);
	}
	else if(n%3 == 0){
		array[n] = min(sol(n/3) + 1, sol(n-1) + 1);
	}
	else if(n % 2 == 0){
		array[n] = min(sol(n/2) + 1, sol(n-1) + 1);
	}
	else{
		array[n] = sol(n-1) + 1;
	}
	return array[n];
}

/*
sol
결국 위의 문제의 핵심은 모든 수는 3으로 나누어 떨어지던가, 2로나누어 떨어지던가, 아니면 둘다 아니던가 였다.
그렇기 때문에 3,2 둘다 나누어 떨어지는 경우 두개로 나누어떨어진 경우의 최소값을 가져가고 
3으로 나누어 떨어지는 경우, 2로 나누어 떨어지는 경우 이렇게 문제를 풀면 됬다. 둘 다 아닌경우에는 1을 뺴고

결국에는 dp로 그 전에 결과값을 저장하여 푸는 문제로 어찌보면 dp_basic_1의 피보나치와 매우 유사하다.

*/
