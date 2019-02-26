#include <iostream>


/*
problem:
1부터 n 까지의 정수가 차례로 스택에 push 된다.

push 가 이루어지는 중간에, 또는 모든 숫자들이 push 된 이 후에 언제든지 임의로 숫자들을 pop 할 수 있다. 이렇게 pop 된 숫자들을 차례로 나열한 수열을 catalan number 라 한다.

예를 들어, n 이 4 라면 1,2,3,4 가 차례로 push 된다. 1,2,3,4 가 모두 push 된 뒤 네 번 pop 하면 4,3,2,1 이라는 수열이 만들어 진다. 반면에 1,2 가 push 된 두 번 pop을 하고, 나머지 3,4 가 push 된 뒤 또 두 번 pop을 하면 2,1,4,3 이라는 수열이 만들어 진다.

따라서 앞서 말한대로 4,3,2,1 과 2,1,4,3 은 둘다 catalan number 이다. 하지만 이렇게 pop을 해도 3,4,1,2 이라는 수열은 만들어 질 수 없는데 따라서 이는 catalan number 가 아니다.

n 과 1부터 n 까지의 숫자로 이루어진 수열이 주어질 때 , 그 수열이 catalan number 인지 아닌지를 알아내는 프로그램을 작성하시오.

input:
첫 번째 줄에 100 이하의 자연수 n 이 주어진다. 두 번 째 줄에는 1부터 n 까지의 수로 이루어진 수열이 주어진다.
output:
입력으로 주어진 수열이 catalan number 라면 YES ,아니면 NO를 출력한다.

*/



using namespace std;
int array[101];
bool isvisit[101];

int main(void)
{
	int N;
	cin>>N;
	for(int i = 0; i < N ; i++){
		cin>>array[i];
	}
	int i,before;
	isvisit[0] =true;
	for(int i = 0 ; i < N ; i++){
		int index = array[i];
		isvisit[index] = true;
		index--;
		i++;
		while(isvisit[index] == false ){
			if(index == array[i]){
				isvisit[index] = true;
				index--;
				i++;
			}
			else{
				cout<<"NO"<<endl;
				return 0;
			}
		}
		i--;
	}
	cout<<"YES"<<endl;
}



/*
sol:
스택문제인데 스택을 안썼다. 나는 사람이 진짜 판별하듯이 풀었는데 처음에 입력받은 숫자는 결국 stack에 바닥까지 무조건 출력을 해주어야 하므로 처음입력 받은 숫자에서 값을 1뺸값과
두번쨰로 입력받은 값을 비교 이런식으로 진행하였다.
스택을 써서 푼 방법도 있어서 가져와봤따.

#include <iostream>
#include <stack>
using namespace std;
 
int main() {
    int n,find_n=1,arr[101]={0};
    cin>>n;
     
    for(int i=1;i<=n;i++){
        scanf("%d",&arr[i]);
    }
 
    stack<int> st;
    for(int j=1;j<=n;j++){
        st.push(arr[j]);
        while(!st.empty()&&st.top()==find_n){
            st.pop();
            find_n++;
        }
    }
    if(st.empty())  cout<<"YES"<<endl;
    else    cout<<"NO"<<endl;
     
    return 0;
}


*/
