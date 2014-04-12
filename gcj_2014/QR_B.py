#!/usr/bin/env python

# Google Code Jam 2014 Qualification Round
# Problem B. Cookie Clicker Alpha

import sys

def solve(c, f, x):
  r = 2.0
  ans = x / r
  for n in range(10000000):
    t = ans - (x - c) / r
    r += f
    t += x / r
    if t > ans:
      break
    ans = t
  return ans

n = int(sys.stdin.readline())
for t in range(1, n+1):
  (c, f, x) = [float(n) for n in sys.stdin.readline().rstrip("\n").split(" ")]
  ans = solve(c, f, x)
  print("Case #%d: %.7f" % (t, ans))

