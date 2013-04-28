#!/usr/bin/env python

# Google Code Jam 2013 Qualification Round
# Problem C. Fair and Square

import sys

def is_palindrome(n):
    s = str(n)
    return s == s[::-1]

def make_palindrome1(n):
    s = str(n)
    return int(s + s[::-1])

def make_palindrome2(n):
    s = str(n)
    return int(s + s[-2::-1])

a = [x*x for x in [make_palindrome1(y) for y in range(1, 10**3)] if is_palindrome(x*x)]
b = [x*x for x in [make_palindrome2(y) for y in range(1, 10**4)] if is_palindrome(x*x)]
pali_sq = sorted(a + b)

def p(n):
    c = 0
    for x in pali_sq:
        if x > n:
            break
        c += 1
    return c

n = int(sys.stdin.readline())
for t in range(1, n+1):
    x = sys.stdin.readline().split(" ")
    ans = str(p(int(x[1])) - p(int(x[0])-1))
    print("Case #" + str(t) + ": " + ans)

