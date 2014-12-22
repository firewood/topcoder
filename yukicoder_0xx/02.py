import sys

primes = [2]

def isprime(n):
  for p in primes:
    if p * p > n:
      return 1
    if (n % p) == 0:
      return 0
  return 1

n = 3
while n < 32000:
  if isprime(n):
    primes.append(n)
  n += 2

N = int(sys.stdin.readline())
ans = 0
for n in primes:
  a = 0
  while (N % n) == 0:
    N /= n
    a += 1
  ans ^= a
if N > 1:
  ans ^= 1

if ans:
  print("Alice")
else:
  print("Bob")
