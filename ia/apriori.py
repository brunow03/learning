import pandas as pd
from mlxtend.preprocessing import TransactionEncoder
from mlxtend.frequent_patterns import apriori, association_rules

# criar uma lista onde cada elemento da lista tem uma lista com as transações
with open('./CursoIA/3.Algoritmos de Machine Learning/Transacoes.txt') as f:
	transactions = [line.strip().split(",") for line in f.readlines()]

print("\n transactions \n")
for line in transactions:
	print(line)

te = TransactionEncoder()
te_array = te.fit(transactions).transform(transactions)
df = pd.DataFrame(te_array, columns=te.columns_)
print("\n df \n")
print(df)

frequent_itemsets = apriori(df, min_support=0.5, use_colnames=True)
print("\n frequent_itemsets \n")
print(frequent_itemsets)

rules = association_rules(frequent_itemsets, metric="confidence", min_threshold=0.5)
print("\n rules \n")
print(rules)

