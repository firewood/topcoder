// Google Code Jam 2017 Qualification Round
// Problem C. Bathroom Stalls

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func nextString() string {
	sc.Scan()
	return sc.Text()
}

func nextInt() int {
	i, e := strconv.Atoi(nextString())
	if e != nil {
		panic(e)
	}
	return i
}

func solve(n int, k int) {
	r := n
	d := 1
	for k > d {
		k -= d
		r -= d
		d *= 2
	}
	e := k <= (r % d)
	sz := r / d - 1
	if e {
		sz += 1
	}
	fmt.Print(sz / 2 + (sz % 2))
	fmt.Print(" ")
	fmt.Print(sz / 2)
}

func main() {
	sc.Split(bufio.ScanWords)
	T := nextInt()
	for t := 1; t <= T; t++ {
		n := nextInt()
		k := nextInt()
		fmt.Print("Case #")
		fmt.Print(t)
		fmt.Print(": ")
		solve(n, k)
		fmt.Println("")
	}
}
