input = open("d15_in.txt").read()
input = input.split(',')

list_of_num = []
for num in input:
    list_of_num.append(int(num))

last_spoken = -1
last_done = {}

for i in range(1,30000001):
    #print(i,last_spoken)
    '''
    if i % 100000 == 0:
        print(i)
    '''
    if i <= len(list_of_num):
        last_done[list_of_num[i - 1]] = [i]
        last_spoken = list_of_num[i - 1]
    else:
        if len(last_done[last_spoken]) == 1:
            last_done[0].append(i)
            last_spoken = 0
        else:
            newly_call = last_done[last_spoken][-1] - last_done[last_spoken][-2]
            if newly_call in last_done:
                last_done[newly_call].append(i)
            else:
                last_done[newly_call] = [i]
            last_spoken = newly_call
    
print(last_spoken)