from functools import reduce


def sparseHash(input_numbers, current_position, skip_size):
    for length in lengths:
        end = min(current_position + length, len(input_numbers))
        wrap_end = max(0, current_position + length - len(input_numbers))
        part = input_numbers[current_position:end] + input_numbers[:wrap_end]
        reversed_part = part[::-1]
        input_numbers = reversed_part[length - wrap_end:] + input_numbers[wrap_end:current_position] + reversed_part[:end - current_position] + input_numbers[end:]
        current_position += (length + skip_size)
        current_position %= len(input_numbers)
        skip_size += 1
    return input_numbers, current_position, skip_size


with open('../input/day10.txt', 'r') as file:
    inputPuzzle = file.read()
    lengths = list(map(lambda string: int(string), inputPuzzle.split(',')))
    numbersSize = 256
    numbers, _, _ = sparseHash(list(range(0, numbersSize)), 0, 0)
    print("star 1: %s" % (numbers[0] * numbers[1]))
    
    lengths = list(map(lambda character: int(ord(character)), inputPuzzle))
    lengths += [17, 31, 73, 47, 23]
    numbers = list(range(0, numbersSize))
    currentPosition = 0
    skipSize = 0
    for i in range(0, 64):
        numbers, currentPosition, skipSize = sparseHash(numbers, currentPosition, skipSize)
    denseHash = ''
    for i in range(0, 16):
        denseHash += "%0.2X" % reduce(lambda x, y: x ^ y, numbers[i * 16:i * 16 + 16])
    print("star 2: %s" % denseHash)
