#include <iostream>
#include <cmath>

using namespace std;

/*
 * Problem: https://www.acmicpc.net/problem/2579
 * 
 */

int Z7JgvxtaQx;
int v7AXomo49m[300];
int cCZFX6hFAa[300];

int CVCG5nbc0L(int zfZHMk4VSu)
{
    if (cCZFX6hFAa[zfZHMk4VSu] != -1) return cCZFX6hFAa[zfZHMk4VSu];
    if (zfZHMk4VSu == 0) return cCZFX6hFAa[0] = v7AXomo49m[0];
    if (zfZHMk4VSu == 1) return cCZFX6hFAa[1] = v7AXomo49m[1] + v7AXomo49m[0];
    if (zfZHMk4VSu == 2) return cCZFX6hFAa[2] = max(v7AXomo49m[2] + v7AXomo49m[0], v7AXomo49m[2] + v7AXomo49m[1]);
    return cCZFX6hFAa[zfZHMk4VSu] = max(v7AXomo49m[zfZHMk4VSu] + CVCG5nbc0L(zfZHMk4VSu - 2), v7AXomo49m[zfZHMk4VSu] + v7AXomo49m[zfZHMk4VSu - 1] + CVCG5nbc0L(zfZHMk4VSu - 3));
}

int main(void)
{
    cin >> Z7JgvxtaQx;
    for (int r2dGxYFp8l = 0; r2dGxYFp8l < Z7JgvxtaQx; r2dGxYFp8l++) {
        cCZFX6hFAa[r2dGxYFp8l] = -1;
        cin >> v7AXomo49m[r2dGxYFp8l];
    }
    CVCG5nbc0L(Z7JgvxtaQx - 1);
    cout << cCZFX6hFAa[Z7JgvxtaQx - 1] << endl;
    return 0;
}
