#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

int board[9][9];
int temp[9][9];
bool visit[9][9];
int N,M;
queue<int> q;
int maxNum = -1;
typedef struct _pos{
	int row;
	int col;
}pos;
void sol();
void infection(int row, int col); //0:위 1:오른쪽 2:아래 3: 왼쪽
int getSafe();
void test();
vector<pos> v;
vector<pos> d;
int main(void)
{
	cin>>N>>M;
	pos candidate;
	for(int row = 0 ; row < N ; row++)
	{
		for(int col = 0 ; col < M ; col++)
		{
			cin>>board[row][col];
			if(board[row][col] == 0)
			{
				candidate.row = row;
				candidate.col = col;
				v.push_back(candidate);
			}
			else if(board[row][col] == 2)
			{
				candidate.row = row;
				candidate.col = col;
				d.push_back(candidate);
			}
		}
	}
	memcpy(temp,board,sizeof(board));
	sol();
	cout<<maxNum<<endl;
}


void sol()
{
	int sa;
	for(int i = 0 ; i < v.size() - 2 ; i++)
	{
		for(int j = i + 1 ; j < v.size() - 1 ; j++)
		{
			for(int k = j + 1 ; k < v.size() ; k++)
			{
				temp[v[i].row][v[i].col] = 1;
				temp[v[k].row][v[k].col] = 1;
				temp[v[j].row][v[j].col] = 1;
				memset(visit,false,sizeof(visit));
				cout<<"before"<<endl;
				for(int a = 0 ; a < d.size() ; a++){
					infection(d[a].row,d[a].col);
				}
				sa = getSafe();
				cout<<"sa is "<<sa<<endl;
				if(sa > maxNum) maxNum = sa;
				memcpy(temp,board,sizeof(board));
			}
		}
	}
}

void infection(int row, int col)
{
	if(temp[row][col] == 1  || visit[row][col] == true)
	{
		visit[row][col] = true;
		return;
	}
	visit[row][col] = true;
	temp[row][col] = 2;
	if(row + 1 < N){
		infection(row + 1,col);
	}
	if(row - 1 >= 0 ){
		infection(row - 1,col);
	}
	if(col + 1 < M ){
		infection(row,col + 1);
	}
	if(col - 1 >= 0){
		infection(row ,col - 1);
	}
}


int getSafe()
{
	int ans = 0;
	for(int row = 0 ; row < N ; row++)
	{
		for(int col = 0 ; col < M ; col++)
		{
			if(temp[row][col] == 0)
			{
				ans++;
			}
		}
	}
	return ans;
}

void test()
{
	cout<<"-------------------------------------------------------"<<endl;
	for(int row = 0 ; row < N ; row++)
	{
		for(int col = 0 ; col < M ; col++){
			cout<<temp[row][col]<<" ";
		}
		cout<<endl;
	}
}
