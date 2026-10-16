

import matplotlib.pyplot as plt
import numpy as np

alphas = [1.5, 3.2, 3.5, 3.62]

files = ["results.txt", "results2.txt", "results3.txt", "results4.txt"]

fig, axes = plt.subplots(2,2, figsize = (10,7))

for ax, alpha, file in zip(axes.flat, alphas, files):
    data = np.loadtxt(file, delimiter = "|", skiprows = 1, usecols = (0,1))

    n = data[:,0]
    x_n = data[:,1]
    ax.plot(n, x_n, color="purple", marker= ".", linestyle = "none")
    ax.set_xlabel("n")
    ax.set_ylabel(r"$x_n$")
    ax.set_title(f"Logistic Map (alpha = {alpha})")
    ax.grid(True, alpha = 0.3)
    
plt.tight_layout()

plt.savefig("plot.pdf", bbox_inches = "tight")
plt.show()

