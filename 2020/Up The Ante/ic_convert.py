#hardcode to do mod 20201227
bin_20201227 = [338920348844032, 169460174422016, 84730087211008, 42365043605504, 21182521802752, 10591260901376, 5295630450688, 2647815225344, 1323907612672, 661953806336, 330976903168, 165488451584, 82744225792, 41372112896, 20686056448, 10343028224, 5171514112, 2585757056, 1292878528, 646439264, 323219632, 161609816, 80804908, 40402454, 20201227]

#baby step precomputation
cur_pow = 7
bb_step = {}
for i in range(1,4495):
    bb_step[cur_pow] = i
    cur_pow *= 7

    #mod 20201227
    for j in range(22,25):
        if not cur_pow < bin_20201227[j]:
            cur_pow -= bin_20201227[j]

#inputs
a = 9717666
b = 20089533
nfa = True #not found a
nfb = True #not found b

#giant steps
for i in range(4495):
    
    if nfa:
        if a == 1:
            pow_a = i * 4495
            nfa = False
        else:
            if a in bb_step:
                pow_a = i * 4495 + bb_step[a]
                nfa = False
            else:

                #680915 is 7^(-4495) mod 20201227
                a *= 680915

                #mod 20201227
                for j in range(5,25):
                    if not a < bin_20201227[j]:
                        a -= bin_20201227[j]

    if nfb:
        if b == 1:
            pow_b = i * 4495
            nfb = False
        else:
            if b in bb_step:
                pow_b = i * 4495 + bb_step[b]
                nfb = False
            else:

                #680915 is 7^(-4495) mod 20201227
                b *= 680915

                #mod 20201227
                for j in range(5,25):
                    if not b < bin_20201227[j]:
                        b -= bin_20201227[j]
    
    if not a and not b:
        break

#finding required exponent
ans_pow = pow_a * pow_b

#hardcode to do mod 20201226
bin_20201226 = [338920332066816, 169460166033408, 84730083016704, 42365041508352, 21182520754176, 10591260377088, 5295630188544, 2647815094272, 1323907547136, 661953773568, 330976886784, 165488443392, 82744221696, 41372110848, 20686055424, 10343027712, 5171513856, 2585756928, 1292878464, 646439232, 323219616, 161609808, 80804904, 40402452, 20201226]

for i in range(25):
    if not ans_pow < bin_20201226[i]:
        ans_pow -= bin_20201226[i]

#hardcode to do modular exponentiation
pow_7 = [13519586, 17275020, 18094939, 6287223, 862904, 13272234, 12086278, 1972288, 16306912, 5065873, 12394425, 7396781, 15930079, 1422779, 6495296, 10650039, 14526858, 13668463, 16669039, 17588834, 13239263, 5764801, 2401, 49, 7]
pow_2 = [16777216, 8388608, 4194304, 2097152, 1048576, 524288, 262144, 131072, 65536, 32768, 16384, 8192, 4096, 2048, 1024, 512, 256, 128, 64, 32, 16, 8, 4, 2, 1]

ans = 1

#modular exponentiation
for i in range(25):
    if not ans_pow < pow_2[i]:
        ans *= pow_7[i]
        ans_pow -= pow_2[i]
        for j in range(25):
            if not ans < bin_20201227[j]:
                ans -= bin_20201227[j]

print(ans_pow)
print(ans)