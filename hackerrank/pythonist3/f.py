n = int(input())
s = input().split(' ')
k = int(input())

c = []
for i in range(0, n + 1):
  a = [1]
  for j in range(1, i + 1):
    a.append(c[i-1][j - 1] + c[i-1][j])
  a.append(0)
  c.append(a)

cnt = 0
for char in s:
  if char != 'a':
    cnt += 1

a = 0
if k <= cnt:
  a = c[cnt][k]

ans = float(c[n][k] - a) / float(c[n][k])
print(ans)
