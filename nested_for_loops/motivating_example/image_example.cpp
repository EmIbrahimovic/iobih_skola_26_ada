#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image.h"
#include "stb_image_write.h"

#include <iostream>
using namespace std;

int main() {
    int width, height, channels;
    unsigned char* image = stbi_load("image.png", &width, &height, &channels, 0);

    if (image == NULL) {
        cout << "Failed to load image.png" << endl;
        return 1;
    }

    cout << "Loaded image: " << width << "x" << height
         << " with " << channels << " channels" << endl;

    for (int row = 0; row < height; row++) {
        for (int col = 0; col < width; col++) {
            int pixel_index = (row * width + col) * channels;

            for (int c = 0; c < channels; c++) {
                if (c == 3) continue; // skip alpha channel if present

                int value = image[pixel_index + c];
                value = value * 2; // increase brightness by 10%
                if (value > 255) value = 255; // clamp to max

                image[pixel_index + c] = value;
            }
        }
    }

    stbi_write_png("image_bright.png", width, height, channels, image, width * channels);
    cout << "Saved to image_bright.png" << endl;

    stbi_image_free(image);
    return 0;
}
