#include <iostream>
#include <stdio.h>

using namespace std;

/*
 problem:
 농부 존은 N (2 <= N <= 100,000)개의 우리(stall)를 가진 긴 축사(barn)를 지으려고 한다. 우리(stall)는 직선 형태로 각각은 x1 ,x2 , .. , xn 에 위치하고 있다.(0 <= xi <= 1,000,000,000).

그가 가진 C 마리의 소들은 한 우리에 넣는 경우 매우 공격적이 된다. 소들이 서로 싸워 다치지 않게 우리에 넣은 인접한 소들의 떨어진 거리의 최소 값이 가능한 크게 소들을 배치하기를 원한다.

최대 최소 거리는 얼마인가?

input:
첫 줄에는 두 정수 N , C 가 주어진다.
다음 N 줄에는 xi 가 주어진다.

output:
가장 큰 최소 거리를 출력한다
 
  */

 
int N,C;
 
int check(int num,int stalls[])
{
    int cows=1,pos=stalls[0];
    for (int i=1; i<N; i++)
    {
        if (stalls[i]-pos>=num)
        {
            pos=stalls[i];
            cows++;
            if (cows==C)
                return 1;
        }
    }
    return 0;
}
 
int binarySearch(int stalls[])
{
    int start=0,end=stalls[N-1],max=-1;
    while (end>start)
    {
        int mid=(start+end)/2;
        if (check(mid,stalls)==1)
        {
            if (mid>max)
                max=mid;
            start=mid+1;
        }
        else
            end=mid;
    }
    return max;
}
 
int main()
{
        cin>>N>>C;
         
        int stalls[N];
         
        for (int i=0; i<N; i++)
            cin>>stalls[i];
         
        sort(stalls,stalls+N);
         
        int k=binarySearch(stalls);
         
        cout<<k;
    return 0;
}


/*
sol:
parametric search : 값을 대입해보면서 결과가 달라지는 최초값을 통해서 값을 추론하는 풀이법
ex) 2*x + 10 <= 26 (0 < x <= 20)
위에 문제를 푸는 경우 
1..20 의 중간 값 (1 + 20)/2 = 10 
f(10) = 2*10 + 10 = 30 
f(10) > 26 이므로 x

1..9 의 중간 값 (1+9)/2 = 5 
f(5) = 20 
f(5) <= 24 이므로 5 는 가능한 해

6 .. 9 의 중간 값 (6+9)/2 = 7 
f(7) = 14 
f(7) <= 26 을 만족. 7 도 가능한 해

8..9 의 중간 값 (8+9)/2 = 8 
f(8)=26 
f(9) <= 26 이므로. 8 도 가능한 해

9..9 의 중간 값 (9+9)/2 = 9 
f(9)=28 
f(9) > 26 이므로 x

9 > 8 이면 종료

이런식으로 값을 대입해가면서 답을 찾는 방식이다.

aggressiv 문제 역시  check 함수를 통해서 파라미터로 들어가는 거리로 소들을 집어넣을수 있는지 판별, 
binarysearch를 통해서 그 값을 계속추롤해 나간다.
*/

