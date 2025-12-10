from sklearn.neighbors import KNeighborsClassifier
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, confusion_matrix
import pandas as pd
import numpy as np

mtcars = pd.read_csv('/home/bruno/Git/Learning/IA/CursoIA/3.Algoritmos de Machine Learning/mt_cars.csv')
print(mtcars.head())

X = mtcars[['mpg', 'hp']].values
y = mtcars['cyl'].values

knn = KNeighborsClassifier(n_neighbors=3)
modelo = knn.fit(X,y)

print(modelo)

y_prev = modelo.predict(X)
print(y_prev)

accuracy = accuracy_score(y, y_prev)
precision = precision_score(y, y_prev, average='weighted')
recall = recall_score(y, y_prev, average='weighted')
f1 = f1_score(y, y_prev, average='weighted')
cm = confusion_matrix(y, y_prev)

print(f'Acurácia: {accuracy}, Precisão: {precision}, Recall: {recall}, F1: {f1}')
print('Matriz de confusão:\n', cm)

# 'mpg','hp'
new_data = np.array([[19.3, 105]])
previsao = modelo.predict(new_data)
print(previsao)

# 'cyl'

distances, indices = modelo.kneighbors(new_data)
print(distances)
print(indices)

print(mtcars.loc[[1,5,31], "cyl", "mpg", "hp"])



