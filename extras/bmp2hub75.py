#!/usr/bin/env -S uv run --script
# /// script
# dependencies = ["Pillow"]
# ///

# ported from https://github.com/CamelCaseName/BMP2HUB75
# MIT License

import sys
import os

try:
    from PIL import Image
except ImportError:
    print("Error: The 'Pillow' library is required. Install it using 'pip install Pillow'.")
    sys.exit(1)

# Generated with wolframalpha "Table[round((1.01093222170971^x)-1), {x,0,255}]"
# The constant is the 255th root of 16
RGB8TO4LUT = [
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 
    0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 
    2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 
    3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 
    5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 
    7, 7, 7, 7, 7, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 8, 9, 9, 9, 9, 9, 9, 9, 9, 9, 10, 10, 10, 10, 10, 
    10, 10, 10, 11, 11, 11, 11, 11, 11, 11, 11, 12, 12, 12, 12, 12, 12, 12, 13, 13, 13, 13, 13, 13, 
    14, 14, 14, 14, 14, 14, 14, 15, 15, 15
]

MAX_COLOR_ITER = 4
MAX_COLOR_DEPTH = MAX_COLOR_ITER - 1

def die(message):
    print(message)
    sys.exit(1)

def rgb8_to_4(color_val):
    return RGB8TO4LUT[max(0, min(255, int(color_val)))]

def main():
    if len(sys.argv) <= 1:
        print("Prints the HUB75 buffer array for the given image.")
        print("Usage: python bmp2hub75.py <image_path>")
        return

    image_path = sys.argv[1]
    
    if not os.path.exists(image_path):
        die(f"Error: {image_path} does not exist!")

    try:
        # Pillow allows reading almost any image format (BMP, PNG, JPG, etc.)
        img = Image.open(image_path).convert("RGB")
    except Exception as e:
        die(f"Error: Failed to open image: {e}")

    width, height = img.size
    if height % 2 != 0:
        die("Error: Image height must be even for HUB75 multiplexing.")

    half_height = height // 2
    pixels = img.load()

    buffer_size = int(height * width * MAX_COLOR_ITER / 2)
    output = []
    output.append(f"const unsigned char buffer[{buffer_size}] PROGMEM = {{ ")

    pixels_set = 0

    for i in range(MAX_COLOR_ITER):
        output.append("\n")
        bit_pos = MAX_COLOR_DEPTH - i
        
        for y in range(half_height):
            line_data = []
            for x in range(width):
                # HUB75 typically drives two rows at once (y and y + half_height)
                # Upper half pixel (Physical top half)
                r_u, g_u, b_u = pixels[x, y]
                # Lower half pixel (Physical bottom half)
                r_l, g_l, b_l = pixels[x, y + half_height]

                # Convert to 4-bit and extract the current bit plane
                ru_bit = (rgb8_to_4(r_u) >> bit_pos) & 1
                gu_bit = (rgb8_to_4(g_u) >> bit_pos) & 1
                bu_bit = (rgb8_to_4(b_u) >> bit_pos) & 1

                rl_bit = (rgb8_to_4(r_l) >> bit_pos) & 1
                gl_bit = (rgb8_to_4(g_l) >> bit_pos) & 1
                bl_bit = (rgb8_to_4(b_l) >> bit_pos) & 1

                # Combine into HUB75 format: 
                # Bit 5: R Lower, 4: G Lower, 3: B Lower, 2: R Upper, 1: G Upper, 0: B Upper
                val = (bl_bit << 5) | (gl_bit << 4) | (rl_bit << 3) | (bu_bit << 2) | (gu_bit << 1) | ru_bit
                line_data.append(f"{val:>2}, ")
                pixels_set += 1
            
            output.append("".join(line_data))
            output.append("\n")

    # Clean up trailing comma and spaces for a clean C array
    final_str = "".join(output).rstrip(", \n")
    final_str += "\n\n};"

    print(f"// Read and converted {pixels_set // MAX_COLOR_ITER * 2} pixels at {width}x{height} and {MAX_COLOR_ITER} bits per channel")
    print(final_str)

if __name__ == "__main__":
    main()
