#!/usr/bin/env python

# Google Code Jam 2013 Qualification Round
# Problem C. Fair and Square
# large 2

import sys

def is_palindrome(n):
    s = str(n)
    return s == s[::-1]

def make_palindrome(n, f):
    s = str(n)
    return int(s + s[-1-f::-1])

def gen(d, digits, pos):
    if pos * 2 >= digits:
        n = make_palindrome("".join(map(str, d)), digits % 2)
        sq = n ** 2
        if is_palindrome(sq):
            seq.append(sq)
    else:
        for n in [0,1,2]:
            d[pos] = n
            if sum([x**2 for x in d[:len(d) - (digits % 2)]]) < 5:
                gen(d, digits, pos + 1)
        d[pos] = 0

def solve(a, b):
    return sum([x >= a and x <= b for x in seq])

seq = [1,4,9]
for digits in range(2, 51):
    for n in [1, 2]:
        gen([n] + [0] * ((digits-1) // 2), digits, 1)

n = int(sys.stdin.readline())
for t in range(1, n+1):
    a, b = map(int, sys.stdin.readline().split(" "))
    print("Case #" + str(t) + ": " + str(solve(a, b)))

