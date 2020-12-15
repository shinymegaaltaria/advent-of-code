input = open("d14_in.txt").read()
lines = input.split('\n')

mem = {}
cur_mask = ''

for line in lines:
    arg = line.split(' ')
    if arg[0] == 'mask':
        cur_mask = arg[1]
    elif arg[0] == 'mem':
        location = int(arg[1])
        to_write = int(arg[2])
        to_write_bin = "{0:b}".format(to_write)
        while len(to_write_bin) < len(cur_mask):
            to_write_bin = '0' + to_write_bin
        actual_write = []
        for i in range(len(cur_mask)):
            if cur_mask[i] == 'X':
                actual_write.append(to_write_bin[i])
            else:
                actual_write.append(cur_mask[i])
        mem[location] = int(''.join(actual_write),2)

ans = 0
for key in mem:
    ans += mem[key]

print(ans)