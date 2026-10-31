import csv

with open("scores.csv") as f:
    rows = list(csv.DictReader(f))

for subject in ["math", "physics", "english"]:
    scores = [int(r[subject]) for r in rows]
    print(subject, sum(scores) / len(scores))