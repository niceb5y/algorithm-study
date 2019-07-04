#include <iostream>

using namespace std;

char board[8][8];
int ans = 0;
int size;
int ispalin_horizontal(int row,int col,int size);
int ispalin_vertical(int row,int col,int size);
int main(void)
{
	for(int num = 0 ; num < 10 ; num++){
		cin>>size;
		for(int row = 0 ; row < 8 ; row++){
			for(int col = 0 ; col < 8 ; col++){
				cin>>board[row][col];
			}
		}
		for(int i = 0 ; i < 8; i++){
			for(int j = 0 ; j <8- size+1 ; j++){
				ans += ispalin_horizontal(i,j,size);
				//cout<<"row :"<<i<<" col :"<<j<<" #horizontal "<<ispalin_horizontal(i,j,size)<<endl;
				ans += ispalin_vertical(j,i,size);
				//cout<<"row :"<<j<<" col :"<<i<<" #vertical "<<ispalin_vertical(i,j,size)<<endl;
			}
		}
		cout<<"#"<<num+1<<" "<<ans<<endl;
		ans = 0;
	}
}

int ispalin_horizontal(int row,int col,int size)
{
	for(int i = 0 ; i < size / 2 ; i++){
		if(board[row][col+i] != board[row][col+ size - i-1]){
			return 0;
		}
	}
	return 1;
}

int ispalin_vertical(int row,int col,int size)
{
	int res = 0;
	for(int i = 0 ; i < size / 2 ; i++){
		if(board[row + i][col] != board[row+ size - i-1][col]){
			return 0;
		}
	}
	return 1;
}
