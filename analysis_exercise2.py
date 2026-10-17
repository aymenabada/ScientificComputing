import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

data = np.loadtxt("iterations_history_filename.txt")

fig, ax = plt.subplots()

n = data[:,0]
x_n = data[:,1]
function = data[:,2]
ERRORS = abs(x_n - 7/3)

ax.plot(n, ERRORS, marker = 'o' ,color = "purple", linestyle = "--", label = r'$x_{0} = 5$')
ax.set_ylabel("ERROR")
ax.set_yscale("log")
ax.set_xlabel("ITERATION NUMBER")
ax.set_title("NEWTON'S CONVERGENCE RATES")
ax.legend()
ax.grid()
fig.savefig("errorplot.pdf", bbox_inches = "tight")
plt.show()

length=len(ERRORS[:-1])
RATIOS = []*length
for i,iplus1 in zip(ERRORS[:-1], ERRORS[1:]):
    ratio = iplus1/i   
    RATIOS.append(ratio)
    
lis = np.array([0,1.2])
n=n[:-1]
fig,ax2 = plt.subplots()
ax2.plot(ERRORS[:-1], ERRORS[1:], marker = 'o', color = 'purple', linestyle = 'none')
ax2.plot(lis, 0.5*lis, linestyle = '-.', color = 'black', label = r'$\frac{\partial\epsilon_{n+1}}{\partial\epsilon_n}$ = 0.499')
ax2.legend()
# ax2.plot(n, length * [0.4996201438494443], linestyle = '-.')
ax2.set_xlabel(r"$\epsilon_n$")
ax2.set_ylabel(r"$\epsilon_{n+1}$")
ax2.set_title("ERROR PLOT")
ax2.grid()
fig.savefig("errorvserrorplot.pdf", bbox_inches = "tight")
plt.show()

print("The ratios of errors are", [float(ratio) for ratio in (RATIOS)], "and the average is", np.average(RATIOS))
# print("The averge ratio value is", np.average(RATIOS))