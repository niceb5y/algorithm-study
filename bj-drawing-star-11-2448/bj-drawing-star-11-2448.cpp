#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
int k, N;
int **starLine;
void atom(int r, int c)
{
    starLine[r][c] = '*';
    starLine[r + 1][c - 1] = '*';
    starLine[r + 1][c + 1] = '*';
    starLine[r + 2][c - 2] = '*';
    starLine[r + 2][c - 1] = '*';
    starLine[r + 2][c] = '*';
    starLine[r + 2][c + 1] = '*';
    starLine[r + 2][c + 2] = '*';
}

void recursiveStar(int step, int r, int c)
{
    if (step == 0)
    {
        atom(r, c);
    }
    else
    {
        recursiveStar(step - 1, r, c);
        recursiveStar(step - 1, r + 3 * pow(2, step - 1), c + 3 * pow(2, step - 1));
        recursiveStar(step - 1, r + 3 * pow(2, step - 1), c - 3 * pow(2, step - 1));
    }
}

void draw()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N * 2 - 1; j++)
        {
            if (!starLine[i][j])
                std::cout << " ";
            else
                std::cout << "*";
        }
        std::cout << std::endl;
    }
}
int main(int argc, char *argv[])
{
    std::cin >> N;
    k = (int)(log2((double)N / (double)3)) + 1; //N=3*2^k-1 -> 2^k-1 = (3/N) -> k = log_2_(3/N)+1
    starLine = new int *[N];
    for (int i = 0; i < N; i++)
        starLine[i] = new int[N * 2 - 1];

    recursiveStar(k - 1, 0, N - 1);
    draw();
    return 0;
}
