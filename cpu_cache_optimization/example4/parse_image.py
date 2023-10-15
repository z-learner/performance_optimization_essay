import matplotlib.pyplot as plt

threads_num = [1,2,4,6,8,10]
func_a = [45368816, 28174026, 21314657, 21695255, 26098804, 25468590]
func_b = [128785640, 65542418, 34245280, 26615415, 34143993, 32400082]
func_c = [345687645, 180377788, 92040850, 69250891, 66929151, 59113950]


plt.figure()

# 绘制折线图
plt.plot(threads_num, func_a, label = "func_a")
plt.plot(threads_num, func_b, label = "func_b")
plt.plot(threads_num, func_c, label = "func_c")

plt.legend()
plt.show()
