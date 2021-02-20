from PIL import Image, ImageDraw, ImageFilter

number_overlay = Image.open('ic_all_tiles.png').convert('RGBA')
background = Image.open('white_1920x1920.png').convert('RGBA')
green_bg = Image.open('green_64x64.png').convert('RGBA')
yellow_bg = Image.open('yellow_64x64.png').convert('RGBA')
bg = background.copy()

#for i in range(0):
cur_line = "0,1101 0 338920348844032 5000"
pt,instr = cur_line.split(',')
instr = instr.split(' ')
pt = int(pt)
bg.paste(green_bg,((pt%30) * 64,(pt//30) * 64))

for j in range(len(instr) - 1):
    bg.paste(yellow_bg,(((pt + 1 + j)%30) * 64,((pt + 1 + j)//30) * 64))
    
bg = Image.alpha_composite(bg, number_overlay)

bg.save('ic_bg_frame.png')