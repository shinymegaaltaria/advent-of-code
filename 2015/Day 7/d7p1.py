input = open('d7_in.txt').read().split('\n')

values = {}

for line in input:
    line = line.split(' -> ')
    #frick
    line[0] = line[0].split(' ')
    if len(line[0]) == 1:
        values[line[1]] = 
    elif len(line[0]) == 2:
        if line[0][0] == 'NOT':
            values[line[1]] = 65535 - int(line[0][1])
    else:
        if line[0][1] == 'NOT':
            values[line[1]] = 65535 - int(line[0][1])