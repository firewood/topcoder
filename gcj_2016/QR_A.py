#!/usr/bin/env python

# Google Code Jam 2016 Qualification Round
# Problem A. Counting Sheep

import sys

def gen(N):
  n = 0
  while True:
    n += N
    yield n

def f(N, d):
  g = gen(N)
  while True:
    n = next(g)
    for a in list(str(n)):
      if int(a) == d:
        return n

def solve(N):
  if N == 0:
    return "INSOMNIA"
  return max([f(N, d) for d in range(0, 10)])

T = int(sys.stdin.readline())
for t in range(1, T+1):
  N = int(sys.stdin.readline())
  ans = solve(N)
  print("Case #" + str(t) + ": " + str(ans))
