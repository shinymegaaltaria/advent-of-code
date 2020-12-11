input = open("d10_in.txt").read()
input = input.split('\n')
num = []
dp = {}
for line in input:
    num.append(int(line))

num.append(0)
num.append(max(num) + 3)

def ctw(x:int):
    if x == 0:
        dp[0] = 1
        return dp[x]
    if x in dp:
        return dp[x]
    if not x in num:
        dp[x] = 0
        return dp[x]
    dp[x] = ctw(x - 1) + ctw(x - 2) + ctw(x - 3)
    return dp[x]

def ictw(x):
    if x == 0:
        return 1
    if not x in num:
        return 0
    return ictw(x - 1) + ictw(x - 2) + ictw(x - 3)

bt_dp = [0] * (max(num) + 1)

for i in range(max(num) + 1):
    if i == 0:
        bt_dp[i] = 1
    if i + 1 in num:
        bt_dp[i + 1] += bt_dp[i]
    if i + 2 in num:
        bt_dp[i + 2] += bt_dp[i]
    if i + 3 in num:
        bt_dp[i + 3] += bt_dp[i]

print(ctw(max(num)))

print(bt_dp[max(num)])