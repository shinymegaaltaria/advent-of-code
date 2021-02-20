input = open('d5_in.txt').read().split('\n')
cnt = 0

for string in input:
    check1 = False
    check2 = False
    check3 = True
    if string.count('a') + string.count('e') + string.count('i') + string.count('o') + string.count('u') >= 3:
        check1 = True
    
    alpha = 'abcdefghijklmnopqrstuvwxyz'
    for letter in alpha:
        if letter*2 in string:
            check2 = True

    ban_list = ['ab', 'cd', 'pq', 'xy']
    for ban in ban_list:
        if ban in string:
            check3 = False

    if check1 and check2 and check3:
        cnt += 1

print(cnt)