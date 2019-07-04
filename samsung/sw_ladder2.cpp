#include <iostream>

using namespace std;

int map[100][100];
int move(int *y,int * x);
bool left_flag = false;
bool right_flag = false;
int min_num = 9999;
int main(void)
{
	for(int i = 0 ; i < 10 ; i++){
		int ans = 0;
		int tc;
		cin>>tc;
		for(int y = 0 ; y <100; y++){
			for(int x = 0 ; x <100 ; x++){
				cin>>map[y][x];
			}
		}
		for(int start_x = 0 ; start_x < 100 ; start_x++){
			if(map[0][start_x] == 0)
				continue;
			int x = start_x;
			int y = 0;
			int num = 0;
			while(move(&y,&x) == 0){
				num++;
			}
			if(num < min_num){
				min_num = num;
				ans = start_x;
			}
		}
		
		cout<<"#"<<tc<<" "<<ans<<endl;
		min_num = 9999;
		left_flag = false;
		right_flag = false;
	}
}


int move(int *y,int * x){
	if(*x + 1 < 100  && (map[*y][*x+1] == 1 || map[*y][*x+1] == 2)&& left_flag == false){
		left_flag = false;
		right_flag = true;
		*x = *x + 1;
		return 0;
	}
	else if(*x - 1 > -1 && (map[*y][*x - 1] == 1 || map[*y][*x - 1] == 2) && right_flag == false){
		left_flag = true;
		right_flag = false;
		*x = *x - 1;
		return 0;
	}
	else if(*y + 1 < 100 && (map[*y+1][*x] == 1 || map[*y+1][*x] == 2)){
		*y = *y + 1;
		left_flag = false;
		right_flag  = false;
		return 0;
	}
	else{
		return -1;
	}
}
