import csv
from collections import Counter
import pandas as pd
import numpy as np
from matplotlib import pyplot as plt
import matplotlib

matplotlib.use("QtAgg")
plt.xkcd()

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

plt.barh(languages, popularity) # horizontal bar chart

plt.title('Most popular Programming Languages')
plt.xlabel('Number of users')

plt.tight_layout()

plt.show()

















