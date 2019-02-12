#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
int search_next(int N);
int array[1001][1001];
bool isv[1001];
int ss;
void search_start(int N);
int result[1001];
int result_index = 0;

int main(void)
{
	ss = 1;
	int N,M;
	cin>>N>>M;
	int num,temp,before;
	for(int i = 0 ; i < 1000 ; i++)
		isv[i] = false;
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
	int n = 1;
	for(int i = 0 ; i < N ; i++){
		search_start(N); 
		n = search_next(N);
		//cout<<"n"<<n<<"i"<<i<<endl;
		isv[n] = true;
		if(n == 0){
			cout<<n<<endl;
			return 0;
		}
		result[i] = n;
		for(int j = 0 ; j <= N ; j++){
			array[n][j] = 0;
		}
	}
	for(int i = 0 ; i < N ; i++){
		cout<<result[i]<<endl;
	}
	
	
}

int search_next(int N){
	bool isnext = true;
	int i,j;
	for(i = ss ; i <= N ; i++){
		for(j = 1 ; j <= N ; j++){
			if(array[j][i] == 1 ){
				isnext = false;
			}
		}
		if(isnext == true)
			return i;
		isnext = true;
	}
	return 0;
}

void search_start(int N){
	for(int i = ss ; i <= N ; i++){
		if(isv[i] == false){
			ss = i;
			break;
		}
	}
}

