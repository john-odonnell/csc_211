#include <iostream>
#include <iomanip>

int digitsBeforeDecimal (double number) {
    int number_placeholder;
    if (number_placeholder < 0) {
        number_placeholder = 0 - (int)number;
    }
    else {
        number_placeholder = (int)number;
    }

    int digits_before_dec = 0;
    while (number_placeholder > 0){
        number_placeholder /= 10;
        digits_before_dec++;
    }

    return digits_before_dec + 4;
}

int main () {
    double a, b, c, average;

    std::cin >> a >> b >> c;

    average = ((a + b + c) / 3);

    int precision_a = digitsBeforeDecimal(a);
    int precision_b = digitsBeforeDecimal(b);
    int precision_c = digitsBeforeDecimal(c);
    int precision_avg = digitsBeforeDecimal(average);

    std::cout << "The average of " << std::setprecision(precision_a) << a << ", ";
    std::cout << std::setprecision(precision_b) << b << ", and ";
    std::cout << std::setprecision(precision_c) << c << " is ";
    std::cout << std::setprecision(precision_avg) << average << std::endl;

    return 0;
}
