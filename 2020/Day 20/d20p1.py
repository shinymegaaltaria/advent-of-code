input = open("d20_in.txt").read()
tiles = input.split('\n\n')

edges = {}

for tile in tiles:
    explode = tile.split('\n')
    tile_no = int(explode[0])
    top = []
    down = []
    left = []
    right = []
    for i in range(10):
        top.append(explode[1][i])
        down.append(explode[10][i])
        left.append(explode[i + 1][0])
        right.append(explode[i + 1][9])
    
    top = ''.join(top)
    down = ''.join(down)
    left = ''.join(left)
    right = ''.join(right)
    
    if top in edges:
        edges[top].append((tile_no,0,False))
    else:
        edges[top] = [(tile_no,0,False)]
    
    if down in edges:
        edges[down].append((tile_no,1,False))
    else:
        edges[down] = [(tile_no,1,False)]

    if left in edges:
        edges[left].append((tile_no,2,False))
    else:
        edges[left] = [(tile_no,2,False)]

    if right in edges:
        edges[right].append((tile_no,3,False))
    else:
        edges[right] = [(tile_no,3,False)]
    
    top = top[::-1]
    down = down[::-1]
    left = left[::-1]
    right = right[::-1]

    if top in edges:
        edges[top].append((tile_no,0,True))
    else:
        edges[top] = [(tile_no,0,True)]
    
    if down in edges:
        edges[down].append((tile_no,1,True))
    else:
        edges[down] = [(tile_no,1,True)]

    if left in edges:
        edges[left].append((tile_no,2,True))
    else:
        edges[left] = [(tile_no,2,True)]

    if right in edges:
        edges[right].append((tile_no,3,True))
    else:
        edges[right] = [(tile_no,3,True)]

tile_data = {}

for key in edges:
    if len(edges[key]) == 1:
        print(edges[key])
        (id,edge,reversed) = edges[key][0]
        if id in tile_data:
            tile_data[id].append((edge,reversed))
        else:
            tile_data[id] = [(edge,reversed)]

ans = 1

for id in tile_data:
    checker = [False,False,False,False]
    for edge_status in tile_data[id]:
        (edge,reversed) = edge_status
        checker[edge] = True
    cnt = 0
    for edge_status in checker:
        if edge_status:
            cnt += 1
    if cnt == 2:
        ans *= id

print(ans)