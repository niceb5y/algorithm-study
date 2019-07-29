#include <cstdio>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	int n = rand() % 5 + 10, m = 200;
	printf("%d %d\n", n, m);
	for (int i = 1; i <= n; i++)
	{
		int x = rand() % 5;
		printf("%d", x);
		for (int j = 0; j < x; j++)
			printf(" %d", rand() % 50 + 151);
		puts("");
	}
}