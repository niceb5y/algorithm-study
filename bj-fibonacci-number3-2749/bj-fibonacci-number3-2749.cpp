#include <iostream>

using namespace std;

typedef struct {
    unsigned long long m[2][2];
} Matrix;

Matrix multi(Matrix& A, Matrix& B)
{
    Matrix C;
    C.m[0][0] = ((A.m[0][0] * B.m[0][0]) % 1000000 + (A.m[0][1] * B.m[1][0]) % 1000000) % 1000000;
    C.m[0][1] = ((A.m[0][0] * B.m[0][1]) % 1000000 + (A.m[0][1] * B.m[1][1]) % 1000000) % 1000000;
    C.m[1][0] = ((A.m[1][0] * B.m[0][0]) % 1000000 + (A.m[1][1] * B.m[1][0]) % 1000000) % 1000000;
    C.m[1][1] = ((A.m[1][0] * B.m[0][1]) % 1000000 + (A.m[1][1] * B.m[1][1]) % 1000000) % 1000000;
    return C;
}

Matrix powerMatrix(Matrix A, int n)
{
    if (n > 1) {
        A = powerMatrix(A, n / 2);
        A = multi(A, A);
        if (n % 2 == 1) {
            Matrix init = {1, 1, 1, 0};
            A = multi(A, init);
        }
    }
    return A;
}

int main(void)
{
    int N;
    cin >> N;
    Matrix init = {1, 1, 1, 0};
    init = powerMatrix(init, N);
    cout << init.m[0][1] << endl;
    return 0;
}