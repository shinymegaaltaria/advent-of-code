input = open("d10_challenge.txt").read()
input = input.split('\n')
num = []
dp = {}
for line in input:
    num.append(int(line))

num.append(0)
num.append(max(num) + 3)

num = sorted(num)

num_s = len(num)

bt_dp = [0] * num_s

for i in range(num_s):
    if i == 0:
        bt_dp[i] = 1
    if (i + 1) < num_s and (num[i + 1] - num[i]) <= 3:
        bt_dp[i + 1] += bt_dp[i]
    if (i + 2) < num_s and (num[i + 2] - num[i]) <= 3:
        bt_dp[i + 2] += bt_dp[i]
    if (i + 3) < num_s and (num[i + 3] - num[i]) <= 3:
        bt_dp[i + 3] += bt_dp[i]

#print(ctw(max(num)))

print(bt_dp[num_s - 1])