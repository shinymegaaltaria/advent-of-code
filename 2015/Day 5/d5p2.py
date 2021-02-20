input = open('d5_in.txt').read().split('\n')
cnt = 0

for string in input:
    check1 = False
    check2 = False
    
    #check whether string is nice
    alpha = 'abcdefghijklmnopqrstuvwxyz'
    for letter1 in alpha:
        for letter2 in alpha:
            checkstr1 = letter1 + letter2
            checkstr2 = letter1 + letter2 + letter1
            if string.count(checkstr1) >= 2:
                check1 = True
            if string.count(checkstr2) >= 1:
                check2 = True

    if check1 and check2:
        cnt += 1

print(cnt)