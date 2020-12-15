input = open("d15_in.txt").read()
input = input.split(',')

list_of_num = []
for num in input:
    list_of_num.append(int(num))

last_spoken = -1
last_done = {}

called_num = []
for i in range(1,2021):
    #print(i,last_spoken)
    if i <= len(list_of_num):
        called_num.append(list_of_num[i - 1])
        last_done[list_of_num[i - 1]] = [i]
        last_spoken = called_num[-1]
    else:
        if len(last_done[last_spoken]) == 1:
            called_num.append(0)
            last_done[0].append(i)
            last_spoken = 0
        else:
            newly_call = last_done[last_spoken][-1] - last_done[last_spoken][-2]
            called_num.append(newly_call)
            if newly_call in last_done:
                last_done[newly_call].append(i)
            else:
                last_done[newly_call] = [i]
            last_spoken = newly_call
    

print(called_num[-1])