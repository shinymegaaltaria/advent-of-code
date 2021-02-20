input = open('d18p2_in.txt').read().split('\n')

grids = [[],[],[],[]]

for i in range(81):
    if i <= 40:
        grids[0].append(input[i][:41])
        grids[1].append(input[i][40:])
    if i >= 40:
        grids[2].append(input[i][:41])
        grids[3].append(input[i][40:])

for i in range(4):
    print('\n'.join(grids[i]))
    print('\n\n\n')
