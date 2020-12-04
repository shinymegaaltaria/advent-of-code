input = open("d4_in.txt").read()
input = input.split('\n')

cnt = 0
cur_str = []
for row in input:
    if row == '':
        check = ' '.join(cur_str)
        valid = True
        if 'byr:' in check and 'iyr:' in check and 'eyr:' in check and 'hgt:' in check and 'hcl' in check and 'ecl' in check and 'pid' in check:
            cnt = cnt + 1
            print(check)
        cur_str = []
    else:
        cur_str.append(row)

check = ' '.join(cur_str)

if 'byr:' in check and 'iyr:' in check and 'eyr:' in check and 'hgt:' in check and 'hcl' in check and 'ecl' in check and 'pid' in check:
    cnt = cnt + 1
    print(check)


print(cnt)