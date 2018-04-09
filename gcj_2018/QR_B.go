// Google Code Jam 2018 Qualification Round
// Problem B. Trouble Sort

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"sort"
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

func solve(n int, v []int) int {
	a := make([][]int, 2)
	for i := 0; i < n; i++ {
		a[i % 2] = append(a[i % 2], v[i])
	}
	sort.Sort(sort.IntSlice(v))
	sort.Sort(sort.IntSlice(a[0]))
	sort.Sort(sort.IntSlice(a[1]))

	for i := 0; i < n; i++ {
		if v[i] != a[i % 2][i / 2] {
			return i
		}
	}

	return -1
}

func main() {
	sc.Split(bufio.ScanWords)
	T := nextInt()
	for t := 1; t <= T; t++ {
		n := nextInt()
		v := make([]int, n)
		for i := 0; i < n; i++ {
			v[i] = nextInt()
		}

		ans := solve(n, v)

		fmt.Print("Case #")
		fmt.Print(t)
		fmt.Print(": ")
		if ans < 0 {
			fmt.Print("OK")
		} else {
			fmt.Print(ans)
		}
		fmt.Println("")
	}
}
