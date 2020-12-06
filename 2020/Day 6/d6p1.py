input = open("d6_in.txt").read()
input = input.split('\n\n')

ans = 0
for group in input:
    r_cnt = 0
    check=''.join(group)
    for a in 'abcdefghijklmnopqrstuvwxyz':
        if a in check:
            r_cnt += 1
    ans += r_cnt

print(ans)