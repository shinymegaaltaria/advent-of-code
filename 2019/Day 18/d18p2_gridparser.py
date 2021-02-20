input = open('tmp_outpuut.txt').read().split('\n\n')

for i in range(4):
    alpha = 'abcdefghijklmnopqrstuvwxyz'
    score = 0
    for j in range(26):
        if alpha[j] in input[i]:
            score += pow(2,j)
    print(score)

# Output
# 33560584
# 6881284
# 8833010
# 17833985
