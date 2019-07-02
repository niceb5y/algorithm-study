#include <iostream>

using namespace std;

int map[100][100];
int move(int *y,int * x);
bool left_flag = false;
bool right_flag = false;
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
			ans = start_x;
		do{
				if(map[y][x] == 2){
					goto END;
				}
			}while(move(&y,&x) == 0);
		}
		END:
		cout<<"#"<<tc<<" "<<ans<<endl;
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

/*
조건을 이상하게 처리했다.일단 X,Y도 바꿔서 처리해서 좀 오래걸리고
map[y][x]가 2인경우에도 그쪽으로 가야하는데 그것도 처리 안하고, *x - 1 > 0 이렇게 해서 0인 부분에는 접근도 안하고  쉬웠는데 이상한거에 발목을 많이 잡혔다.

*/
