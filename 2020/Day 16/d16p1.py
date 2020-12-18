input = open("d16_p1_in.txt").read()
input = input.split('\n')

all_fields = []
ans = 0
for i in range(len(input)):
    if i < 20:
        cur_field = input[i].split(' ')
        empty_field = []
        for num in cur_field:
            empty_field.append(int(num))
        all_fields.append(empty_field)
    else:
        cur_ticket = input[i].split(' ')
        for num in cur_ticket:
            ok = False
            for j in range(20):
                if (all_fields[j][0] <= int(num) and int(num) <= all_fields[j][1]) or (all_fields[j][2] <= int(num) and int(num) <= all_fields[j][3]):
                    ok = True
            if ok == False:
                print(num)
                ans += int(num)
print(ans)