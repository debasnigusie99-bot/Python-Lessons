grades = {"Abel": [85, 90], "Sara": [70]}
import json, os


def save(data, path):
    with open(path, "w") as f:
        json.dump(data, f)


def load(path):
    if not os.path.exists(path):
        return {}
    with open(path) as f:
        return json.load(f)


def parse_score(text):
    score = int(text)
    if score < 0 or score > 100:
        raise ValueError("score must be between 0 and 100")
    return score


save(grades, "test.json")
assert load("test.json") == grades
assert load("missing.json") == {}


def add_score(data, name, text):
    score = parse_score(text)
    data.setdefault(name, []).append(score)


def average(data, name):
    scores = data.get(name, [])
    if len(scores) == 0:
        return None
    return sum(scores) / len(scores)


d = {}
add_score(d, "Abel", "85")
add_score(d, "Abel", "95")
assert d == {"Abel": [85, 95]}
assert average(d, "Abel") == 90
assert average({"Sara": []}, "Sara") is None
assert average({"Abel": [85]}, "Dawit") is None

try:
    add_score(d, "Abel", "abc")
    assert False, "should have raised ValueError"
except ValueError:
    pass
assert d == {"Abel": [85, 95]}
FILE = "grades.json"
data = load(FILE)


while True:
    choice = input("1) Add score  2) Show averages  3) Quit: ")
    if choice == "1":
        name = input("Name: ")
        text = input("Score: ")
        try:
            add_score(data, name, text)
        except ValueError:
            print("Invalid score.")
        else:
            save(data, FILE)
    elif choice == "2":
        for name in data:
            result = average(data, name)
            if result is None:
                print(name, "no scores yet")
            else:
                print(name, result)
    elif choice == "3":
        break
    else:
        print("Choose 1, 2 or 3.")
   
