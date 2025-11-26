import numpy as np

array = np.array([[['A', 'B', 'C'], ['D', 'E', 'F'], ['G', 'H', 'I']],
                  [['A', 'B', 'C'], ['D', 'E', 'F'], ['G', 'H', 'I']],
                  [['S', 'B', 'C'], ['D', 'E', 'F'], ['G', 'H', 'I']]])

print(array)
print(array.ndim)
print(array.shape)
print(array[0][0][0]) # chain indexing
print(array[0, 0, 0]) # multidimensional indexing 

word = array[0, 0, 0] + array[2, 0, 0] + array[2, 0, 0]

print(word)
