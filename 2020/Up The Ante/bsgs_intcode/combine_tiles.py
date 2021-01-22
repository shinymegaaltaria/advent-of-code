from PIL import Image, ImageDraw, ImageFilter

background = Image.open('trans_1920x1920.png')
bg = background.copy()

for i in range(900):
    to_be_pasted = Image.open('ic_vis_tiles/ic_tile_{0:03d}.png'.format(i))
    bg.paste(to_be_pasted,((i%30) * 64,(i//30) * 64))

bg.save('ic_all_tiles.png')