input = open("d13_in.txt").read()
input = input.split('\n')
start_time = int(input[0])
buses = input[1].split(',')
actual_bus = []
for bus in buses:
    if bus.isdigit():
        actual_bus.append(bus)
    else:
        actual_bus.append('1')

print(' '.join(actual_bus))