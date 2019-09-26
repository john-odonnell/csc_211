#include <iostream>
#include <iomanip>

int digitsBeforeDecimal (double number) {
    int number_placeholder;
    if (number < 0) {
        number_placeholder = 0 - (int)number;
    }
    else {
        number_placeholder = (int)number;
    }

    int digits_before_dec = 0;
    while (number_placeholder > 0) {
        number_placeholder /= 10;
        digits_before_dec++;
    }

    return digits_before_dec + 4;
}

int main () {
    double input_temp, output_temp;
    double fraction_c_f = (double)9/5;
    double fraction_f_c = (double)5/9;
    char input_char, output_char;
    int precision_input, precision_output;

    std::cin >> input_temp >> input_char;

    if ((input_char == 'C') || (input_char == 'c')) {
        output_temp = ((input_temp * fraction_c_f) + 32);
        output_char = 'F';
    }
    else if ((input_char == 'F') || (input_char == 'f')) {
        output_temp = ((input_temp - 32) * fraction_f_c);
        output_char = 'C';
    }

    precision_input = digitsBeforeDecimal(input_temp);
    precision_output = digitsBeforeDecimal(output_temp);

    std::cout << std::setprecision(precision_input) << input_temp << " degree(s) " << char(toupper(input_char));
    std::cout << " is equal to ";
    std::cout << std::setprecision(precision_output) << output_temp << " degree(s) " << output_char;
    std::cout << std::endl;

    return 0;
}