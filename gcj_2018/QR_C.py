#!/usr/bin/env python

# Google Code Jam 2018 Qualification Round
# Problem C. Go, Gopher!

import sys, random

def solve():
  a = int(sys.stdin.readline())
  x = 2
  y = 2
  while True:
    print(x, y, flush=True)
    res = [int(x) for x in sys.stdin.readline().rstrip("\n").split(' ')]
    if len(res) == 1:
      exit(1)
    (r, c) = res
    if r == 0 and c == 0:
      return
    x = x + 1
    if x > 4:
      x = 2
      y = y + 1
      if y > 3:
        y = 2
  return


T = int(sys.stdin.readline())
for t in range(1, T+1):
  solve()
