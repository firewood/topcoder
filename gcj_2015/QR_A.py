#!/usr/bin/env python

# Google Code Jam 2015 Qualification Round
# Problem A. Standing Ovation

import sys

def solve(m, s):
  ans = 0
  tot = 0
  for level in range(0, m+1):
    n = int(s[level])
    if n > 0:
      need = max(0, level - tot)
      ans += need
      tot += need + n
  return ans

n = int(sys.stdin.readline())
for t in range(1, n+1):
  args = []
  line = sys.stdin.readline().rstrip("\n").split(' ')
  ans = solve(int(line[0]), line[1])
  print("Case #" + str(t) + ": " + str(ans))

