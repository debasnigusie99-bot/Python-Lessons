import numpy as np

x = np.random.choice([5, 2, 7], p=[0.3, 0.7, 0.0], size=(100))
print(x)
count = 0
for value in x:
    if value == 2:
        count += 1
print(count)
adder = 0
for item in x:
    if item == 5:
        adder += 1
print(adder)
permutation = np.random.permutation
print(permutation([1,2,3,4]))
