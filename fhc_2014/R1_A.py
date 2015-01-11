#!/usr/bin/env python

# Facebook Hacker Cup 2014 Round 1
# A. Labelmaker

import sys

def solve(L, N):
  digits = 1
  e = len(L)
  N = N - 1
  while N >= e:
    N -= e
    digits += 1
    e *= len(L)
  s = ""
  for d in range(digits):
    s += L[N % len(L)]
    N //= len(L)
  return "".join(reversed(list(s)))

T = int(sys.stdin.readline())
for t in range(T):
  (L, N) = sys.stdin.readline().split(" ")
  ans = solve(L, int(N))
  print("Case #" + str(t+1) + ": " + ans)
