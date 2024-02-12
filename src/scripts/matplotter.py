from matplotlib import figure
import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(1, 1000, num=1000)
# x = np.array([1, 5000, 10000, 15000])
print(x)
y = x * np.log2(x)

plt.plot(x, y)
plt.plot(x, x)
plt.plot(x, x**2)
plt.plot(x, np.log2(x))
plt.axis("square")
plt.ylim(0, 1000)
plt.xlim(1, 1000)
plt.show()
