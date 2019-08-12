#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<int>> matrix;

matrix create_matrix(int n) {
  matrix ret = vector<vector<int>>(n, vector<int>(n, 0));
  for (int i = 0; i < n; ++i) {
    ret[i][i] = 1;
  }
  return ret;
}

matrix operator*(const matrix &a, const matrix &b) {
  size_t size = a.size();
  matrix ret = create_matrix(size);
  for (size_t i = 0; i < size; ++i) {
    for (size_t j = 0; j < size; ++j) {
      ret[i][j] = 0;
      for (size_t k = 0; k < size; ++k) {
        ret[i][j] += a[i][k] * b[k][j];
        ret[i][j] %= 1000;
      }
    }
  }
  return ret;
}

matrix power(const matrix &n, long long k) {
  if (k == 0)
    return create_matrix(n.size());
  matrix ret = power(n, k / 2);
  ret = ret * ret;
  if (k % 2 == 1)
    ret = ret * n;
  return ret;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n;
  long long b;
  cin >> n >> b;

  matrix mat = create_matrix(n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> mat[i][j];
    }
  }

  matrix ans = power(mat, b);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cout << ans[i][j] << (j == n - 1 ? "\n" : " ");
    }
  }
}
