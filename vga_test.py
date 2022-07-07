import matplotlib.pyplot as plt

FCPU = 20 * 10**6  # 20 MHz
PIXEL_LENGTH = 200  # 200 nS
PIXEL_EVENTS_SEC = 10**9 / PIXEL_LENGTH
"""
<------><---><----><---->
   100    5    16    11
Visible   1     0     1

<-----><---><-----><---->
  75     1     4      23
Visible  1     0      1
"""
VSYNC = []
HSYNC = []
DATA = []
