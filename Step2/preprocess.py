# %%
import numpy as np
# %%
length_of_polymer = 10
number_of_polymer = 10

# %%
with open('start.txt', 'w') as f:
    for i in range(number_of_polymer):
        for j in range(length_of_polymer):
            x = np.random.uniform(-1, 1)+190+2*i
            y = np.random.uniform(-1, 1)+190+2*j
            z = np.random.uniform(-1, 1)+210-2*i
            f.write(f"{x}    {y}    {z}\n")

# %%
