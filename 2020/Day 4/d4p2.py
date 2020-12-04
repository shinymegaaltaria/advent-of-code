input = open("d4p1_processed.txt").read()
input = input.split('\n')

cnt = 0
for row in input:
    fields = row.split(' ')
    valid = True
    print(fields)
    for field in fields:
        explode = field.split(':')
        ok = True
        if explode[0] == 'byr':
            cur_year = int(explode[1])
            if 1920 <= cur_year and cur_year <= 2002:
                ok = True
            else:
                valid = False
                print('byr flag',explode)
        elif explode[0] == 'iyr':
            cur_year = int(explode[1])
            if 2010 <= cur_year and cur_year <= 2020:
                ok = True
            else:
                valid = False
                print('iyr flag',explode)
        elif explode[0] == 'eyr':
            cur_year = int(explode[1])
            if 2020 <= cur_year and cur_year <= 2030:
                ok = True
            else:
                valid = False
                print('eyr flag',explode)
        elif explode[0] == 'hgt':
            if 'in' in explode[1]:
                num = int(explode[1].replace('in',''))
                if 59 <= num and num <= 76:
                    ok = True
                else:
                    valid = False
                    print('hgt flag',explode)
            elif 'cm' in explode[1]:
                num = int(explode[1].replace('cm',''))
                if 150 <= num and num <= 193:
                    ok = True
                else:
                    valid = False
                    print('hgt flag',explode)
            else:
                valid = False
                print('hgt no unit flag',explode)
        elif explode[0] == 'hcl':
            if explode[1][0] == '#':
                explode[1] = explode[1].replace('#','')
                if len(explode[1]) == 6:
                    for character in explode[1]:
                        if character in ['a','b','c','d','e','f'] or character.isdigit():
                            ok = True
                        else:
                            valid = False
                            print('hcl alphanum flag',explode)
                else:
                    valid = False
                    print('hcl length flag',explode)
            else:
                valid = False
                print('hcl hash flag',explode)
        elif explode[0] == 'ecl':
            if explode[1] in ['amb','blu','brn','gry','grn','hzl','oth']:
                ok = True
            else:
                valid = False
                print('ecl flag',explode)
        elif explode[0] == 'pid':
            if explode[1].isdigit() and len(explode[1]) == 9:
                ok = True
            else:
                valid = False
                print('pid flag',explode)
    
    if valid:
        cnt = cnt + 1

    print('\n\n\n')

print(cnt)