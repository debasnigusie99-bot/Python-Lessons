import pandas as pd
from sklearn.linear_model import LinearRegression

df = pd.read_csv("big_scores.csv")
train = df.iloc[:2400000]
test = df.iloc[2400000:]

model = LinearRegression()
model.fit(train[["math"]], train["english"])

pred = model.predict(test[["math"]])
error = (test["english"] - pred).abs().mean()
print("Slope:", model.coef_[0])
print("Intercept:", model.intercept_)
print("Model test error:", error)
baseline = train["english"].mean()
base_error = (test["english"] - baseline).abs().mean()
print("Baseline test error:", base_error)