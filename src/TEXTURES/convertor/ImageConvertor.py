import numpy as np
from PIL import Image

img = Image.open('Gun1.png')
img_rgba = img.convert('RGBA')

data = np.array(img_rgba)
flat_data = data.reshape(-1, 4)

hex_data = []
for r, g, b, a in flat_data:
    if a < 255:
        hex_data.append("0")
    else:
        hex_data.append(f"0x{r:02x}{g:02x}{b:02x}")

char_string = 'uint32_t textureName[] = {' + ','.join(hex_data) + '};'
print(char_string)
