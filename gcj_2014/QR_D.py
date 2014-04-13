#!/usr/bin/env python

# Google Code Jam 2014 Qualification Round
# Problem D. Deceitful War

import sys

def deceitful(a, b):
  a.sort()
  b.sort()
  s = 0
  while len(a) > 1:
    if a[0] < b[0]:
      a.pop(0)
      b.pop()
    else:
      s += 1
      a.pop(0)
      b.pop(0)
  if a[0] > b[0]:
    s += 1
  return s

def war(a, b):
  a.sort()
  b.sort()
  s = 0
  while len(a) > 0:
    x = a[0]
    a.pop(0)
    for y in b:
      if y > x:
        break
    if x > y:
      s += 1
      b.pop(0)
    else:
      b.remove(y)
  return s

def solve(a, b):
  return [deceitful(a[:], b[:]), war(a, b)]

T = int(sys.stdin.readline())
for t in range(1, T+1):
  N = int(sys.stdin.readline())
  a = [float(n) for n in sys.stdin.readline().rstrip("\n").split(" ")]
  b = [float(n) for n in sys.stdin.readline().rstrip("\n").split(" ")]
  ans = solve(a, b)
  print("Case #%d: %d %d" % (t, ans[0], ans[1]))

