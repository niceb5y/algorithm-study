#include <stdio.h>
#include <string.h>

void bubble_sort(char *arr, int len)
{
    int i, j, t;
    for (i = len - 1; i > 0; i--) {
        for (j = 0; j <= i; j++) {
            if(arr[j] < arr[j+1]) {
                t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    char number[11];
    scanf("%s", number);
    bubble_sort(number, strlen(number));
    printf("%s\n", number);
    return 0;
}
