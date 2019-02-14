#include <iostream>
/*
problem:
fibonacci(N)을 호출했을 때, 0과 1이 각각 몇 번 출력되는지 구하는 프로그램을 작성하시오.

input:
첫째 줄에 테스트 케이스의 개수 T가 주어진다.

각 테스트 케이스는 한 줄로 이루어져 있고, N이 주어진다. N은 40보다 작거나 같은 자연수 또는 0이다.

output:
각 테스트 케이스마다 0이 출력되는 횟수와 1이 출력되는 횟수를 공백으로 구분해서 출력한다.

*/


using namespace std;

int num_zero;
int num_one;
int array[100];
int result[100][2];
int fibonacci(int n);
int main(void)
{
	int T;
	cin>>T;
	for(int i = 0 ; i < T ; i++){
		num_zero = 0;
		num_one = 0;
		int temp;
		cin>>temp;
		fibonacci(temp);
		cout<<num_zero<<" "<<num_one<<endl;
	}
}

int fibonacci(int n){
	if( n == 0){
		num_zero++;
		return 0;
	}
	else if(n == 1){
		num_one++;
		return 1;
	}
	else if(array[n] > 0){
		num_zero += result[n][0];
		num_one += result[n][1];
		return array[n];
	}
	else{
		array[n] = fibonacci(n - 1) + fibonacci(n - 2);
		result[n][0] = num_zero;
		result[n][1] = num_one;
		return array[n];
	}
}
/*
sol
피보나치 수열 문제를 재귀로 푸는경우 비효율적이기 떄문에 dp를 이용하여 답을 도출해내는 문제이다.
dp의 핵심은 결국 결과를 저장하여서 그 결과값을 이용하여 문제를 푸는것인데 위 문제에서도 각 피보나치 결과값을 array에 저장하여 풀었다.

여기서 해맷던 부분이 피보나치를 구하는 경우 0과 1이 나오는대로 변수값을 증가시키면 되지만 저장되어 있는 값을 가져오는 경우 0,1의 횟수를 파악하지 못하여 새로운 변수를 만들어서
그 변수에 피보나치를 구한 결과에서의 0,1횟수를 저장하여 저장된 값을 쓰는경우 그 값을 변수에 더하였다.

*/
