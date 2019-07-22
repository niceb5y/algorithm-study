#include <iostream>

using namespace std;

int board[8];
int main(void)
{
	int index = 0;
	int trash;
	for(int tc = 0 ; tc < 10 ; tc++)
	{
		index = 0;
		cin>>trash;
		for(int i = 0 ; i < 8 ; i++)
		{
			cin>>board[i];
		}
		while(1)
		{
			board[index%8] -= (index%5)+1;
			if(board[index%8] <= 0)
			{
				board[index%8] = 0;
				index++;
				break;
			}
			index++;
			
		}
		cout<<"#"<<tc+1<<" ";
		for(int i = 0 ; i < 8 ; i++)
		{
			cout<<board[(index+i) % 8]<<" ";
		}
		cout<<endl;
		}
}
