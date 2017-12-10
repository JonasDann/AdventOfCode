import re

import sys


def instructionTuple(string):
    groups = re.search('([a-z]+) (inc|dec) (-?\d+) if ([a-z]+) ([!<>=]+) (-?\d+)', string).groups()
    return groups[0], int(groups[2]) * (-1 if groups[1] == 'dec' else 1), groups[3], groups[4], int(groups[5])


with open('../input/day8.txt', 'r') as file:
    inputPuzzle = file.read()
    conditions = {"<": (lambda x, y: x < y), ">": (lambda x, y: x > y), "==": (lambda x, y: x == y),
                  "<=": (lambda x, y: x <= y), ">=": (lambda x, y: x >= y), "!=": (lambda x, y: x != y)}
    instructions = list(map(instructionTuple, inputPuzzle.split("\n")))
    registers = dict()
    highestEver = -sys.maxsize - 1
    for instruction in instructions:
        register, value, condRegister, condition, condValue = instruction
        if conditions[condition](registers.get(condRegister, 0), condValue):
            if not (register in registers):
                registers[register] = 0
            registers[register] += value
            if registers[register] > highestEver:
                highestEver = registers[register]
    sortedValues = list(registers.values())
    sortedValues.sort()
    print("star 1: %s" % sortedValues[-1:][0])
    print("star 2: %s" % highestEver)