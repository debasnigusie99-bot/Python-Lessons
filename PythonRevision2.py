class Student:
    def __init__(self, name):
        self.name = name
        self.scores = []

    def add_score(self, score):
        self.scores.append(score)

    def average(self):
        if len(self.scores) == 0:
            return None
        return sum(self.scores) / len(self.scores)


s = Student("Abel")
s.add_score(85)
s.add_score(85)
print(s.name, s.scores, s.average())
d = Student("Dawit")
d.add_score(60)
d.add_score(80)
print(d.name, d.average())
print(s.scores)
names = ["Sara", "Sara", "Hana"]
counts = {}
for name in names:
    counts[name] = counts.get(name, 0) + 1
print(counts)
