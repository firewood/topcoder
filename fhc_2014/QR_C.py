# Facebook Hacker Cup 2014 Qualification Round
# C. Tennison

import sys

def solve():
  total = 0.0
  args = sys.stdin.readline().rstrip().split(' ')
  K = int(args[0])
  (P_sun, P_rain, P_init, P_up, P_win, P_down, P_lose) = [float(x) for x in args[1:]]
  current = [{P_init:1.0}]
  for set_no in range(K*2):
    next = [{} for x in range(K+1)]
    for wins,s in enumerate(current):
      loses = set_no - wins
      if loses >= K:
        continue
      if wins >= K:
        for x in s:
          total += s[x]
        continue
      for sun in s:
        p = s[sun]
        sunny = p * sun
        rainy = p - sunny
        sunny_win = sunny * P_sun
        sunny_lose = sunny - sunny_win
        sunny_up = sunny_win * P_win
        sunny_down = sunny_lose * P_lose
        rainy_win = rainy * P_rain
        rainy_lose = rainy - rainy_win
        rainy_up = rainy_win * P_win
        rainy_down = rainy_lose * P_lose
        w = [[sunny_up+rainy_up,min(1.0,sun+P_up)],[sunny_win-sunny_up+rainy_win-rainy_up,sun]]
        l = [[sunny_down+rainy_down,max(0.0,sun-P_down)],[sunny_lose-sunny_down+rainy_lose-rainy_down,sun]]
        for x in w:
          if x[1] in next[wins+1]:
            next[wins+1][x[1]] += x[0]
          else:
            next[wins+1][x[1]] = x[0]
        for x in l:
          if x[1] in next[wins]:
            next[wins][x[1]] += x[0]
          else:
            next[wins][x[1]] = x[0]
    current = next
  return total

cases = int(sys.stdin.readline())
for case in range(cases):
  r = solve()
  print("Case #%d: %f" % (case+1, r))
