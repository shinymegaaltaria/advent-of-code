from PIL import Image
import numpy as np

input = open('visp1.txt').read().split('\n\n')

for i in range(len(input)):
    seats = input[i].split('\n')

    w, h = 92, 99
    data = np.zeros((h, w, 3), dtype=np.uint8)

    for j in range(99):
        for k in range(92):
            if seats[j][k] == 'L':
                data[j,k] = [0,255,0]
            elif seats[j][k] == '#':
                data[j,k] = [255,0,0]
            else:
                data[j,k] = [128,128,128]
    
    img = Image.fromarray(data, 'RGB')
    img.save('vis_p1_img/visp1_frame_{0:02d}.png'.format(i))

    print('vis_p1_img/visp1_frame_{0:02d}.png CREATED'.format(i))

print('\n\n\nVISUALIZATION OF P1 DONE\n\n\n')


input = open('visp2.txt').read().split('\n\n')

for i in range(len(input)):
    seats = input[i].split('\n')

    w, h = 92, 99
    data = np.zeros((h, w, 3), dtype=np.uint8)

    for j in range(99):
        for k in range(92):
            if seats[j][k] == 'L':
                data[j,k] = [0,255,0]
            elif seats[j][k] == '#':
                data[j,k] = [255,0,0]
            else:
                data[j,k] = [128,128,128]
    
    img = Image.fromarray(data, 'RGB')
    img.save('vis_p2_img/visp2_frame_{0:02d}.png'.format(i))

    print('vis_p2_img/visp2_frame_{0:02d}.png CREATED'.format(i))