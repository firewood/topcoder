import re

def decode(n, m, s):
  a = ""
  for i in range(m):
    for j in range(n):
      a = a + s[j][i]
  return re.sub(r"([A-Za-z0-9])[ !@#$%&]+([A-Za-z0-9])", r"\1 \2", a)

(n, m) = [int(x) for x in input().split(' ')]
a = []
for i in range(n):
  a.append(input())
print(decode(n, m, a))
