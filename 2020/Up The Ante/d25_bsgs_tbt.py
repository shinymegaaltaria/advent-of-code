import math
def solve(g, h, p):
    m = int(math.ceil(math.sqrt(p)))
    cur_pow = 1
    bb_step = {}
    for i in range(m):
        bb_step[cur_pow] = i
        cur_pow *= g
        cur_pow %= p
    
    c = pow(g , p - m - 1, p)
    y = h

    for i in range(m):
        if y in bb_step:
            return i * m + bb_step[y]
        else:
            y *= c
            y %= p

pow_a = solve(7,9717666,20201227)
pow_b = solve(7,20089533,20201227)
print(pow(7,pow_a*pow_b,20201227))