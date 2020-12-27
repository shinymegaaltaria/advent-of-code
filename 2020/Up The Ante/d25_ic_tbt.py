def d25():
    a = int(input())
    b = int(input())

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
    while cur_pow > 20201226:
        cur_pow -= 20201226
        
    cur_pow = 1
    for i in range(1,20201227):
        cur_pow *= 7
        while cur_pow > 20201227:
            cur_pow -= 20201227
        if i == ans_pow:
            print(cur_pow)
            return
