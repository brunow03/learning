from sklearn import datasets
from sklearn.metrics import confusion_matrix
from sklearn.cluster import KMeans, AgglomerativeClustering, DBSCAN
import matplotlib.pyplot as plt
from scipy.cluster.hierarchy import linkage, dendrogram

iris = datasets.load_iris()
print(iris)

def plot_clusters(data, label, title):
	colors = ['red', 'green', 'purple', 'black']
	plt.figure(figsize=(8,4))
	for i,c,l in zip(range(-1,3), colors, ['Noise', 'Setosa', 'Versioncolor', 'Virginica']):
		if i == -1:
			plt.scatter(data[label == i, 0], data[label == i, 3], 
				c=colors[i], label=l, alpha=0.5, s=50, marker='x')
		else:
			plt.scatter(data[label == i, 0], data[label == i, 3], 
				c=colors[i], label=l, alpha=0.5, s=50)
	plt.legend()
	plt.title(title)
	plt.xlabel('Comprimento Sépala')
	plt.ylabel('Largura da Pétala')
	plt.show()

print(iris.target)

kmeans = KMeans(n_clusters=3, n_init='auto')
kmeans.fit(iris.data)
print(kmeans.labels_)

resultados = confusion_matrix(iris.target, kmeans.labels_)
print(resultados)

dbscan = DBSCAN(eps=0.5, min_samples=3)
dbscan_labels = dbscan.fit_predict(iris.data)
print(dbscan_labels)

plot_clusters(iris.data, dbscan_labels, 'Cluster DBSCAN')

# cluster hierarquico
agglo = AgglomerativeClustering(n_clusters=3)
agglo_labels = agglo.fit_predict(iris.data)
print(agglo_labels)

resultados = confusion_matrix(iris.target, agglo_labels)
print(resultados)

plot_clusters(iris.data, kmeans.labels_, 'Cluster Kmeans')


