#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>

// this will throw an error if you don't have the bitmap library installed
// so be sure to do that before uncommenting this #include line
#include "bitmap_image.hpp"

int get_mean(bitmap_image image) {
    int sum = 0;
    int pixel_count = 0;
    rgb_t this_pixel;
    for (int i = 0; i < image.height(); i++) {
        for (int j = 0; j < image.width(); j++) {
            image.get_pixel(i, j, this_pixel);
            sum += ((this_pixel.red + this_pixel.green + this_pixel.blue) / 3);
            pixel_count++;
        }
    }
    return (sum / pixel_count);
}

int main(int argc, char *argv[]) {
    // get a string containing the image name
    // this is necessary because the bitmap_image
    // class expects a string as an argument
    std::string file_name(argv[1]);
    bitmap_image input(file_name);
    input.convert_to_grayscale();

    int mean = get_mean(input);

    for (int i = 0; i < input.height(); i++) {
        for (int j = 0; j < input.width(); j++) {
            std::cout << input.height() << " " << input.width() << std::endl;
            std::cout << i << " " << j << std::endl;
            rgb_t this_pixel;
            input.get_pixel(j, i, this_pixel);
            if (((this_pixel.red + this_pixel.green + this_pixel.blue) / 3) < mean) {
                input.set_pixel(j, i, 0, 0, 0);
            }
            else {
                input.set_pixel(j, i, 255, 255, 255);
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

// WORKS?