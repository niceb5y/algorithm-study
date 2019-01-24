#include <stdio.h>

int main(void)
{
    int i;
    printf("%d\n", 5000);
    for(i = 2; i <= 10000; i+=2) {
        printf("%d\n", i);
    }
}
