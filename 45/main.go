package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	var fib [46]int
	fib[0], fib[1] = 0, 1
	for i := 2; i <= n; i++ {
		fib[i] = fib[i-1] + fib[i-2]
	}
	fmt.Println(fib[n])
}
