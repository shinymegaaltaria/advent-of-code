input = open("test.txt").read()
recipe = input.split("\n")
print(len(recipe))
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
        
    print(cnt)
    print(' '.join(result))