// Google Code Jam 2017 Qualification Round
// Problem A. Oversized Pancake Flipper

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
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

func solve(s string, k int) int {
	if len(s) == 0 {
		return 0
	}
	if s[0] == '+' {
		return solve(s[1:len(s)], k)
	}
	if len(s) < k {
		return -1
	}
	a := strings.Replace(s[0:k], "+", ".", -1)
	a = strings.Replace(a, "-", "+", -1)
	a = strings.Replace(a, ".", "-", -1)
	r := solve(a + s[k:len(s)], k)
	if r < 0 {
		return -1
	} else {
		return 1 + r
	}
}

func main() {
	sc.Split(bufio.ScanWords)
	T := nextInt()
	for t := 1; t <= T; t++ {
		s := nextString()
		k := nextInt()
		ans := solve(s, k)

		fmt.Print("Case #")
		fmt.Print(t)
		fmt.Print(": ")
		if ans < 0 {
			fmt.Print("IMPOSSIBLE")
		} else {
			fmt.Print(ans)
		}
		fmt.Println("")
	}
}
