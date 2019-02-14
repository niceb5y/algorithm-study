#include <iostream>
#include <algorithm>

/*
problem
RGB거리에 사는 사람들은 집을 빨강, 초록, 파랑중에 하나로 칠하려고 한다. 또한, 그들은 모든 이웃은 같은 색으로 칠할 수 없다는 규칙도 정했다. 집 i의 이웃은 집 i-1과 집 i+1이다.

각 집을 빨강으로 칠할 때 드는 비용, 초록으로 칠할 때 드는 비용, 파랑으로 드는 비용이 주어질 때, 모든 집을 칠할 때 드는 비용의 최솟값을 구하는 프로그램을 작성하시오.

input
첫째 줄에 집의 수 N이 주어진다. N은 1,000보다 작거나 같다. 둘째 줄부터 N개의 줄에 각 집을 빨강으로 칠할 때, 초록으로 칠할 때, 파랑으로 칠할 때 드는 비용이 주어진다. 비용은 1,000보다 작거나 같은 자연수이다.

output
첫째 줄에 모든 집을 칠할 때 드는 비용의 최솟값을 출력한다.


*/


using namespace std;

int result[1001][3];
void sol(int R, int G, int B,int n);
int main(void)
{
	int N;
	int R,G,B;
	cin >> N;
	cin>>R>>G>>B;
	result[0][0] = R;
	result[0][1] = G;
	result[0][2] = B;
	for(int i = 1; i < N ; i++){
		cin>>R>>G>>B;
		sol(R,G,B,i);
		//cout<<result[i][0] <<" "<<result[i][1]<<" "<<result[i][2]<<endl;
	}
	int temp = min(result[N - 1][0], result[N - 1][1]);
	cout<<min(temp, result[N - 1][2])<<endl;
	
}


void sol(int R, int G, int B,int n){
	int temp;
	result[n][0] += min(result[n-1][1] , result[n-1][2]) + R;
	result[n][1]  += min(result[n-1][0] , result[n-1][2]) + G;
	result[n][2]  += min(result[n-1][0] , result[n-1][1]) + B;
}

/*
sol
dp로 풀 수 있는 가장 기본적인 색칠문제이다.
최소값을 구하려면 전에 색칠했던 색을 제외한 나머지 2개의 색 중 작은값을 가져오면 된다.
그래서 col이 3인 배열을 선언하여 첫번째 자리는 빨간색, 두번째 자리는 초록색, 새번째 자리는 파랑색으로 고정하고
각 자리를 구할때는 row-1 위치에서 자신을 제외한 두 색의 최소값을 구하여 더하는 식으로 풀었다.

*/
