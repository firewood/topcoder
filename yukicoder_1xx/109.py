import sys

primes = [2]

def isprime(n):
  for p in primes:
    if p * p > n:
      return 1
    if (n % p) == 0:
      return 0
  return 1

def extgcd(a, b, x, y):
  d = a
  if b != 0:
    (d, y, x) = extgcd(b, a % b, y, x)
    y -= (a / b) * x
  else:
    x = 1
    y = 0
  return (d, x, y)

def modinv(a, m):
  (d, x, y) = extgcd(a, m, 1, 0)
  return (x + m) % m

def solve(N, M):
  r = 1
  if M <= N or M <= 1:
    return 0
  if M <= 200000:
    for n in range(2, N+1):
      r = (r * n) % M
    return r
  if not isprime(M):
    return 0
  r = M - 1
  for n in range(N+1, M):
    r = (r * n) % M
  return modinv(r, M)

n = 3
while n < 32000:
  if isprime(n):
    primes.append(n)
  n += 2

T = int(sys.stdin.readline())
for t in range(T):
  (N, M) = [int(x) for x in sys.stdin.readline().rstrip("\n").split(" ")]
  print(solve(N, M))
