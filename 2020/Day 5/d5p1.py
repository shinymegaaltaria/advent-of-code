input = open("d5_modded.txt").read()
input = input.split()

best = -1
for num in input:
    if int(num,2) > best:
        best = int(num,2)

print(best)