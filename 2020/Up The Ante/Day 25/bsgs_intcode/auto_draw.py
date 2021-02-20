from PIL import Image, ImageDraw, ImageFont

input = open('img_input_run2.txt').read()

def get_tile_id(mem_id):
    if mem_id < 840:
        return mem_id
    elif mem_id >= 5000:
        return 900
    else:
        return mem_id-4000 + 840

def mem_cell_create(id,num):
    # get an image
    base = Image.open('trans_64x64.png').convert('RGBA')

    width, height = base.size
    
    # make a blank image for the text, initialized to transparent text color
    txt = Image.new('RGBA', base.size, (255,255,255,0))

    # get a drawing context
    d = ImageDraw.Draw(txt)

    if len(num) > 8:
        half_len = len(num)//2
        num = num[:half_len] + '\n' + num[half_len:]

    textwidth, textheight = d.textsize(num)

    margin = 10
    x = (width - textwidth) / 2 
    y = (height - textheight) / 2

    d.multiline_text((x,y), num, fill=(0,0,0,255) , align = "center")

    out = Image.alpha_composite(base, txt)

    out.save('ic_vis_tiles/ic_tile_{0:03d}.png'.format(id))

def mem_grid_create():
    background = Image.open('trans_1920x1920.png').convert('RGBA')
    bg = background.copy()

    for i in range(900):
        to_be_pasted = Image.open('ic_vis_tiles/ic_tile_{0:03d}.png'.format(i))
        bg.paste(to_be_pasted,((i%30) * 64,(i//30) * 64))

    bg.save('ic_all_tiles.png')

def mem_grid_update(id):
    
    if id == 900:
        return
    
    ic_mem_grid = Image.open('ic_all_tiles.png').convert('RGBA')
    bg = ic_mem_grid.copy()

    to_be_pasted = Image.open('ic_vis_tiles/ic_tile_{0:03d}.png'.format(id))
    bg.paste(to_be_pasted,((id%30) * 64,(id//30) * 64))

    bg.save('ic_all_tiles.png')

def mem_grid_bg(instr_line):
    number_overlay = Image.open('ic_all_tiles.png').convert('RGBA')
    background = Image.open('white_1920x1920.png').convert('RGBA')
    green_bg = Image.open('green_64x64.png').convert('RGBA')
    yellow_bg = Image.open('yellow_64x64.png').convert('RGBA')
    sky_blue_bg = Image.open('sky_blue_64x64.png').convert('RGBA')
    bg = background.copy()

    #for i in range(0):
    instrs = instr_line.split(',')
    pt = int(instrs[1])
    instr = instrs[2].split(' ')
    if len(instrs) == 4:
        update_instr = instrs[3].split(' ')
        update_pt = get_tile_id(int(update_instr[0]))
    
    bg.paste(green_bg,((pt%30) * 64,(pt//30) * 64))

    for j in range(len(instr) - 1):
        bg.paste(yellow_bg,(((pt + 1 + j)%30) * 64,((pt + 1 + j)//30) * 64))
    
    if len(instrs) == 4:
        bg.paste(sky_blue_bg,((update_pt%30) * 64,(update_pt//30) * 64))

    bg = Image.alpha_composite(bg, number_overlay)

    bg.save('ic_frame.png')

def add_caption(instr_line):
    # get an image
    base = Image.open('ic_frame.png').convert('RGBA')

    width, height = base.size
    
    # make a blank image for the text, initialized to transparent text color
    txt = Image.new('RGBA', base.size, (255,255,255,0))

    # get a drawing context
    d = ImageDraw.Draw(txt)

    op_num = 'Operation Number: #{}'.format(instr_line.split(',')[0])
    textwidth, textheight = d.textsize(op_num)

    x = (960 - textwidth) / 2 
    y = (64 - textheight) / 2 + 1856

    d.multiline_text((x,y), op_num, fill=(0,0,0,255) , align = "center")

    instr = 'Instruction: {}'.format(instr_line.split(',')[2])
    textwidth, textheight = d.textsize(instr)

    x = (960 - textwidth) / 2 + 960
    y = (64 - textheight) / 2 + 1856

    d.multiline_text((x,y), instr, fill=(0,0,0,255) , align = "center")

    out = Image.alpha_composite(base, txt)

    out.save('test_run/ic_frame_{0:07d}.png'.format(int(instr_line.split(',')[0])))
    print('test_run/ic_frame_{0:07d}.png CREATED'.format(int(instr_line.split(',')[0])))

input = input.split('\n\n')
intcode,extra = input[0].split('\n')
intcode = intcode.split(',')
extra = extra.split(',')

for i in range(900):
    if i < len(intcode):
        mem_cell_create(i,intcode[i])
    elif i < 840:
        mem_cell_create(i,'')
    elif i < 840+len(extra):
        mem_cell_create(i,extra[i-840])
    else:
        mem_cell_create(i,'')

mem_grid_create()

print('mem_grid_init done')

instructions = input[1].split('\n')
for instr in instructions:

    mem_grid_bg(instr)
    add_caption(instr)
    if len(instr.split(',')) == 4:
        update_instr = instr.split(',')[3].split(' ')
        mem_cell_create(get_tile_id(int(update_instr[0])),update_instr[1])
        mem_grid_update(get_tile_id(int(update_instr[0])))
        