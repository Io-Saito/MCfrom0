# %%
from plotly.subplots import make_subplots
import plotly.graph_objects as go
import pandas as pd
import plotly.express as px
import io
import PIL
import numpy as np
from tqdm import tqdm
from plotly.colors import qualitative
# %%
df = pd.read_csv("/Users/io/Project/Polymer_Monte_Carlo/Step3/finish.csv")
df["chain"] = df["chain"].astype(str)

# %%


fig_ = px.line_3d(
    data_frame=df,
    x="X",
    y="Y",
    z="Z",
    color='chain',
    markers=True,
    color_discrete_sequence=qualitative.Plotly,
    animation_frame='timestep')

print("figure converted")
fig_.update_layout(
    scene=dict(
        xaxis=dict(nticks=2, range=[-30, 30],),
        yaxis=dict(nticks=2, range=[-30, 30],),
        zaxis=dict(nticks=2, range=[-30, 30]),
        aspectratio=dict(x=1, y=1, z=1),
    ),
    width=800,
    height=800,
    margin=dict(r=20, l=10, b=10, t=10))

frames = []
for s, fr in tqdm(enumerate(fig_.frames)):
    # set main traces to appropriate traces within plotly frame
    fig_.update(data=fr.data)
    # move slider to correct place
    fig_.layout.sliders[0].update(active=s)
    # generate image of current state
    frames.append(PIL.Image.open(io.BytesIO(fig_.to_image(format="png"))))

# create animated GIF
frames[0].save(
    "plotly2.gif",
    save_all=True,
    append_images=frames[1:],
    optimize=True,
    duration=200,
    loop=0,
)
print("saved")
