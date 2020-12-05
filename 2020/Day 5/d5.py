input = open("d5_in.txt").read().split('\n')
best = -1
all_num = [i for i in range(1024)]
for seat in input:
    num = int(seat.replace('R','1').replace('L','0').replace('F','0').replace('B','1'),2)
    all_num.remove(num)
    if num > best:
        best = num
print('Part 1:',best)
print('Part 2:',all_num)