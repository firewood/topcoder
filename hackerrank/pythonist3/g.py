import re

def validate(s):
  a = "".join(s.split('-'))
  return (re.match(r"\d{16,16}$", s) or re.match(r"\d{4,4}-\d{4,4}-\d{4,4}-\d{4,4}$", s)) and \
      re.match(r"[456]", s) and \
      (not re.search(r"(\d)\1{3,}", a))

n = int(input())
for i in range(n):
  if validate(input().strip()):
    print("Valid")
  else:
    print("Invalid")
