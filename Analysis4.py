import pandas as pd

df = pd.read_csv("scores.csv")
baseline = df["english"].mean()
error = (df["english"] - baseline).abs().mean()
print("Baseline:", baseline)
print("Average error:", error)