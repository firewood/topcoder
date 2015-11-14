import sys

def cap(s):
  if len(s) == 0:
    return ""
  return s[0].upper() + s[1:]

def solve(s):
  return " ".join(map(cap, s.split(" ")))

print(solve(sys.stdin.readline().strip()))
