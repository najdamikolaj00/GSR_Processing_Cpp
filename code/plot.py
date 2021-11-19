import matplotlib.pyplot as plt
import pandas as pd

data = pd.read_csv("eda_signal_filtered_k102.csv", delimiter = ",", header = 0, names = ["signal", "time_series"], usecols = ["signal", "time_series"])
plt.figure()
plt.title("Signal EDA")
plt.plot(data["time_series"], data["signal"])
plt.grid(True)
plt.show()
