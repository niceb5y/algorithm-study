#include <iostream>
#include <algorithm>

using namespace std;

int num[100];
int second_max,second_min;
int first_max = 99;
int first_min = 0;
void get_max_min();
int main(void)
{
	int row,dump,value;
	for(int i = 0 ; i < 10 ; i++){
		cin>>dump;
		for(int j = 0 ; j < 100  ; j++){
			cin>>num[j];
		}
		sort(num, num + 100);
		while(dump > 0){
			sort(num,num+100);
			get_max_min();
			value = abs(min(num[second_min] - num[first_min], num[first_max] - num[second_max]));
			if( value< dump ){
				num[first_min] += value;
				num[first_max] -= value;
				dump -= value;
			}
			else{
				num[first_min] = num[first_min] + dump;
				num[first_max] = num[first_max] - dump;
				break;
			}
		}
		sort(num,num+100);
		cout<<"#"<<i+1<<" "<<num[first_max] - num[first_min]<<endl;
		fill(num,num+100,0);
	}
}

void get_max_min(){
	for(int i = 0 ; i < 100 ; i++){
		if(num[first_max] != num[99-i]){
			second_max = 99-i;
			break;
		}
			
	}
	for(int i = 0 ; i < 100 ; i++){
		if(num[first_min] != num[i]){
			second_min = i;
			break;
		}
			
	}
}
