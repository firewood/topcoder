# Facebook Hacker Cup 2014 Qualification Round
# A. Square Detector

import sys

def stripped(a):
  while a[0].strip('.') == '':
    del(a[0])
  while a[-1].strip('.') == '':
    del(a[-1])
  return a

def rotated(a):
  return ["".join(l) for l in zip(*[list(s) for s in a])]

def solve():
  N = int(sys.stdin.readline())
  a = []
  for i in range(N):
    a.append(sys.stdin.readline().rstrip())
  a = stripped(a)
  a = stripped(rotated(a))
  if len(a) != len(a[0]):
    return False
  if "".join(a).find('.') >= 0:
    return False
  return True

cases = int(sys.stdin.readline())
for case in range(cases):
  r = solve()
  s = "Case #" + str(case + 1) + ": "
  s += ["NO", "YES"][int(r)]
  print(s)
