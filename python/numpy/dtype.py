import numpy as np

# array = np.array([1,2,3,4], dtype=np.int16)
# array = np.array([1,2,3,4], dtype=np.float16)
# array = np.array([1,2,3,4], dtype=np.bool_)
# array = np.array([1,2,3,4], dtype=np.str_)
# array = np.array(["apple", "orange", "banana"], dtype=np.str_)
# array = np.array(["apple", "orange", "banana"], dtype="<U4")
# array = np.array([1, 2.1, "apple", 4, True], dtype=np.object_)
array = np.array([1,2,3,4])

array = array.astype(np.float16)

print(array)
print(array.dtype)
print(f"{array.nbytes} bytes")
