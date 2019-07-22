#include <iostream>
#include <utility>
#include <cstring>

using namespace std;
int move_col[4] = {0,0,-1,1};
int move_row[4] = {-1,1,0,0};
//위 아래 왼쪽 오른쪽
pair<int,int> start,fin;
bool find_flag;
char map[16][16];
void dfs(pair<int,int> pos);
int main(void)
{
	int trash;
	for(int tc = 0 ; tc < 10 ; tc++)
	{
		memset(map,0,sizeof(map));
		find_flag = false;
		cin>>trash;
		for(int row = 0 ; row < 16 ; row++)
		{
			for(int col = 0 ; col < 16 ; col++)
			{
				cin>>map[row][col];
				if(map[row][col] == '2'){
					start = make_pair(row,col);
				}
				else if(map[row][col] == '3')
				{
					fin = make_pair(row,col);
				}
			}
		}
		dfs(start);
		cout<<"#"<<trash<<" "<<find_flag<<endl;
	}
	
}

void dfs(pair<int,int> pos)
{
	if(pos.first < 0 || pos.first > 15 || pos.second < 0 || pos.second > 15)
		return;
	if(map[pos.first][pos.second] == '3')
	{
		find_flag = true;
		return;
	}
	else if(map[pos.first][pos.second] == '1')
	{
		return;
	}
	for(int i = 0 ; i < 4 ; i++){
		int next_row = pos.first + move_row[i];
		int next_col = pos.second + move_col[i];
		map[pos.first][pos.second] = '1';
		dfs(make_pair(next_row,next_col));
		map[pos.first][pos.second] = '0';
	}
}
