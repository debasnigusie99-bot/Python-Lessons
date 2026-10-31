import pandas as pd

df = pd.read_csv("scores.csv")
df["average"] = df[["math", "physics", "english"]].mean(axis=1)
print(df.sort_values("average", ascending=False))