def predict(xs, slope, intercept):
    return [slope * x + intercept for x in xs]

def mae(real, pred):
    return sum(abs(r - p) for r, p in zip(real, pred)) / len(real)
assert predict([10, 20], 0.5, 35) == [40.0, 45.0]
assert mae([10, 20], [12, 17]) == 2.5
import csv

with open("big_scores.csv") as f:
    rows = list(csv.DictReader(f))

xs = [int(r["math"]) for r in rows[:240]]
ys = [int(r["english"]) for r in rows[:240]]

best_error = None
best_slope = None
best_intercept = None

for s in range(0, 101):
    slope = s / 100
    for intercept in range(0, 61):
        err = mae(ys, predict(xs, slope, intercept))
        if best_error is None or err < best_error:
            best_error = err
            best_slope = slope
            best_intercept = intercept

print(best_slope, best_intercept, best_error)
test_xs = [int(r["math"]) for r in rows[240:]]
test_ys = [int(r["english"]) for r in rows[240:]]

test_error = mae(test_ys, predict(test_xs, best_slope, best_intercept))
print("Test error:", test_error)