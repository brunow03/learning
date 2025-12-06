import csv
from collections import Counter
import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
import matplotlib

# print(plt.style.available)
# plt.style.use('fivethirtyeight')
matplotlib.use("QtAgg")
plt.xkcd()

# ages_x = []

# x_indexes = np.arange(len(ages_x))
# width = 0.25

# dev_y = []

# # plt.plot(ages_x, dev_y, color='#444444', linestyle='--', marker='.', label='First plot')
# plt.bar(x_indexes - width, dev_y, width=width, color='#444444', linestyle='--', marker='.', label='First plot')

# py_dex_y = []

# plt.bar(x_indexes, py_dex_y, width=width, color='b', marker='o', linewidth=3, label='Second plot')

# js_dev_y = []
# plt.bar(x_indexes + width, js_dev_y, width=width, color='#adad3b', linewidth=3, label='JS')

# plt.xlabel('Abscissa')
# plt.ylabel('Ordenada')
# plt.title('Title')

# plt.legend() # ['First plot', 'Second plot']

# plt.xticks(ticks=x_indexes, labels=ages_x)

# plt.grid(True)

# plt.tight_layout()

# plt.savefig('plot.png')

# plt.show()

# WITH METHOD

# with open('data.csv') as csv_file:
#     csv_reader = csv.DictReader(csv_file)

#     language_counter = Counter()

#     # row = next(csv_reader)
#     # print(row['LanguagesWorkedWith'].split(';'))

#     for row in csv_reader:
#         language_counter.update(row['LanguagesWorkedWith'].split(';'))

# PANDAS METHOD

data = pd.read_csv('data.csv')
ids = data['Responder_id']
lang_responses = data['LanguagesWorkedWith']

language_counter = Counter()

for response in lang_responses:
    language_counter.update(response.split(';'))

languages = []
popularity = []

for item in language_counter.most_common(15):
    languages.append(item[0])
    popularity.append(item[1])

languages.reverse()
popularity.reverse()

# plt.bar(languages, popularity)
plt.barh(languages, popularity) # horizontal bar chart

plt.title('Most popular Programming Languages')
# plt.ylabel('Programming Languages')
plt.xlabel('Number of users')

plt.tight_layout()

plt.show()

# print(language_counter.most_common(15))
















