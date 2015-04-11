#!/usr/bin/env python

# Google Code Jam 2015 Qualification Round
# Problem B. Infinite House of Pancakes

import sys
import math

def solve(D, P):
  ans = max(P)
  for d in range(1, 1001):
    tot = d
    for p in P:
      if p > d:
        tot += int(math.ceil(float(p) / d)) - 1
    ans = min(ans, tot)
  return ans

T = int(sys.stdin.readline())
for t in range(1, T+1):
  D = int(sys.stdin.readline())
  P = [int(x) for x in sys.stdin.readline().rstrip("\n").split(' ')]
  ans = solve(D, P)
  print("Case #" + str(t) + ": " + str(ans))

