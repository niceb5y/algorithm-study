#include <cstdio>
#include <iostream>

using namespace std;

// arr: 쿼드트리가 담길 배열
bool arr[64][64];

// quadtree: 쿼드트리를 재귀적으로 압축하여 출력하는 함수.
// x, y: 좌표
// size: x, y 한 축의 크기
string quadtree(int x, int y, int size) {
  // 기저: 사이즈가 1이면 수를 리턴한다.
  if (size == 1)
    return (arr[y][x] == 1) ? "1" : "0";

  // 배열을 순회하면서 주어진 구역의 수가 모두 동일한지 확인한다.
  for (int i = y; i < y + size; ++i) {
    for (int j = x; j < x + size; ++j) {
      if (arr[i][j] != arr[y][x]) {
        // 주어진 구역의 수가 동일하지 않을경우 함수를 재귀적으로 호출하고
        // 결과값을 묶는다.
        return "(" + quadtree(x, y, size / 2) +
               quadtree(x + size / 2, y, size / 2) +
               quadtree(x, y + size / 2, size / 2) +
               quadtree(x + size / 2, y + size / 2, size / 2) + ")";
      }
    }
  }
  // 주어진 구역의 수가 모두 동일하다면 압축한다.
  return arr[y][x] ? "1" : "0";
}

int main() {
  // size: 입력의 사이즈
  int size;
  cin >> size;

  // buf: 한줄씩 값을 읽어올 변수
  string buf;
  // cin 버퍼 비우기
  cin.get();

  for (int i = 0; i < size; ++i) {
    // 입력을 한줄씩 읽는다.
    getline(cin, buf);
    // 읽어들인 문자열에서 한문자씩 배열에 집어넣는다.
    for (int j = 0; j < size; ++j) {
      arr[i][j] = (buf[j] == '1');
    }
  }

  // 결과물 출력
  cout << quadtree(0, 0, size) << endl;
}
