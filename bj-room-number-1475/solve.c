#include <stdio.h>
#include <unistd.h>
#include "../util/util.h"
/* Problem: https://www.acmicpc.net/problem/1475 */

int main(int argc, char *argv[])
{
    printf("%d\n", util_abs(-6));
    return unlink(*argv);
}