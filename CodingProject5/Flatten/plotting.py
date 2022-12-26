import matplotlib.pyplot as plt

threads1 = [
    0,
    2,
    4,
    6,
    8,
    10,
    12,
    14,
    16,
]

times1 = [
    67155.5,  # 0
    39068.4,  # 2
    25012.5,  # 4
    19421.5,  # 6
    15685.3,  # 8
    13089.6,  # 10
    12074.9,  # 12
    11662.5,  # 14
    13590.0,  # 16
]

threads2 = [
    0,
    2,
    4,
    6,
    8,
    10,
    12,
    14,
    16,
]

times2 = [
    95125,  # 0
    47523,  # 2
    32322,  # 4
    27341,  # 6
    22258,  # 8
    18821,  # 10
    16656,  # 12
    17323,  # 14
    21407,  # 16
]

plt.plot(threads1, times1)
plt.bar(threads1, times1)
plt.plot(threads2, times2)
plt.bar(threads2, times2)
plt.xlabel("#Threads")
plt.ylabel("Time (us)")
plt.xticks(threads2)
plt.show()
