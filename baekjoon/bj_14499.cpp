#include <iostream>

using namespace std;

int move_row[5] = {0,0,0,-1,1};
int move_col[5] = {0,1,-1,0,0};
int board[20][20];
int size_row,size_col,pos_row,pos_col,command_num;
typedef struct _dice{
	int top;
	int bot;
	int east;
	int west;
	int north;
	int south;
}dice;
dice move(int command,dice now);
dice now;
int main(void)
{
	int command;
	//cin>>size_row>>size_col>>pos_row>>pos_col>>command_num;
	scanf("%d%d%d%d%d",&size_row,&size_col,&pos_row,&pos_col,&command_num);
	for(int row = 0 ; row < size_row ; row++)
	{
		for(int col = 0 ; col < size_col ; col++)
		{
			//cin>>board[row][col];
			scanf("%d",&board[row][col]);
		}
	}
	for(int i = 0 ; i < command_num ; i++)
	{
		//cin>>command;
		scanf("%d",&command);
		pos_row += move_row[command];
		pos_col += move_col[command];
		if(pos_row >= size_row || pos_row < 0 || pos_col >= size_col || pos_col < 0)
		{
			pos_row -= move_row[command];
			pos_col -= move_col[command];
			continue;
		}
		now = move(command,now);
		//cout<<now.top<<endl;
		printf("%d\n",now.top);
		//cout<<"com"<<" "<<command<<" "<<now.top<<endl;
	}
	
}

dice move(int command,dice now)
{
	dice next;
	if(command == 1)
	{
		next.top = now.west;
		next.bot = now.east;
		next.west = now.bot;
		next.east = now.top;
		next.north = now.north;
		next.south = now.south;
	}
	else if(command == 2)
	{
		next.top = now.east;
		next.bot = now.west;
		next.west = now.top;
		next.east = now.bot;
		next.north = now.north;
		next.south = now.south;
	}
	else if(command == 3)
	{
		next.top = now.south;
		next.bot = now.north;
		next.north = now.top;
		next.south = now.bot;
		next.west = now.west;
		next.east = now.east;
	}
	else if(command == 4)
	{
		next.top = now.north;
		next.bot = now.south;
		next.north = now.bot;
		next.south = now.top;
		next.west = now.west;
		next.east = now.east;		
	}
	if(board[pos_row][pos_col] == 0)
	{
		board[pos_row][pos_col] = next.bot;
	}
	else
	{
		next.bot = board[pos_row][pos_col];
		board[pos_row][pos_col] = 0;
	}
	return next;
}

//예외처리만 하자
