#!/usr/bin/env python3

from collections import Counter

def score(S):
  s = 0
  for i in range(1, 10):
    s += i * 10 ** S.count(i)
  return s

K = int(input())
S = [int(x) for x in input()[:-1]]
T = [int(x) for x in input()[:-1]]

ans = 0
for i in range(1, 10):
  if (S + T).count(i) >= K:
    continue
  p = (K - (S + T).count(i)) / (K * 9 - len(S + T))
  S2 = S + [i]
  for j in range(1, 10):
    if (S2 + T).count(j) >= K:
      continue
    if score(S2) > score(T + [j]):
      ans += p * (K - (S2 + T).count(j)) / (K * 9 - len(S2 + T))
print(ans)
