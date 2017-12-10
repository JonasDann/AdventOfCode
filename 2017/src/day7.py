import re


def programTuple(string):
    groups = re.search('([a-z]*) \(([0-9]*)\)( -> ([a-z, ]*))?', string).groups()
    children = []
    if groups[2]:
        children = groups[3].split(', ')
    return groups[0], int(groups[1]), children


def getCorrectWeight(program, siblingWeight):
    children = programDict[program]
    if len(children) == 2 and resolvedWeightDict[children[0]] != resolvedWeightDict[children[1]]:
        correctWeight = getCorrectWeight(children[0], resolvedWeightDict[children[1]])
        return correctWeight if correctWeight != programWeightDict[children[0]] else getCorrectWeight(children[1], resolvedWeightDict[children[0]])
    elif len(children) > 2:
        correctChildrenWeight = resolvedWeightDict[children[0]]
        wrongChildIndex = -1
        for index, child in enumerate(children[1:]):
            if correctChildrenWeight != resolvedWeightDict[child]:
                wrongChildIndex = index + 1
                if index == 0 and correctChildrenWeight != resolvedWeightDict[children[index + 2]]:
                    correctChildrenWeight = resolvedWeightDict[child]
                    wrongChildIndex = 0
                break
        if wrongChildIndex > -1:
            return getCorrectWeight(children[wrongChildIndex], correctChildrenWeight)
    return programWeightDict[program] + siblingWeight - resolvedWeightDict[program]



with open('../input/day7.txt', 'r') as file:
    inputPuzzle = file.read()
    programs = list(map(programTuple, inputPuzzle.split("\n")))
    programDict = dict([(program[0], program[2]) for program in programs])
    reverseProgramDict = dict([(child, parent[0]) for parent in programs for child in parent[2]])
    root = next(iter(reverseProgramDict.values()))
    while root in reverseProgramDict:
        root = reverseProgramDict.get(root)
    print("star 1: %s" % root)

    programWeightDict = dict(map(lambda program: (program[0], program[1]), programs))
    resolvedWeightDict = dict()
    for program in programWeightDict.keys():
        currentProgram = program
        while currentProgram in reverseProgramDict:
            if not (currentProgram in resolvedWeightDict):
                resolvedWeightDict[currentProgram] = 0
            resolvedWeightDict[currentProgram] += programWeightDict[program]
            currentProgram = reverseProgramDict[currentProgram]
    correctWeight = getCorrectWeight(root, 0)
    print("star 2: %s" % correctWeight)
