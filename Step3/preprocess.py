# %%
import numpy as np
# %%
length_of_polymer = 10
number_of_polymer = 10

# %%
with open('start.txt', 'w') as f:
    for i in range(number_of_polymer):
        start_x = np.random.uniform(-15, 10)
        start_y = np.random.uniform(-15, 10)
        start_z = np.random.uniform(-15, 10)
        choose = np.random.choice([1, 2, 3])
        for j in range(length_of_polymer):
            if choose ==1:
                x = np.random.uniform(-1, 1)+start_x+2*j
                y = np.random.uniform(-1, 1)+start_y+2*i
                z = np.random.uniform(-1, 1)+start_z+2*i
            elif choose == 2:
                x = np.random.uniform(-1, 1)+start_x+2*i
                y = np.random.uniform(-1, 1)+start_y+2*j
                z = np.random.uniform(-1, 1)+start_z+2*i
            elif choose == 3:
                x = np.random.uniform(-1, 1)+start_x+2*i
                y = np.random.uniform(-1, 1)+start_y+2*j
                z = np.random.uniform(-1, 1)+start_z+2*i
            else:
                pass
            f.write(f"{x}    {y}    {z}\n")

# %%
