import re

def validate(s):
  return re.match(r"(\d){6,6}$", s) != None and \
      s[0] != "0" and \
      len(list(filter(lambda i:re.match(r"(\d).\1", s[i:]), range(4)))) <= 1

print(validate(input()))
