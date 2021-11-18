import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv("eda_signal_normalized.csv", delimiter = ",", header = 0, names = ["signal", "time_series"], usecols = ["signal", "time_series"])
plt.figure()
plt.plot(data["time_series"], data["signal"])
plt.grid(True)
plt.show()
