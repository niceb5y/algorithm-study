#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;
string strnum[10] = {"ZRO", "ONE", "TWO", "THR", "FOR", "FIV", "SIX", "SVN", "EGT", "NIN"};
void strtonum(string str);
int num[10001];
int index,size;
int compare(const void *a, const void *b);
int main(void)
{
	string tc;
	int size;
	string str;
	int trash;
	cin>>trash;
	for(int i = 0 ; i < 10 ; i++){
		cin>>tc>>size;
		index = 0;
		string temp;
		cout<<tc<<endl;
		for(int j = 0 ; j < size; j++)
		{
			cin>>temp;
			strtonum(temp);
		}
		qsort(num,index,sizeof(int),compare);
		cout<<tc<<endl;
		for(int j = 0 ; j < index ; j++)
		{
			cout<<strnum[num[j]]<<" ";
		}
		cout<<endl;
	}

	
}

void strtonum(string str)
{
	if(str.at(0) == 'Z')
	{
		num[index] = 0;
	}
	else if(str.at(0) == 'O')
	{
		num[index] = 1;
	}	
	else if(str.at(0) == 'T')
	{
		if(str.at(1) == 'W')
		{
			num[index] = 2;
			
		}
		else
		{
			num[index] = 3;
		}
		
	}
	else if(str.at(0) == 'F')
	{
		if(str.at(1) == 'O')
		{
			num[index] = 4;
			
		}
		else
		{
			num[index] = 5;
		}
	}
	else if(str.at(0) == 'S')
	{
		if(str.at(1) == 'I')
		{
			num[index] = 6;
			
		}
		else
		{
			num[index] = 7;
		}
	}
	else if(str.at(0) == 'E')
	{
		num[index] = 8;
	}
	else if(str.at(0) == 'N')
	{
		num[index] = 9;
	}
	else{
		num[index] = -1;
	}
	index++;
}

// 오름차순
int compare(const void *a, const void *b)    // 오름차순 비교 함수 구현
{
    int num1 = *(int *)a;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴
    int num2 = *(int *)b;    // void 포인터를 int 포인터로 변환한 뒤 역참조하여 값을 가져옴

    if (num1 < num2)    // a가 b보다 작을 때는
        return -1;      // -1 반환
    
    if (num1 > num2)    // a가 b보다 클 때는
        return 1;       // 1 반환
    
    return 0;    // a와 b가 같을 때는 0 반환
}

