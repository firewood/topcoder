#!/usr/bin/env python

# Google Code Jam 2015 Qualification Round
# Problem C. Dijkstra

import sys
import math

mul_tbl = [[0],[0,1,2,3,4],[0,2,-1,4,-3],[0,3,-4,-1,2],[0,4,3,-2,-1]]
char_tbl = {'i':2, 'j':3, 'k':4}

def find(L, X, s, current, target, pos):
  m = min(8, X)
  for x in range(0, m):
    for p in range(pos, L):
      if current == target:
        return (X - x, p, current)
      c = char_tbl[s[p]]
      if current > 0:
        current = mul_tbl[current][c]
      else:
        current = -1 * mul_tbl[-current][c]
    pos = 0
  return (X - m, 0, current)

def solve(L, X, s):
  (X, pos, current) = find(L, X, s, 1, 2, 0)
  if current != 2:
    return False
  (X, pos, current) = find(L, X, s, 1, 3, pos)
  if current != 3:
    return False
  (X, pos, current) = find(L, X, s, 1, 4, pos)
  if current != 4:
    return False
  if X > 8:
    X = 4 + (X - 4) % 4
  (X, pos, current) = find(L, X, s, 1, 255, pos)
  return X == 0 and pos == 0 and current == 1

T = int(sys.stdin.readline())
for t in range(1, T+1):
  (L, X) = [int(x) for x in sys.stdin.readline().rstrip("\n").split(' ')]
  s = sys.stdin.readline().rstrip("\n")
  if solve(L, X, s):
    ans = "YES"
  else:
    ans = "NO"
  print("Case #" + str(t) + ": " + ans)

