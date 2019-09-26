#include <iostream>
#include <math.h>
#include <string>
#include <array>
using namespace std;

int main () {
    int sale_amount;
    double sales_tax;
    double tax_rate = 0.07;
    double after_tax;

    std::cout << "Input value of sale: " << std::ends;
    std::cin >> sale_amount;

    sales_tax = sale_amount * tax_rate;
    after_tax = sale_amount + sales_tax;

    std::cout << "After tax, the amount is " << after_tax;
    std::cout << "." << std::endl;

    return 0;
}