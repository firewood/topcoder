#!/usr/bin/env python

# Google Code Jam 2013 Round 1A
# Problem A. Bullseye
# large

import sys

def int_sqrt(x):
    if x <= 0:
        return 0
    s = 1
    t = x
    while s < t:
        s *= 2
        t //= 2
    while True:
        t = s
        s = (x // s + s) // 2
        if s >= t:
            break
    return t

def solve(r, t):
    if r % 2:
        p = 0
        if r > 1:
            p = (r - 1) // 2
            t += 2 * (p ** 2) + p
        c = (-1 + int_sqrt(1 + 8 * t)) // 4
        return c - p
    p = 0
    if r > 2:
        p = (r-1) // 2
        t += 2 * (p ** 2) + p * 3
    c = (-3 + int_sqrt(9 + 8 * t)) // 4
    return c - p

n = int(sys.stdin.readline())
for t in range(1, n+1):
    a = sys.stdin.readline().split(" ")
    ans = solve(int(a[0]), int(a[1]))
    print("Case #" + str(t) + ": " + str(int(ans)))

