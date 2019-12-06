#include <iostream>
#include <stdio.h>

int main(int argc, char *argv[]) {

    for (int i = 0; i <= argc; i++) {
        std::cout << argv[i] << std::endl;
    }

    FILE *out_file = fopen(argv[argc - 1], "w");
    for (int i = 1; i <= argc; i++) {
        FILE *in_file = fopen(argv[i], "r");
        if (in_file != NULL) {
            while (!feof(in_file)) {
                char c = fgetc(in_file);
                if (c != EOF) {
                    std::cout << c;
                }
            }
        }
        fclose(in_file);
    }
    fclose(out_file);
}