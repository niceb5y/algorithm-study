#include <iostream>
#include <algorithm>

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
