#!/usr/bin/env python

# Google Code Jam 2014 Qualification Round
# Problem A. Magic Trick

import sys

def solve(a, b):
  m = []
  for n in a[a[0]]:
    if n in b[b[0]]:
      m.append(n)
  if len(m) == 0:
    return "Volunteer cheated!"
  if len(m) > 1:
    return "Bad magician!"
  return str(m[0])

n = int(sys.stdin.readline())
for t in range(1, n+1):
  args = []
  for n in range(2):
    line = sys.stdin.readline().rstrip("\n")
    arg = [int(line)]
    for i in range(4):
      line = sys.stdin.readline().rstrip("\n")
      arg.append([int(n) for n in line.split(" ")])
    args.append(arg)
#  print(args)
  ans = solve(args[0], args[1])
  print("Case #" + str(t) + ": " + ans)

