def isAnagram(str1, str2):
    str1_list = list(str1)
    str1_list.sort()
    str2_list = list(str2)
    str2_list.sort()

    return str1_list == str2_list


def passphraseHasAnagram(passphrase):
    prevWords = []
    for word in passphrase:
        for prevWord in prevWords:
            if isAnagram(word, prevWord):
                return False
        prevWords.append(word)
    return True


with open('../input/day4.txt', 'r') as file:
    inputPuzzle = file.read()
    rows = inputPuzzle.split("\n")
    passphrases = list(map(lambda row: row.split(" "), rows))
    valid = 0
    for passphrase in passphrases:
        dictionary = set()
        for word in passphrase:
            if word in dictionary:
                break
            dictionary.add(word)
        if len(dictionary) == len(passphrase):
            valid += 1
    print("star 1: %s" % valid)

    withoutAnagram = filter(lambda passphrase: passphraseHasAnagram(passphrase), passphrases)
    valid = sum(map(lambda passphrase: 1, withoutAnagram))
    print("star 2: %s" % valid)
