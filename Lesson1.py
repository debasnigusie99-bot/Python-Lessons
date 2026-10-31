# 1. Function definition (top)
def parse_score(text):
    score = int(text)
    if score < 0 or score > 100:
        raise ValueError("score must be between 0 and 100")
    return score
def assert_rejects(text):
    try:
        parse_score(text)
    except ValueError:
        return
    assert False, "should have raised ValueError"

# 2. Tests (right below the function)
assert parse_score("85") == 85
assert parse_score("0") == 0
assert parse_score("100")==100
assert_rejects("150")
assert_rejects("abc")
assert_rejects("-5")

scores = []
for _ in range(3):
    while True:
        text = input("Enter a score:")
        try:
            score = parse_score(text)
        except ValueError:
            print("Invalid score, try again.")
            continue
        scores.append(score)
        break

total = 0
for x in scores:
    total += x
average = total / len(scores)
highest = scores[0]
lowest = scores[0]
for x in scores:
    if x > highest:
        highest = x
for x in scores:
    if x < lowest:
        lowest = x
print("Average:", average)
print("Highest:", highest)
print("Lowest:", lowest)
if average >= 50:
    print("Passed")
else:
    print("Failed")
