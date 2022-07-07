def CIncludeASMString(string):
  print("""\"{}\\t\\n\"""".format(string))


def repeat(times, commands):
  for i in range(times):
    for command in commands.split("\n"):
      command = command.strip()
      if command in ["", "\n"]:
        continue
      CIncludeASMString(command)
