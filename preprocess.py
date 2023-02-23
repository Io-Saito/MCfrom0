# %%
import numpy as np
# %%
length_of_polymer = 10
number_of_polymer = 10
bond_length = 2

# %%
with open('start.txt', 'w') as f:
    for i in range(number_of_polymer):
        x_before = np.random.uniform(-15, 10)
        y_before = np.random.uniform(-15, 10)
        z_before = np.random.uniform(-15, 10)
        for j in range(length_of_polymer):
            theta = np.random.uniform(0, 2*np.pi)
            phi = np.random.uniform(0, 2*np.pi)
            x = x_before+bond_length*np.sin(phi)*np.cos(theta)
            y = y_before+bond_length * np.sin(phi)*np.cos(theta)
            z = z_before+np.cos(phi)
            f.write(f"{x}    {y}    {z}\n")
            x_before = x
            y_before = y
            z_before = z

# %%
