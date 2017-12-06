import math

with open('../input/day6.txt', 'r') as file:
    inputPuzzle = file.read()
    banks = list(map(lambda string: int(string), inputPuzzle.split("\t")))
    distributions = []
    while not (banks in distributions):
        distributions.append(banks)
        biggestBank = 0
        for index, bank in enumerate(banks):
            if bank > banks[biggestBank]:
                biggestBank = index
        newBanks = list(banks)
        newBanks[biggestBank] = 0
        for index, bank in enumerate(banks):
            newBanks[index] += math.floor(banks[biggestBank] / len(banks))
            if (index - biggestBank - 1) % len(banks) < banks[biggestBank] % len(banks):
                newBanks[index] += 1
        banks = newBanks
    print("star 1: %s" % len(distributions))

    indexOfFirst = distributions.index(banks)
    print("star 2: %s" % (len(distributions) - indexOfFirst))
