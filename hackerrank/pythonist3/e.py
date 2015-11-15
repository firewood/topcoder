import re

s = input().strip()
pat = r"(\d)\1*"
i = re.finditer(pat, s)
ans = []
for match in i:
  count = match.end() - match.start()
  char = int(match.group()[0])
  ans.append(str((count, char)))

print(" ".join(ans))
