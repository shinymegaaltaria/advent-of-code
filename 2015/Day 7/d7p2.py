instrs = open('d7_p2_in.txt').read().split('\n')

values = {}

lol = "abcdefghijklmnopqrstuvwxyz"

def find_val(tmp):
    if tmp.isnumeric():
        return int(tmp)
    else:
        if tmp in values:
            return values[tmp]
        else:
            return 2147483647

while len(instrs) > 0:
    print(len(instrs))
    redo_instrs = []
    for instr in instrs:
        #print(instr)
        line = instr.split(' -> ')
        #frick
        line[0] = line[0].split(' ')
        
        if len(line[0]) == 1:
            l00 = find_val(line[0][0])
            if l00 == 2147483647:
                redo_instrs.append(instr)
                #print('redo')
            else:
                values[line[1]] = l00
        elif len(line[0]) == 2:
            if line[0][0] == 'NOT':
                l01 = find_val(line[0][1])
                if l01 == 2147483647:
                    redo_instrs.append(instr)
                    #print('redo')
                else:
                    values[line[1]] = 65535 - l01
        else:
            l00 = find_val(line[0][0])
            l02 = find_val(line[0][2])
            if l00 == 2147483647 or l02 == 2147483647:
                redo_instrs.append(instr)
                #print('redo')
            else:
                if line[0][1] == 'AND':
                    values[line[1]] = l00 & l02
                elif line[0][1] == 'OR':
                    values[line[1]] = l00 | l02
                elif line[0][1] == 'RSHIFT':
                    values[line[1]] = l00 // pow(2,l02)
                else:
                    values[line[1]] = l00 * pow(2,l02) % 65536
    instrs = redo_instrs.copy()
    #print('\n'.join(instrs),file=open("d7p1_debug.txt",'w'))
    #print(values)
    #input('Press for next run')

for val in values:
    print(val,values[val])