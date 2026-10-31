import pandas as pd

df = pd.read_csv("big_scores.csv")
train = df.iloc[:24]    # first 24 rows
test = df.iloc[24:]     # last 6 rows
print(len(train), len(test))

baseline = train["english"].mean()
error = (test["english"] - baseline).abs().mean()
print("Baseline:", baseline)
print("Baseline test error:", error)