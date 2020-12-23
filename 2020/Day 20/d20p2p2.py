from PIL import Image
import numpy as np

input = open('d20_in.txt').read()
tiles = input.split('\n\n')

w, h = 2400, 2400
data = np.zeros((h, w, 3), dtype=np.uint8)
data[0:h,0:w] = [255,255,255]
img = Image.fromarray(data, 'RGB')
img.save('base.png')

'''
for tile in tiles:
    explode = tile.split('\n')
    tile_num = explode[0]

    w, h = 100, 100
    data = np.zeros((h, w, 3), dtype=np.uint8)
    
    for i in range(10):
        for j in range(10):
            if explode[i + 1][j] == '.':
                data[i*10:(i+1)*10,j*10:(j+1)*10] = [255,255,255]
    
    img = Image.fromarray(data, 'RGB')
    img.save('{}.png'.format(tile_num))
'''