input = open("d14_in.txt").read()
lines = input.split('\n')

memory = {}
cur_mask = ''

def key_union(a:str,b:str):
    out_list = []
    for i in range(36):
        if a[i] == b[i]:
            out_list.append(a[i])
        else:
            if a[i] == 'X':
                out_list.append(b[i])
            elif b[i] == 'X':
                out_list.append(a[i])
            else:
                return 'no union'
    return ''.join(out_list)

tmp = 0
for line in lines:
    tmp = max(line.count('X'),tmp)

print(tmp)

for line in lines:
    commands = line.split(' ')

    if commands[0] == 'mask':
        cur_mask = commands[1]
    
    elif commands[0] == 'mem':
        address = int(commands[1])
        address_bin = "{0:{fill}36b}".format(address, fill='0')
        
        result_address = []
        for i in range(36):
            if cur_mask[i] == '0':
                result_address.append(address_bin[i])
            elif cur_mask[i] == '1':
                result_address.append('1')
            elif cur_mask[i] == 'X':
                result_address.append('X')
        result_address = ''.join(result_address)

        #print(result_address)

        value = int(commands[2])

        running_cnt = 0
        update = {}
        for key in memory:
            common_key = key_union(key, result_address)
            amt = common_key.count('X')
            if not common_key == 'no union':
                if not common_key in memory:
                    (mem_cnt, mem_val) = memory[key]
                    memory[key] = (mem_cnt - 2 ** amt, mem_val)
                    update[common_key] = (2 ** amt, value)
                    running_cnt += 2 ** amt
                else:
                    running_cnt += 2 ** amt
        
        for key in update:
            memory[key] = update[key]
        
        memory[result_address] = ( (2 ** result_address.count('X')) - running_cnt, value)
        

        #print(running_cnt)
        #print(memory)

ans = 0        
for key in memory:
    (cnt,val) = memory[key]
    print(key,cnt,val)
    ans += cnt * val

print(ans)