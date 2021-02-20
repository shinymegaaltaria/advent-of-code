def d25():
    a = 9717666
    b = 20089533

    cur_pow = 1

    for i in range(1,20201227):
        cur_pow *= 7
        while cur_pow > 20201227:
            cur_pow -= 20201227
        if cur_pow == a:
            pow_a = i
        if cur_pow == b:
            pow_b = i

    ans_pow = pow_a * pow_b
    while ans_pow > 20201226:
        ans_pow -= 20201226
    
    cur_pow = 1
    for i in range(1,20201227):
        cur_pow *= 7
        while cur_pow > 20201227:
            cur_pow -= 20201227
        if i == ans_pow:
            print(cur_pow)
            return cur_pow

d25()