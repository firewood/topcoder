// Google Code Jam 2016 Qualification Round
// Problem D. Fractiles

package main

import (
    "bufio"
    "fmt"
    "os"
    "strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
    sc.Scan()
    i, e := strconv.Atoi(sc.Text())
    if e != nil {
        panic(e)
    }
    return i
}

func main() {
    sc.Split(bufio.ScanWords)
    T := nextInt()
    for t := 1; t <= T; t++ {
	k := nextInt()
	c := nextInt()
	s := nextInt()
	fmt.Print("Case #")
	fmt.Print(t)
	fmt.Print(":")
	for i := 1; i <= k; i++ {
	    fmt.Print(" ")
	    fmt.Print(i)
        }
	fmt.Println("")
	_ = c
	_ = s
    }
}
