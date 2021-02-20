from PIL import Image, ImageDraw, ImageFont

intcode = open('to_sim.txt').read().split(',')

for i in range(900):
    # get an image
    base = Image.open('trans_64x64.png').convert('RGBA')

    width, height = base.size
    
    # make a blank image for the text, initialized to transparent text color
    txt = Image.new('RGBA', base.size, (255,255,255,0))

    # get a drawing context
    d = ImageDraw.Draw(txt)

    if i < len(intcode):
        num = intcode[i]
    else:
        num = ''

    if len(num) > 8:
        half_len = len(num)//2
        num = num[:half_len] + '\n' + num[half_len:]

    textwidth, textheight = d.textsize(num)

    margin = 10
    x = (width - textwidth) / 2 
    y = (height - textheight) / 2

    d.multiline_text((x,y), num, fill=(0,0,0,255) , align = "center")

    out = Image.alpha_composite(base, txt)

    out.save('ic_vis_tiles/ic_tile_{0:03d}.png'.format(i))