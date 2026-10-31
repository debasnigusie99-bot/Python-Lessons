import random
import pandas as pd

random.seed(42)
rows = []
for i in range(3000000):
    math = random.randint(40, 100)
    english = int(0.5 * math + 35 + random.randint(-8, 8))
    rows.append({"name": f"S{i+1}", "math": math, "english": english})

pd.DataFrame(rows).to_csv("big_scores.csv", index=False)
print("saved")