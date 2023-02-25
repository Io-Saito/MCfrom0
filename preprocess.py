# %%
import numpy as np
# %%
length_of_polymer = 20
number_of_polymer = 5
bond_length = 2
distance = 60

# %%
with open('start.txt', 'w') as f:
    x_ = 0
    y_ = 0
    z_ = 0
    for i in range(number_of_polymer):
        theta_ = np.random.uniform(0, 2*np.pi)
        phi_ = np.random.uniform(0, 2*np.pi)
        x_before = x_+distance*np.sin(phi_)*np.cos(theta_)
        y_before = y_+distance * np.sin(phi_)*np.sin(theta_)
        z_before = z_+np.cos(phi_)*distance
        
        for j in range(length_of_polymer):
            theta = np.random.uniform(0, 2*np.pi)
            phi = np.random.uniform(np.pi/2, 3*np.pi/2)
            x = x_before+bond_length*np.sin(phi)*np.cos(theta)
            y = y_before+bond_length * np.sin(phi)*np.sin(theta)
            z = z_before+np.cos(phi)*bond_length
            f.write(f"{x}    {y}    {z}\n")
            x_before = x
            y_before = y
            z_before = z
    x_=x_before
    y_=y_before
    z_=z_before


# %%
