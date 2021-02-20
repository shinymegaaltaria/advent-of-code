input = open('d3_in.txt').read().split(';')

visited = []

x1,y1 = 0,0
x2,y2 = 0,0
ans = 0
cnt = 0

for i in range(len(input)):
    tmp1,tmp2 = [int(tmp) for tmp in input[i].split(',')]
    if i % 2 == 0:
        x1 += tmp1
        y1 += tmp2
        if not (x1,y1) in visited:
            visited.append((x1,y1))
            ans += 1
    else:
        x2 += tmp1
        y2 += tmp2
        if not (x2,y2) in visited:
            visited.append((x2,y2))
            ans += 1

print(ans)