import matplotlib.pyplot as plt
import pandas as pd

# data = pd.read_csv("gsr_samples.csv", delimiter = ",", header = 0, names = ["signal", "time_series"], usecols = ["signal", "time_series"])
# plt.figure()
# plt.title("Signal EDA")
# plt.plot(data["time_series"], data["signal"])
# plt.grid(True)
# plt.show()


data = pd.read_csv("eda_signal_filtered_k.csv", delimiter = ",", header = None, names = ["signal", "time_series"], usecols = ["signal", "time_series"])
data_1 = pd.read_csv("trough_to_peak.csv", delimiter = ",", header = None, names = ["values", "indices"], usecols = ["values", "indices"])
print(data_1["indices"])
plt.figure()
plt.plot(data["time_series"], data["signal"], color="navy")
plt.scatter(data_1["indices"], data["signal"][data_1["indices"][:]], color="red")
for i in data_1["indices"]:
    plt.vlines(i-10, ymin=0, ymax=1, linestyle="--")
    plt.vlines(i+10, ymin=0, ymax=1, linestyle="--")
# plt.plot(X[criticals_indices_in_signal[0]:], normalized_signal[criticals_indices_in_signal[0]:], color="yellow")
plt.grid(True)
plt.xlabel("Samples")
plt.ylabel("Conductance")
plt.title("EDA signal")
plt.show()