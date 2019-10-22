#include <iostream>
#include <iomanip>

int loan_payment(double loan, double interest, double payment) {
    int month_counter = 0;
    while (loan > 0.004) {
        loan = (loan * (1 + interest));
        loan -= payment;
        month_counter++;
    }

    return month_counter;
}

int main () {
    double loan, interest, payment;
    std::cin >> loan >> interest >> payment;

    int months_to_pay = loan_payment(loan, interest, payment);

    std::cout << months_to_pay << std::endl;

    return 0;
}