input = open("d14_in.txt").read()
lines = input.split('\n')

memory = {}
cur_mask = ''

def brute_force(a:str):
    out_list = []
    cnt = a.count('X')
    for i in range(2 ** cnt):
        i_bin = str(bin(i))[2:]
        while len(i_bin) < cnt:
            i_bin = '0' + i_bin
        cur_pt = 0
        cur_address = []
        for j in range(36):
            if a[j] == 'X':
                cur_address.append(i_bin[cur_pt])
                cur_pt += 1
            else:
                cur_address.append(a[j])
        out_list.append(''.join(cur_address))
    return out_list

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

        possible_addresses = brute_force(result_address)

        for possible_address in possible_addresses:
            memory[possible_address] = value


ans = 0        
for key in memory:
    ans += memory[key]

print(ans)