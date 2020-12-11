input = open("d10_in.txt").read()
input = input.split('\n')
num = []
for line in input:
    num.append(int(line))

num.append(0)
num.append(max(num) + 3)
num = sorted(num)

cnt1 = 0
cnt3 = 0

for i in range(len(num) - 1):
    if num[i+1] - num[i] == 1:
        cnt1 += 1
    elif num[i+1] - num[i] == 3:
        cnt3 += 1

print(cnt1 * cnt3)