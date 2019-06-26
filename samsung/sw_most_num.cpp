#include <iostream>

using namespace std;

int array[1000];
int main(void)
{
	int test;
	int max = 0;
	cin>>test;
	for(int i = 0 ; i < test ; i++){
		fill(array,array+1000,0);
		int temp;
		cin>>temp;
		for(int j = 0 ; j < 1000 ; j++){
			int index;
			cin>>index;
			array[index]++;
		}
	for(int i = 1 ; i < 1000 ; i++){
		if(array[max] <= array[i]){
			max = i;
		}
	}
	cout<<"#"<<temp<<" "<<max<<endl;
	max = 0;
	}
	
}
