import numpy as np
from PIL import Image

img = Image.open('WALL.bmp')

img_rgb = img.convert('RGB')
data = np.array(img_rgb)
flat_data = data.reshape(-1, 3)
hex_data = [f"0x{r:02x}{g:02x}{b:02x}" for r, g, b in flat_data]
char_string = 'uint8_t char0[charLength] = {' + ','.join(hex_data) + '};'
print(char_string)