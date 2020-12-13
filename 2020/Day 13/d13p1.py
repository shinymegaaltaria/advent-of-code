input = open("d13_in.txt").read()
input = input.split('\n')
start_time = int(input[0])
buses = input[1].split(',')
actual_bus = []
for bus in buses:
    if bus.isdigit():
        actual_bus.append(int(bus))

cur_time = start_time

def p1():
    global cur_time
    while True:
        cur_time += 1
        for num in actual_bus:
            if cur_time % num == 0:
                return num * (cur_time - start_time)
print(p1())