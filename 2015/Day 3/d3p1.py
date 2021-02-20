input = open('d3_in.txt').read().split(';')

visited = []

x,y = 0,0
ans = 0

for instr in input:
    tmp1,tmp2 = [int(tmp) for tmp in instr.split(',')]
    x += tmp1
    y += tmp2
    if not (x,y) in visited:
        visited.append((x,y))
        ans += 1

print(ans)