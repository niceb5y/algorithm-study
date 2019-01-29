package main

import (
	"container/ring"
	"fmt"
)

func main() {
	// n: 원소의 수
	// m: 뽑아낼 원소의 수
	var n, m int
	fmt.Scan(&n, &m)
	// r: 원소들이 담길 ring
	// https://golang.org/pkg/container/ring/
	r := ring.New(n)
	// 원소들을 -1로 초기화한다.
	for i := 0; i < r.Len(); i++ {
		r.Value = -1
		r = r.Next()
	}
	// 뽑아내야 하는 원소들에 뽑아낼 순서를 기록한다.
	for i := 0; i < m; i++ {
		var target int
		fmt.Scan(&target)
		tmp := r
		for j := 0; j < target-1; j++ {
			tmp = tmp.Next()
		}
		tmp.Value = i
	}
	// ans: 문제의 정답
	ans := 0
	for i := 0; i < m; i++ {
		// count: 이번에 뽑아낼 원소까지 .Next()로 이동하는 데 드는 비용
		count := 0
		// 이번에 뽑아낼 원소까지 이동한다.
		for r.Value != i {
			r = r.Next()
			count++
		}
		// min(a, b): a, b 중 최소값을 반환하는 함수
		min := func(a int, b int) int {
			if a < b {
				return a
			}
			return b
		}
		// .Next()와 .Prev()로 이동하는 비용 중 최소값을 구한다.
		ans += min(count, (r.Len()-count)%r.Len())
		// 뽑아낼 원소를 삭제한다.
		r = r.Prev()
		r.Unlink(1)
		r = r.Next()
	}
	// 정답 출력
	fmt.Println(ans)
}
