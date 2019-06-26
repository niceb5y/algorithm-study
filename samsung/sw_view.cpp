#include <iostream>
#include <queue>

using namespace std;

int calc(int,int);
int get_index(int,int);

int main(void)
{
	vector<int> input;
	int length;
	for(int i = 0 ; i < 10 ; i++){
		int sum = 0;
		cin>>length;
		for(int i = 0 ; i < 4 ; i++){
			int temp;
			cin>>temp;
			input.push_back(temp);
		}
		for(int i = 4 ; i < length; i++){
			int temp;
			cin>>temp;
			input[i%5] = temp;
			sum = sum + calc(input[get_index(i%5,  -2)],max(max(input[get_index(i%5,- 4)],input[get_index(i%5,-3)]),max(input[get_index(i%5,-1)],input[get_index(i%5,0)])));
		}		
		cout<<"#"<<i+1<<" "<<sum<<endl;
		sum = 0;
		input.clear();
	}
}


int calc(int center,int  near_max)
{
	int res = center - near_max;
	if(res < 0){
		res = 0;
	}

	return res;
}

int get_index(int pivot,int value){
	int index = pivot + value;
	if(index < 0 ){
		index = 5 + index;
	}
	else if (index > 5){
		index = index % 5;
	}
	return index;
}
