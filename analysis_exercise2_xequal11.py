import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

data = np.loadtxt("iterations_history_filename.txt")

fig, ax = plt.subplots()

n = data[:,0]
x_n = data[:,1]
function = data[:,2]
ERRORS = abs(x_n - 11)

ax.plot(n, ERRORS, marker = 'o' ,color = "purple", linestyle = "--", label = r'$x_{0} = -100$')
ax.set_ylabel("ERROR")
ax.set_yscale("log")
ax.set_xlabel("ITERATION NUMBER")
ax.set_title("NEWTON'S CONVERGENCE RATES")
ax.legend()
ax.grid()
fig.savefig("errorplot2.pdf", bbox_inches = "tight")
plt.show()

length=len(ERRORS)-1
RATIOS = []*length
for i,iplus1 in zip(ERRORS[:-1], ERRORS[1:]):
    ratio = np.sqrt(iplus1)/i
    
    RATIOS.append(ratio)
    

n=n[:-1]
fig,ax2 = plt.subplots()
ax2.plot(ERRORS[:-1], ERRORS[1:], marker = 'o', color = 'purple', linestyle = 'none')
# ax2.plot(n, length * [0.5], linestyle = '-.', color = 'black', label = r'$\overline{\epsilon_{n}}$ = 0.499')
# ax2.legend()
# ax2.plot(n, length * [0.4996201438494443], linestyle = '-.')
ax2.set_xlabel("ITERATION NUMBER")
ax2.set_ylabel("RATIOS")
ax2.set_title("ERRORSPLOT")
ax2.grid()
fig.savefig("errorvserrorplot2.pdf", bbox_inches = "tight")
plt.show()

print("The ratios of errors are", [float(ratio) for ratio in (RATIOS)], "and the average is", np.average(RATIOS))
# print("The averge ratio value is", np.average(RATIOS))