#include <iostream>
#include <utility>

using namespace std;
char board[100][100];
void sol();
bool isSame(pair<int,int> pos1, pair<int,int> pos2);
int getLength(pair<int,int> pos1, pair<int,int> pos2,int flag);

int flag; // 0 : horizontal , 1 : vertical
int maxNum = 0;
int main(void)
{
	for(int i = 0 ; i < 10 ; i++)
	{
	int tc;
	cin>>tc;
	for(int row = 0 ; row < 100;row++)
	{
		for(int col = 0 ; col < 100 ; col++)
		{
			cin >>board[row][col];
		}
	}
	sol();
	cout<<"#"<<tc<<" "<<maxNum<<endl;
	maxNum = 0;
	}
}

void sol()
{
	flag = 0;
	char before = 'x';
	int length;
	for(int row = 0 ; row < 100 ; row++)
	{
		for(int col = 0 ; col < 100  ; col++)
		{
			if(board[row][col] == board[row][col+1])
			{
				length = getLength(make_pair(row,col),make_pair(row,col+1), flag);
				if(maxNum < length)
				{
					maxNum = length;
				}
			}
			else if(before == board[row][col+1])
			{
				length = getLength(make_pair(row,col-1),make_pair(row,col+1), flag) + 1;
				if(maxNum < length)
				{
					maxNum = length;
				}
			}
			before = board[row][col];
		}
		before = 'x';
	}
	flag = 1;
	before = 'x';
	for(int col = 0 ; col < 100 ; col++)
	{
		for(int row = 0 ; row < 100 ; row++)
		{
			if(board[row][col] == board[row + 1][col])
			{
				length = getLength(make_pair(row,col),make_pair(row+1,col), flag);
				if(maxNum < length)
				{
					maxNum = length;
				}
			}
			else if(before == board[row + 1][col])
			{
				length = getLength(make_pair(row-1,col),make_pair(row+1,col), flag) + 1;
				if(maxNum < length)
				{
					maxNum = length;
				}
			}
			before = board[row][col];
		}
		before = 'x';
	}
}

bool isSame(pair<int,int> pos1, pair<int,int> pos2)
{
	if(board[pos1.first][pos1.second] == board[pos2.first][pos2.second])
	{
		return true;
	}
	else
	{
		return false;
	}
}

int getLength(pair<int,int> pos1, pair<int,int> pos2,int flag)
{
	int length = 2;
	if(pos1.first < 0 || pos1.second < 0 || pos2.first >  99 || pos2.second > 99)
	{
		return 0;
	}
	else if(isSame(pos1,pos2) == false)
	{
		return 0;
	}
	if(flag == 0)
	{
		length += getLength(make_pair(pos1.first,pos1.second-1),make_pair(pos2.first,pos2.second+1),flag);
		return length;
	}
	else
	{
		length += getLength(make_pair(pos1.first-1,pos1.second),make_pair(pos2.first+1,pos2.second),flag);
		return length;
		
	}
}
