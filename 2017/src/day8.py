import re


def instructionTuple(string):
    groups = re.search('([a-z]+) (inc|dec) (-?\d+) if ([a-z]+) ([!<>=]+) (-?\d+)', string).groups()
    return groups[0], int(groups[2]) * (-1 if groups[1] == 'dec' else 1), groups[3], groups[4], int(groups[5])


with open('../input/day8.txt', 'r') as file:
    inputPuzzle = file.read()
    ops = {"<": (lambda x, y: x < y), ">": (lambda x, y: x > y), "==": (lambda x, y: x == y),
           "<=": (lambda x, y: x <= y), ">=": (lambda x, y: x >= y), "!=": (lambda x, y: x != y)}
    instructions = list(map(instructionTuple, inputPuzzle.split("\n")))
    registers = dict()
    for instruction in instructions:
        if ops[instruction[3]](registers.get(instruction[2], 0), instruction[4]):
            if not (instruction[0] in registers):
                registers[instruction[0]] = 0
            registers[instruction[0]] += instruction[1]
    sortedValues = list(registers.values())
    sortedValues.sort()
    print("star 1: %s" % sortedValues[-1:][0])
