from functools import reduce


def equal_pair(pair):
    if pair[0] == pair[1]:
        return int(pair[0])
    else:
        return 0


def sum_equal_pairs(char_pairs):
    equal_pairs = map(equal_pair, char_pairs)
    return reduce(lambda x, y: x + y, equal_pairs)


with open('../input/day1.txt', 'r') as file:
    inputPuzzle = file.read()
    previousChar = inputPuzzle[-1:]
    charPairs = []
    for char in inputPuzzle:
        charPairs.append(previousChar + char)
        previousChar = char
    sumEqualPairs = sum_equal_pairs(charPairs)
    print("star 1: %s" % sumEqualPairs)

    charPairs = []
    for index, char in enumerate(inputPuzzle):
        charPairs.append(char + inputPuzzle[int((index + len(inputPuzzle) / 2)) % len(inputPuzzle)])
    sumEqualPairs = sum_equal_pairs(charPairs)
    print("star 2: %s" % sumEqualPairs)
