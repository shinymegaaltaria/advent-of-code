input = open("d16_p2_in.txt").read()
input = input.split('\n')

all_fields = []
ans = 0
ticket_fields = []
for i in range(len(input)):
    if i < 20:
        cur_field = input[i].split(' ')
        empty_field = []
        for num in cur_field:
            empty_field.append(int(num))
        all_fields.append(empty_field)
        ticket_fields.append([])
    else:
        cur_ticket = input[i].split(' ')
        for j in range(20):
            ticket_fields[j].append(int(cur_ticket[j]))

valid = []
output = []

for i in range(20):
    valid.append([])
    for j in range(20):
        big_ok = True
        for k in ticket_fields[j]:
            if (all_fields[i][0] <= k and k <= all_fields[i][1]) or (all_fields[i][2] <= k and k <= all_fields[i][3]):
                ok = True
            else:
                big_ok = False
        if big_ok:
            valid[i].append('1')
        else:
            valid[i].append('0')
    valid[i] = ' '.join(valid[i])

for row in valid:
    print(row)
