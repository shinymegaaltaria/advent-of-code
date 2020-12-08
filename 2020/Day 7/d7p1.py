input = open("d7_in.txt").read()
instructions = input.split('\n')

trees = {}
bags = []
for line in instructions:
    line = line.split('->')
    line[0] = ''.join(line[0].split(' '))
    line[1] = line[1].split(', ')
    tmp = ''
    for bag in line[1]:
        explode = bag.split(' ')
        tmp += explode[0]
        tmp += ' '
        for i in range(1,len(explode)):
            tmp += explode[i]
        tmp += ' '
    print(len(line[1]), line[0],tmp)
