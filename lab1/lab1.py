def changeFile(path):
    with open(path, 'a+') as file:
        print("Enter the text:\n")
        while True:
            line = input()
            k = 0
            for i in line:
                k += 1
                if ord(i) > 31 or ord(i) == 10:
                    file.write(i)
                elif k == 1:
                    return
                else:
                    file.write('\n')
                    return
            file.write('\n')


def showFile(path):
    openedFile = True
    try:
        inFile = open(path, 'a+')
    except IOError:
        print("Can't open this file...\n")
        openedFile = False
    inFile.seek(0, 2)
    if inFile.tell() == 0:
        print("File is empty.\n")
    else:
        print("File contain:\n")
        inFile.seek(0);
        for line in inFile:
            print(line.rstrip())
    inFile.close()
    return openedFile


def findWord(inPath, outPath):
    inPath = open(inPath, 'r')
    while True:
        line = inPath.readline()
        if not line:
            break
        maxWord = word = sentence = ""
        maxLen = lenWord = 0
        for i in line:
            sentence += i
            if i.isupper() or i.islower() or i.isalpha():
                lenWord += 1
                word += i
            else:
                if lenWord > maxLen:
                    maxLen = lenWord
                    maxWord = word
                if i == '.':
                    outChangedFile(maxWord, sentence, outPath)
                    sentence = ""
                    maxLen = 0
                    maxWord = ""
                lenWord = 0
                word = ""


def outChangedFile(word, line, path):
    with open(path, 'a+') as outPath:
        if line[0] == ' ':
            line = line.replace(' ', '', 1)
        outPath.write(f"{len(word)} {word} | {line}\n")


def main():
    inPath = input("Enter file 1 path: ")
    abilityOpen = showFile(inPath)
    agree = input("Do you want change the file(y/n)? ")
    if abilityOpen:
        if agree == 'y':
            changeFile(inPath)
        elif agree != 'n':
            print("It's not 'y' or 'n'")
    outPath = input("Enter file 2 path: ")
    abilityOpen = showFile(outPath)
    if abilityOpen:
        findWord(inPath, outPath)
        print("File changed.\n")
        showFile(outPath)


main()
