N = 48
keyMap = [str(i) for i in range(N)]

keyString = "    "
for i in range(N):
  keyString += str(keyMap[i]) + ","
  if (i + 1) % 8 == 0:
    keyString += "\n    "

keyString = keyString[:-5]

print("""
char asciiMap[{N}] = {{
{string}
}}
""".format(N=N, string=keyString))
