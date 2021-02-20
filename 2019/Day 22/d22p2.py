input = open('day22_in.txt').read().split('\n')
n = 119315717514047
m = 1
c = 0

def normalize(a):
    while a < 0:
        a += n
    
    if a > n:
        a %= n
    
    return a

for cmd in input:
    cmd = cmd.split(' ')
    if cmd[0] == 'ds':
        m *= -1
        c *= -1
        c -= 1
    
    elif cmd[0] == 'cut':
        c += (n - int(cmd[1]))
    else:
        m *= int(cmd[1])
        c *= int(cmd[1])
    
    m = normalize(m)
    c = normalize(c)

real_m = pow(m,101741582076661,n)
real_c = (((real_m - 1) * pow(m - 1, n - 2 ,n)) * c) % n

calc = normalize(2020 - real_c)
print((pow(real_m, n - 2,n) * calc)%n)