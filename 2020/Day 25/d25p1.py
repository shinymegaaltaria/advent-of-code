input = open("d25_in.txt").read()
input = input.split('\n')

for i in range(1,20201226):
    if i % 10000 == 0:
        print(i)
    cur_pow = pow(7,i,20201227)
    if cur_pow == int(input[0]):
        pow1 = i
    if cur_pow == int(input[1]):
        pow2 = i

new_pow = pow(7,pow1*pow2,20201227)
print("ans:",new_pow)