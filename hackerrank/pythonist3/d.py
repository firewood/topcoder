from functools import reduce

def hoge(s):
  c = ord(s)
  if s >= "0" and s <= "9":
    return c + 1000 - (c % 2) * 100
  if s >= "A" and s <= "Z":
    return c + 100
  return c

s = input().strip()
print(reduce(lambda x,y:x+y,sorted(s, key=hoge)))
