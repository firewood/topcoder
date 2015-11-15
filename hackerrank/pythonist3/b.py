import sys

def seq(n):
  return "-".join(reversed([chr(c) for c in range(ord('a'), ord('a') + n)]))

def solve(n):
  s = seq(n)
  ans = []
  for i in range(1, n * 2):
    a = min(i, 2 * n - i)
    b = (n - a) * 2
    c = s[:a*2-1]
    ans.append("-" * b + c + c[::-1][1:] + "-" * b)
  return "\n".join(ans)

print(solve(int(sys.stdin.readline().strip())))
