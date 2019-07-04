#include <iostream>
#include <cstring>
using namespace std;
void dfs(int start);

bool map[100][100];
bool end_flag;
int tc,length,x,y;
int main(void)
{
	for(int i = 0 ; i < 10 ; i++)
	{
		end_flag = false;
		memset(map,0,sizeof(map));
		cin>>tc>>length;
		for(int j = 0 ; j < length ; j++)
		{
			cin>>x>>y;
			map[x][y] = true;
		}
		dfs(0);
		cout<<"#"<<tc<<" ";
		if(end_flag == true)
		{
			cout<<"1"<<endl;
		}
		else
		{
			cout<<"0"<<endl;
		}
	}
}


void dfs(int start)
{
	if(start == 99)
	{
		end_flag = true;
		return;
	}
	for(int i = 0 ; i < 100 ; i++)
	{
		if(map[start][i] == true){
			dfs(i);
		}
		if(end_flag == true)
			break;
	}
}
