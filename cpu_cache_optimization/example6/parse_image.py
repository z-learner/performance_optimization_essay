import matplotlib.pyplot as plt

size = [4, 64, 1024, 16384, 262144, 4194304] # KB
times = [49.1, 950, 17031, 478563, 29965577, 461015151]


res = []
for i in range(len(size)):
    res.append( size[i] / 1024 / times[i] * 1000000000 )


plt.figure()

# 绘制折线图
plt.plot(size, res)
plt.xlabel("size/(KB)")
plt.ylabel("bandwidth/(MB/S)")
plt.legend()
plt.show()
