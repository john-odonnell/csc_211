#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

// this will throw an error if you don't have the bitmap library installed
// so be sure to do that before uncommenting this #include line
#include "bitmap_image.hpp"

int main(int argc, char *argv[]) {
    // get a string containing the image name
    // this is necessary because the bitmap_image
    // class expects a string as an argument
    std::string file_name(argv[1]);
    bitmap_image input(file_name);
    input.convert_to_grayscale();

    unsigned int height = input.height();
    unsigned int width = input.width();

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            rgb_t this_col;
            input.get_pixel(j, i, this_col);

            if (((this_col.red + this_col.green + this_col.blue) / 3) > 127) {
                input.set_pixel(j, i, 255, 255, 255);
            }
            else {
                input.set_pixel(j, i, 0, 0, 0);
            }
        }
    }

    // TODO:
    // your implementation of problem #4 should be done in this
    // file. Feel free to create functions etc. if you feel that
    // it will help you.

    input.save_image(argv[2]);

    return 0;
}