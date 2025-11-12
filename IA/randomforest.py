import pandas as pd
import numpy as np
from pandas.core.common import random_state
from sklearn.model_selection import train_test_split
from sklearn.ensemble import RandomForestClassifier
from sklearn.preprocessing import LabelEncoder
from sklearn.metrics import accuracy_score, precision_score, recall_score, f1_score, classification_report
import matplotlib.pyplot as plt
from sklearn.tree import plot_tree

base = pd.read_csv("/home/bruno/Git/Learning/IA/CursoIA/3.Algoritmos de Machine Learning/insurance.csv", keep_default_na=False)
print(base.head())

y = base.iloc[:,7].values
X = base.drop(base.columns[7], axis=1).values
print(X)	

labelencoder = LabelEncoder()
for i in range(X.shape[1]):
	if X[:,i].dtype == 'object':
		X[:,i] = labelencoder.fit_transform(X[:,i])

X_treinamento, X_teste, y_treinamento, y_teste = train_test_split(X, y, test_size=0.3, random_state=11)

modelo = RandomForestClassifier(random_state=1, max_depth=20, max_leaf_nodes=12, n_estimators=500)
modelo.fit(X_treinamento, y_treinamento)

tree_index = 1
tree_to_visualize = modelo.estimators_[tree_index]
plt.figure(figsize=(7,7))
plot_tree(tree_to_visualize, filled=True, feature_names=base.columns[:-1], class_names=True, rounded=True)
plt.show()

previsoes = modelo.predict(X_teste)
print(previsoes)

accuracy = accuracy_score(y_teste, previsoes)
precision = precision_score(y_teste, previsoes, average='weighted')
recall = recall_score(y_teste, previsoes, average='weighted')
f1 = f1_score(y_teste, previsoes, average='weighted')
print(f'Acurácia: {accuracy}, Precisão: {precision}, Recall: {recall}, F1: {f1}')

report = classification_report(y_teste, previsoes)
print(report)














