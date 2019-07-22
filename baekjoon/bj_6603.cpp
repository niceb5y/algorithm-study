#include <iostream>
#include <vector>

using namespace std;

int num;
int candidate[13];
vector<int> st;
void dfs(int n,int index);
void print_stack();
int main(void)
{
	num = -1;
	while(1)
	{
		cin>>num;
		if(num == 0)
			break;
		for(int i = 0 ; i < num ; i++)
		{
			cin>>candidate[i];
		}
		for(int i = 0 ; i < num - 5 ; i++){
			dfs(candidate[i],i);
		}
		cout<<endl;	
	}
}

void dfs(int n,int index)
{
	st.push_back(n);
	if(st.size() == 6){
		print_stack();
		st.pop_back();
		return;
	}
	for(int i = index + 1 ; i < num  ; i++){
		dfs(candidate[i],i);
	}
	st.pop_back();
}

void print_stack()
{
	for(int i = 0 ; i < st.size() ; i++){
		cout<<st.at(i)<<" ";
	}
	cout<<endl;
}
