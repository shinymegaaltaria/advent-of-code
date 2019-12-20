input = open("day14_in.txt").read()
recipe = input.split("\n")
with open('test_parsed.txt', 'w') as f:
    print(len(recipe),file=f)
for line in recipe:
    by_comp = line.split(" ")
    #print(by_comp)
    cnt = 0
    result = []
    for item in by_comp:
        if item == '=>':
            cnt -= 1
        else:
            if not item.isdigit():
                cnt += 1
                if item[-1] == ',':
                    result.append(item[:-1])
                else:
                    result.append(item)
            else:
                result.append(item)
    with open('test_parsed.txt', 'a') as f:
        print(cnt,file=f)
        print(' '.join(result),file=f)