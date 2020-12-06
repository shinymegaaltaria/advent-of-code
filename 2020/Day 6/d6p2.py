input = open("d6_in.txt").read()
input = input.split('\n\n')

ans = 0
for group in input:
    r_cnt = 0
    group = group.split('\n')
    for a in 'abcdefghijklmnopqrstuvwxyz':
        ok = True
        for person in group:
            if not a in person:
                ok = False
        if ok:
            r_cnt += 1
    ans += r_cnt

print(ans)