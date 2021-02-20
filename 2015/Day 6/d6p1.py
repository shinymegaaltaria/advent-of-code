input = open('d6_in.txt').read().split('\n')

light_grid = []
for i in range(1000):
    light_grid.append([])
    for j in range(1000):
        light_grid[i].append(0)

for line in input:
    line = line.split(' ')
    if int(line[0]) == -1:
        for i in range(int(line[1]),int(line[3])+1):
            for j in range(int(line[2]),int(line[4])+1):
                light_grid[i][j] = 1 - light_grid[i][j]
    else:
        for i in range(int(line[1]),int(line[3])+1):
            for j in range(int(line[2]),int(line[4])+1):
                light_grid[i][j] = int(line[0])

cnt = 0

for i in range(1000):
    for j in range(1000):
        cnt += light_grid[i][j]

print(cnt)