#include <iostream>
#include <queue>

using namespace std;
void bfs();
int N,K;
bool is_find;
bool visit[100001];
typedef struct _node{
	int level;
	int pos;
}node;
queue<node> q;
node ans;
void insert(node next);
int main(void)
{
	cin>>N>>K;
	is_find = false;
	node start;
	start.level = 0;
	start.pos = N;
	q.push(start);
	bfs();
	cout<<ans.level<<endl;
	
}


void bfs()
{
	node now ;
	node next;
	while(!q.empty()){
		now = q.front();
		q.pop();
		cout<<now.level<<" "<<now.pos<<endl;
		if(now.pos == K){ans = now ; return;}
		next.level = now.level + 1;
		next.pos  = now.pos - 1;
		insert(next);
		next.pos = now.pos + 1;
		insert(next);
		next.pos = now.pos * 2;
		insert(next);
	}
}


void insert(node next)
{
	if(next.pos < 0  || next.pos > 100000 || visit[next.pos] == true)
		return;
	visit[next.pos] = true;
	q.push(next);
}
