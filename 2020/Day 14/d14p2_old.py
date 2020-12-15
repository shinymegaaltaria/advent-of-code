input = open("d14_in.txt").read()
lines = input.split('\n')

mem = {}
cur_mask = ''

def count_diff(a:str, b:str):
    output = 0
    out_list = []
    for i in range(len(a)):
        if not a[i] == b[i]:
            if a[i] == 'X':
                out_list.append(b[i])
            elif b[i] == 'X':
                out_list.append(a[i])
            else:
                return (0,'')
        else:
            if a[i] == 'X' and b[i] == 'X':
                output += 1
            out_list.append(a[i])
    if ''.join(out_list) == a:
        return (0,a)
    elif ''.join(out_list) == b:
        return (0,b)
    return (2 ** output , ''.join(out_list))

for line in lines:
    arg = line.split(' ')
    if arg[0] == 'mask':
        cur_mask = arg[1]
    elif arg[0] == 'mem':
        location = int(arg[1])
        to_write = int(arg[2])
        
        location_bin = "{0:b}".format(location)
        while len(location_bin) < len(cur_mask):
            location_bin = '0' + location_bin
        
        actual_location = []
        for i in range(len(cur_mask)):
            if cur_mask[i] == 'X':
                actual_location.append('X')
            elif cur_mask[i] == '1':
                actual_location.append('1')
            else:
                actual_location.append(location_bin[i])
        actual_location = ''.join(actual_location)

        #print(actual_location)
        running_minus = 0
        update = {}
        for key in mem:
            (cur,new_key) = count_diff(key, actual_location)
            (cnt,value) = mem[key]
            mem[key] = (cnt - cur, value)
            update[new_key] = (cur, to_write)
            running_minus += cur
        
        #print(mem)

        for key in update:
            mem[key] = update[key]

        #print(mem)
        mem[actual_location] = (2 ** actual_location.count('X') - running_minus, to_write)



ans = 0
for key in mem:
    if not key == '':
        (cnt, value) = mem[key]
        #print(key,cnt,value)
        ans += cnt * value

print(ans)