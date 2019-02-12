#include <iostream>
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
