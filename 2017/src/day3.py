import math

inputSquare = 368078
innerWidth = math.floor(math.sqrt(inputSquare))
if innerWidth % 2 == 0:
    innerWidth -= 1
halfWidth = math.floor(innerWidth / 2)
lastInner = math.pow(innerWidth, 2)
remaining = inputSquare - lastInner - 1
if lastInner != inputSquare:
    manhattanDistance = halfWidth + 1 + (
        ((halfWidth + 1) / math.pi) * math.acos(math.cos((remaining - halfWidth) * math.pi / (halfWidth + 1))))
else:
    manhattanDistance = 2 * halfWidth
print("star 1: %s" % int(manhattanDistance))


def getValue(list, x, y):
    shifted_x = int(x + math.floor(len(list) / 2))
    shifted_y = int(y + math.floor(len(list) / 2))
    if len(list) > shifted_x >= 0 and len(list[x]) > shifted_y >= 0:
        return list[shifted_x][shifted_y]
    else:
        return 0


grid = [[0] * 3, [0, 1, 0], [0] * 3]
current = 1
x = 1
y = 0
while True:
    current = 0
    for xDiff in range(-1, 2):
        for yDiff in range(-1, 2):
            if xDiff != 0 or yDiff != 0:
                current += getValue(grid, x + xDiff, y + yDiff)
    shiftedX = int(x + math.floor(len(grid) / 2))
    shiftedY = int(y + math.floor(len(grid) / 2))
    grid[shiftedX][shiftedY] = current
    if getValue(grid, x, y + 1) != 0 and getValue(grid, x + 1, y) == 0:
        x += 1
        if getValue(grid, x, y + 1) == 0:
            for column in grid:
                column.insert(0, 0)
                column.append(0)
            newLength = len(grid) + 2
            grid.insert(0, [0] * newLength)
            grid.append([0] * newLength)
    elif getValue(grid, x - 1, y) != 0:
        y += 1
    elif getValue(grid, x, y - 1) != 0:
        x -= 1
    else:
        y -= 1
    if current > inputSquare:
        break
print("star 2: %s" % current)
