target = []
target.append(int(input()))
target.append(int(input()))

def d25():
    ok1 = False
    ok2 = False
    cur_pow = 1
    for i in range(1,20201226):
        
        '''
        if i % 10000 == 0:
            print(i)
        '''

        cur_pow *= 7
        cur_pow %= 20201227
        if cur_pow == target[0]:
            pow1 = i
            ok1 = True
        if cur_pow == target[1]:
            pow2 = i
            ok2 = True
        if ok1 and ok2:
            new_pow = pow(7,pow1*pow2,20201227)
            print("base: 7, pow1: {}, pow2: {}".format(pow1,pow2))
            print("ans:",new_pow)
            return

d25()