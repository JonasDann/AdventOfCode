from functools import reduce


def evenlyDivisibleDiff(row):
    for i in range(0, len(row)):
        for j in range(0, len(row)):
            if i != j and int(row[i]) % int(row[j]) == 0:
                return int(int(row[i]) / int(row[j]))


def smallest(a, b):
    if int(a) < int(b):
        return int(a)
    else:
        return int(b)


def largest(a, b):
    if int(a) > int(b):
        return int(a)
    else:
        return int(b)


with open('../input/day2.txt', 'r') as file:
    inputPuzzle = file.read()
    rows = inputPuzzle.split("\n")
    spreadsheet = list(map(lambda row: row.split("\t"), rows))
    smallestLargest = map(lambda row: reduce(largest, row) - reduce(smallest, row), spreadsheet)
    print("star 1: %s" % sum(smallestLargest))

    evenlyDivisibleDiffs = map(evenlyDivisibleDiff, spreadsheet)
    print("star 2: %s" % sum(evenlyDivisibleDiffs))
