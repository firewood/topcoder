#!/usr/bin/env python

# Google Code Jam 2013 Round 1A
# Problem A. Bullseye
# small

import sys

def solve(r, t):
    c = 0
    while 1:
#        n = (r + 1) ** 2 - r ** 2
        n = (r*2) + 1
        if (t < n):
            break
        t -= n
        c += 1
        r += 2
    return c

n = int(sys.stdin.readline())
for t in range(1, n+1):
    a = sys.stdin.readline().split(" ")
    ans = solve(int(a[0]), int(a[1]))
    print("Case #" + str(t) + ": " + str(ans))

