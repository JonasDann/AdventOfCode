with open('../input/day5.txt', 'r') as file:
    inputPuzzle = file.read()
    rows = inputPuzzle.split("\n")
    jumps = list(map(lambda string: int(string), rows))
    jumpCount = 0
    jumpPointer = 0
    while jumpPointer >= 0 and jumpPointer < len(jumps):
        jumps[jumpPointer] += 1
        jumpPointer += jumps[jumpPointer] - 1
        jumpCount += 1
    print("star 1: %s" % jumpCount)

    jumps = list(map(lambda string: int(string), rows))
    jumpCount = 0
    jumpPointer = 0
    while jumpPointer >= 0 and jumpPointer < len(jumps):
        jump = jumps[jumpPointer]
        if jumps[jumpPointer] < 3:
            jumps[jumpPointer] += 1
        else:
            jumps[jumpPointer] -= 1
        jumpPointer += jump
        jumpCount += 1
    print("star 2: %s" % jumpCount)