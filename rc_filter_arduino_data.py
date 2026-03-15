import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv("arduino_data_3.csv")

print(df.head())

plt.plot(df["t"], df["V_in"], label="V_in")
plt.plot(df["t"], df["V_c"], label="V_c")
plt.plot(df["t"], df["V_th"], label="V_th")
plt.plot(df["t"], df["x_1"], label="x_1")  
plt.plot(df["t"], df["x_2"], label="x_2")
plt.xlabel("Time (s)")
plt.ylabel("ADC value")
plt.legend()
plt.grid(True)
plt.show()