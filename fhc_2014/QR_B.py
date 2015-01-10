# Facebook Hacker Cup 2014 Qualification Round
# B. Basketball Game

import sys

def solve():
  (N, M, P) = [int(x) for x in sys.stdin.readline().rstrip().split(' ')]
  m = []
  for i in range(N):
    (name, shot, height) = sys.stdin.readline().rstrip().split(' ')
    shot = int(shot)
    height = int(height)
    m.append([0, 0, -shot, -height, name])
  m = sorted(m)
  for k,v in enumerate(m):
    m[k][1] = k
  all = [m[::2], m[1::2]]
  active = [all[0][:P], all[1][:P]]
  bench = [all[0][P:], all[1][P:]]
  for min in range(M):
    for i in range(2):
      for k,v in enumerate(active[i]):
        active[i][k][0] += 1
      if len(bench[i]) > 0:
        a = active[i][:-1] + [bench[i][0]]
        b = bench[i][1:] + [active[i][-1]]
        active[i] = sorted(a)
        bench[i] = sorted(b)
  return [x[-1] for x in active[0]+active[1]]

cases = int(sys.stdin.readline())
for case in range(cases):
  r = solve()
  s = "Case #" + str(case + 1) + ": "
  s += " ".join(sorted(r))
  print(s)
