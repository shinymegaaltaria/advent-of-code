input = open("d20p2_full_image.txt").read()
input = input.split('\n\n')

for image in input:
    image = image.split('\n')
    seamonster_land = []
    output = []
    cur_ans = 0
    cnt = -1
    for i in range(120):
        if not i % 10 == 0 and not i % 10 == 9:
            cnt += 1
            seamonster_land.append([])
            output.append([])
            for j in range(120):
                if not j % 10 == 0 and not j % 10 == 9:
                    output[cnt].append(image[i][j])
                    if image[i][j] == '0':
                        seamonster_land[cnt].append(False)
                    else:
                        seamonster_land[cnt].append(True)
                        cur_ans += 1
    for i in range(93):
        for j in range(76):
            if seamonster_land[i + 1][j] and seamonster_land[i + 2][j + 1] and seamonster_land[i + 2][j + 4] and seamonster_land[i + 1][j + 5] and seamonster_land[i + 1][j + 6] and seamonster_land[i + 2][j + 7] and seamonster_land[i + 2][j + 10] and seamonster_land[i + 1][j + 11] and seamonster_land[i + 1][j + 12] and seamonster_land[i + 2][j + 13] and seamonster_land[i + 2][j + 16] and seamonster_land[i + 1][j + 17] and seamonster_land[i + 1][j + 18] and seamonster_land[i][j + 18] and seamonster_land[i + 1][j + 19]:
                cur_ans -= 15

    print(cur_ans)