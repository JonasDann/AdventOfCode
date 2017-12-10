with open('../input/day9.txt', 'r') as file:
    inputPuzzle = file.read()
    score = 0
    groupScore = 0
    garbageCount = 0
    garbage = False
    escaped = False
    for character in inputPuzzle:
        if not escaped:
            if garbage:
                if character == '!':
                    escaped = True
                elif character == '>':
                    garbage = False
                else:
                    garbageCount += 1
            elif character == '{':
                groupScore += 1
                score += groupScore
            elif character == '}':
                groupScore -= 1
            elif character == '<':
                garbage = True
        else:
            escaped = False
    print("star 1: %s" % score)
    print("star 2: %s" % garbageCount)
