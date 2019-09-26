#include <iostream>
#include <iomanip>

int main () {
    double input_temp, output_temp;
    double fraction_c_f = (double)9/5;
    double fraction_f_c = (double)5/9;
    char input_char, output_char;

    std::cout << "~~Temperature Converter~~" << std::endl;
    std::cout << "Enter decimal temperature and Temperature Scale Character:" << std::endl;

    std::cin >> input_temp >> input_char;

    if ((input_char == 'C') || (input_char == 'c')) {
        output_temp = ((input_temp * fraction_c_f) + 32);
        output_char = 'F';
    }
    else if ((input_char == 'F') || (input_char == 'f')) {
        output_temp = ((input_temp - 32) * fraction_f_c);
        output_char = 'C';
    }

    std::cout << input_temp << " degree(s) " << input_char;
    std::cout << " is equal to ";
    std::cout << output_temp << " degree(s) " << output_char;
    std::cout << std::endl;

    return 0;
}