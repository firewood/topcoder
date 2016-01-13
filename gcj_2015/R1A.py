#!/usr/bin/env python

# Google Code Jam 2015 Round 1A
# Problem A. Mushroom Monster

import sys

def solve(N, M):
  a = 0
  b = 0
  s = 0
  for i in range(1, N):
    c = max(0, M[i-1] - M[i])
    a += c
    s = max(s, c)
  for i in range(0, N-1):
    b += min(M[i], s)
  return (a, b)

T = int(sys.stdin.readline())
for t in range(1, T+1):
  N = int(sys.stdin.readline().rstrip("\n"))
  M = [int(x) for x in sys.stdin.readline().rstrip("\n").split(' ')]
  (a, b) = solve(N, M)
  print("Case #" + str(t) + ": " + str(a) + " " + str(b))
