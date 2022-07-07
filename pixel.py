from utils import repeat

# 100 Pixels
repeat(100, """
  ld r16, Z+
	ori r16, 0x3
	out 0x0b, r16
  """)
