#!/usr/bin/env python

# Google Code Jam 2016 Round 1B
# Problem A. Getting the Digits

import sys

def dec(h, k, s):
  cnt = 0
  if k in h and h[k] > 0:
    cnt = h[k]
    for c in s:
      h[c] -= cnt
  return cnt

def solve(s):
  a = [0]*11
  h = {}
  for c in s:
    if c in h:
      h[c] += 1
    else:
      h[c] = 1
  a[0] += dec(h, 'Z', 'ZERO')
  a[2] += dec(h, 'W', 'TWO')
  a[4] += dec(h, 'U', 'FOUR')
  a[6] += dec(h, 'X', 'SIX')
  a[8] += dec(h, 'G', 'EIGHT')
  a[1] += dec(h, 'O', 'ONE')
  a[3] += dec(h, 'R', 'THREE')
  a[5] += dec(h, 'F', 'FIVE')
  a[7] += dec(h, 'S', 'SEVEN')
  a[9] += dec(h, 'I', 'NINE')
  ans = ''
  for i in range(0, 10):
    ans += str(i) * a[i]
  return ans

T = int(sys.stdin.readline())
for t in range(1, T+1):
  s = sys.stdin.readline().strip()
  ans = solve(s)
  print("Case #" + str(t) + ": " + str(ans))
