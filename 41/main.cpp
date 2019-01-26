#include <iostream>
#include <vector>

using namespace std;

// matrix_t 숫자의 2차원 행렬
typedef vector<vector<int>> matrix_t;

// create_matrix(n, m): 크기가 (n, m)인 행렬을 만든다.
matrix_t create_matrix(int n, int m) {
  return vector<vector<int>>(n, vector<int>(m, 0));
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  // n, m, k: 행렬 1, 2의 크기 (n, m), (m, k)
  int n, m, k;
  cin >> n >> m;
  // mat1: 행렬 1
  matrix_t mat1 = create_matrix(n, m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cin >> mat1[i][j];
    }
  }
  cin >> m >> k;
  // mat2: 행렬 2
  matrix_t mat2 = create_matrix(m, k);
  for (int i = 0; i < m; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> mat2[i][j];
    }
  }
  // 행렬을 곱해서 출력한다.
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      int ans = 0;
      for (int k = 0; k < m; ++k) {
        ans += mat1[i][k] * mat2[k][j];
      }
      cout << (j == 0 ? "" : " ") << ans;
    }
    cout << '\n';
  }
}
