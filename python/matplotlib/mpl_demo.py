import numpy as np
from matplotlib import pyplot as plt

# print(plt.style.available)
# plt.style.use('fivethirtyeight')
plt.xkcd()

ages_x = []

x_indexes = np.arange(len(ages_x))
width = 0.25

dev_y = []

# plt.plot(ages_x, dev_y, color='#444444', linestyle='--', marker='.', label='First plot')
plt.bar(x_indexes - width, dev_y, width=width, color='#444444', linestyle='--', marker='.', label='First plot')

py_dex_y = []

plt.bar(x_indexes, py_dex_y, width=width, color='b', marker='o', linewidth=3, label='Second plot')

js_dev_y = []
plt.bar(x_indexes + width, js_dev_y, width=width, color='#adad3b', linewidth=3, label='JS')

plt.xlabel('Abscissa')
plt.ylabel('Ordenada')
plt.title('Title')

plt.legend() # ['First plot', 'Second plot']

plt.xticks(ticks=x_indexes, labels=ages_x)

plt.grid(True)

plt.tight_layout()

plt.savefig('plot.png')

plt.show()






















